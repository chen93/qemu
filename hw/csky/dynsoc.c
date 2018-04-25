/*
 * CSKY modules loader.
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

#include "qemu/osdep.h"
#include "qemu/help_option.h"
#include "hw/csky/dynsoc.h"
#include "qemu/module.h"
#include "qemu/error-report.h"

struct dynsoc_board_info *dynsoc_b_info;

#ifdef _WIN32
#include <windows.h>

#define CSKYSIM_KEY     ("0x2333")

static struct dynsoc_board_info *create_shm(void)
{
    HANDLE shmid;
    char *ret;
    struct dynsoc_board_info *shm;

    shmid = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0,
                              sizeof(struct dynsoc_board_info), CSKYSIM_KEY);

    if (shmid == NULL) {
        printf("CreateFileMapping failed\n");
        return (void *)-1;
    }

    ret = (char *)MapViewOfFile(shmid, FILE_MAP_ALL_ACCESS, 0, 0,
                                sizeof(struct dynsoc_board_info));

    if (ret == NULL) {
        printf("MapViewOfFile failed\n");
        return (void *)-1;
    }

    shm = (struct dynsoc_board_info *)ret;
    return shm;
}

#else
#include <sys/ipc.h>
#include <sys/shm.h>

#define CSKYSIM_KEY     ((key_t)0x2333)
static struct dynsoc_board_info *create_shm(void)
{
    int shmid;
    struct dynsoc_board_info *shm;
    shmid = shmget(CSKYSIM_KEY, sizeof(struct dynsoc_board_info),
                   0666 | IPC_CREAT);

    if (shmid == -1) {
        error_report("shmget failed");
        return (void *)-1;
    }

    shm = shmat(shmid, (void *)0, 0);
    if ((void *)shm == (void *)-1) {
        error_report("shmat failed");
        return (void *)-1;
    }

    return shm;
}

#endif

void dynsoc_load_modules(void)
{
    struct dynsoc_board_info *b_info;
    int i;

    b_info = create_shm();
    dynsoc_b_info = b_info;

    if (b_info == (struct dynsoc_board_info *)-1) {
        error_report("create shm failed");
        goto dynsoc_fail;
    }

    if (b_info->read_enable != 1) {
        error_report("sync fail");
        goto dynsoc_fail;
    }

    module_load_one("hw-csky-", b_info->name);

    for (i = 0; i < 10; i++) {
        if (b_info->dev[i].name != NULL) {
            module_load_one("", b_info->dev[i].filename);
        }
    }

    return;
dynsoc_fail:
    assert(0);
}
