/*
 * CSKY dynamic soc header.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DYNSOC_H
#define DYNSOC_H

#include <stdint.h>

#define DYNSOC_UART    (1 << 0)
#define DYNSOC_TIMER   (1 << 1)
#define DYNSOC_LCDC    (1 << 2)
#define DYNSOC_MAC     (1 << 3)
#define DYNSOC_EXIT    (1 << 4)
#define DYNSOC_MEMLOG  (1 << 5)
#define DYNSOC_DMA     (1 << 6)
#define DYNSOC_IIS     (1 << 7)
#define DYNSOC_NAND    (1 << 8)
#define DYNSOC_SDHC    (1 << 9)

struct dynsoc_cpu {
    char        cpu_name[32];
    char        abi[8];
    char        endian[8];
};

struct cpu_property {
    char        vdsp[8];
    char        pctrace[8];
    char        elrw[8];
    char        mem_prot[8];
    char        mmu_default[8];
};

struct dynsoc_device {
    int         type;
    char        name[32];
    char        filename[32];
    uint32_t    addr;
    int         irq;
};

struct dynsoc_memory {
    char        name[32];
    uint32_t    addr;
    uint32_t    size;
    uint32_t    writeable;
};

struct dynsoc_board_info {
    uint32_t                write_enable;
    uint32_t                read_enable;
    char                    name[32];
    struct dynsoc_cpu       cpu;
    /*
     * 0.uart
     * 1.timer
     * 2.lcdc
     * 3.mac
     * 4.exit
     * 5.memlog
     * 6.dma
     * 7.iis
     * 8.nand
     * 9.sdhc
     */
    struct dynsoc_device    dev[10];
    struct dynsoc_memory    mem[4];
    struct cpu_property     cpu_prop;
    char                    misc[1024];
    uint32_t                flags;
    int                     shmid;
};

void dynsoc_load_modules(void);
extern struct dynsoc_board_info *dynsoc_b_info;

#endif
