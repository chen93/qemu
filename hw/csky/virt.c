#include "qemu/osdep.h"
#include "qapi/error.h"
#include "sysemu/sysemu.h"
#include "exec/address-spaces.h"
#include "net/net.h"
#include "sysemu/device_tree.h"

#include "target-csky/cpu.h"
#include "hw/sysbus.h"
#include "hw/boards.h"
#include "hw/csky/csky.h"
#include "hw/csky/cskydev.h"
#include "hw/char/csky_uart.h"

static struct csky_boot_info virt_binfo = {
        .loader_start   = 0,
        .dtb_addr       = 0x8f000000,
        .magic          = 0x20150401,
        .freq           = 50000000ll,
};

static bool get_ramsize_from_dtb(unsigned int *ram_size, unsigned int *base)
{
    void *fdt = NULL;
    int size;
    int lenp = 0;
    unsigned int *res;
    virt_binfo.dtb_filename = qemu_opt_get(qemu_get_machine_opts(), "dtb");
    if (virt_binfo.dtb_filename) {
        char *filename;
        filename = qemu_find_file(QEMU_FILE_TYPE_BIOS, virt_binfo.dtb_filename);
        if (!filename) {
            fprintf(stderr, "Couldn't open dtb file %s\n",
                    virt_binfo.dtb_filename);
            return false;
        }

        fdt = load_device_tree(filename, &size);
        if (!fdt) {
            fprintf(stderr, "Couldn't open dtb file %s\n", filename);
            g_free(filename);
            return false;
        }
        g_free(filename);
    } else {
        fprintf(stderr, "Board was unable to create a dtb blob\n");
        return false;
    }

    qemu_fdt_dumpdtb(fdt, size);

    /* get reg<base size> to point "res" */
    res = (unsigned int *)
        qemu_fdt_getprop(fdt, "/memory", "reg", &lenp, &error_fatal);

    if (lenp == 8) {
        *base = __builtin_bswap32(*res);
        *ram_size = __builtin_bswap32(*(res + 1));
        return true;
    } else {
        return false;
    }
}

static void virt_init(MachineState *machine)
{
        ObjectClass     *cpu_oc;
        Object          *cpuobj;
        CSKYCPU         *cpu;

        DeviceState     *intc;
        unsigned int ram_size =0, base = 0;
        /*
         * Prepare RAM.
         */
        MemoryRegion *sysmem = get_system_memory();
        MemoryRegion *ram = g_new(MemoryRegion, 1);

        /* read ram base and size from dtb file. */
        if (!get_ramsize_from_dtb(&ram_size, &base)) {
            fprintf(stderr, "qemu: fail to read RAM base/size in dtb '%s'\n",
                    virt_binfo.dtb_filename);
            exit(1);
        }
        memory_region_allocate_system_memory(ram, NULL, "ram", ram_size);
        memory_region_add_subregion(sysmem, base, ram);

        /*
         * Prepare CPU
         */
#ifdef TARGET_CSKYV2
        machine->cpu_model = "ck810f";
#else
        machine->cpu_model = "ck610ef";
#endif

        cpu_oc = cpu_class_by_name(TYPE_CSKY_CPU, machine->cpu_model);
        if (!cpu_oc) {
                fprintf(stderr, "Unable to find CPU definition\n");
                exit(1);
        }

        cpuobj = object_new(object_class_get_name(cpu_oc));
        object_property_set_bool(cpuobj, true, "realized", &error_fatal);

        cpu = CSKY_CPU(cpuobj);

        /*
         * use C-SKY interrupt controller
         */
        intc = sysbus_create_simple(
                        "csky_intc",
                        0xfffff000,
                        *csky_intc_init_cpu(&cpu->env));

        /*
         * use dw-apb-timer
         */
        csky_timer_set_freq(virt_binfo.freq);
        sysbus_create_varargs(
                        "csky_timer",
                        0xffffd000,
                        qdev_get_gpio_in(intc, 1),
                        qdev_get_gpio_in(intc, 2),
                        NULL);

        /*
         * use 16650a uart.
         */
        csky_uart_create(
                        0xffffe000,
                        qdev_get_gpio_in(intc, 3),
                        serial_hds[0]);

        /*
         * for qemu exit, use cmd poweroff.
         */
        sysbus_create_simple("csky_exit", 0xffffc000, NULL);

        /*
         * add net, io-len is 2K.
         */
        csky_mac_v2_create(&nd_table[0], 0xffffa000, qdev_get_gpio_in(intc, 4));

        /*
         * boot up kernel with unaligned_access and mmu on.
         */
#ifdef TARGET_CSKYV2
        cpu->env.features |= UNALIGNED_ACCESS;
#endif
        cpu->env.mmu_default = 1;

        virt_binfo.kernel_filename = machine->kernel_filename;
        csky_load_kernel(cpu, &virt_binfo);
}

static void virt_class_init(ObjectClass *oc, void *data)
{
        MACHINE_CLASS(oc)->desc = "C-SKY QEMU virt machine";
        MACHINE_CLASS(oc)->init = virt_init;
}

static const TypeInfo virt_type = {
        .name           = MACHINE_TYPE_NAME("virt"),
        .parent         = TYPE_MACHINE,
        .class_init     = virt_class_init,
};

static void virt_machine_init(void)
{
        type_register_static(&virt_type);
}

type_init(virt_machine_init)

