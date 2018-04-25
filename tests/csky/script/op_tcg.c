#include "inst_dspv2.h"

uint64_t DSPV2_HELPER(muls_u32)(uint32_t z, uint32_t z1,
                                uint32_t x, uint32_t y)
{
    /* Rz[31:0] = {Rz[31:0],Rz+1[31:0]}
     * - {Rx[31:0] X Ry[31:0]}[63:32] ) */
    uint64_t res, xy;
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    xy = (uint64_t)x * (uint64_t)y;
    res = z_long - xy;
    return res;
}
uint64_t DSPV2_HELPER(muls_s32)(uint32_t z, uint32_t z1,
                                uint32_t x, uint32_t y)
{
    /* Rz[31:0] = {Rz[31:0],Rz+1[31:0]}
     * - {Rx[31:0] X Ry[31:0]}[63:32] ) */
    uint64_t res, xy;
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    xy = (int64_t)(int32_t)x * (int64_t)(int32_t)y;
    res = z_long - xy;
    return res;
}

uint32_t DSPV2_HELPER(mulxl_s32)(uint32_t x, uint32_t y)
{
    /* Rz[31:0] = {Rz[31:0],Rz+1[31:0]}
     * - {Rx[31:0] X Ry[31:0]}[63:32] ) */
    int16_t tmp_y = y & 0xffff;
    uint64_t res = ((int64_t)(int32_t)x * (int64_t)tmp_y) >> 16;
    return res;
}
uint32_t DSPV2_HELPER(mulxl_s32_r)(uint32_t x, uint32_t y)
{
    /* Rz[31:0] = {Rz[31:0],Rz+1[31:0]}
     * - {Rx[31:0] X Ry[31:0]}[63:32] ) */
    int16_t tmp_y = y & 0xffff;
    uint64_t res = ((int64_t)(int32_t)x * (int64_t)tmp_y + 0x8000) >> 16;
    return res;
}
uint32_t DSPV2_HELPER(mulxh_s32)(uint32_t x, uint32_t y)
{
    /* Rz[31:0] = {Rz[31:0],Rz+1[31:0]}
     * - {Rx[31:0] X Ry[31:0]}[63:32] ) */
    int16_t tmp_y = y >> 16;
    uint64_t res = ((int64_t)(int32_t)x * (int64_t)tmp_y) >> 16;
    return res;
}
uint32_t DSPV2_HELPER(mulxh_s32_r)(uint32_t x, uint32_t y)
{
    /* Rz[31:0] = {Rz[31:0],Rz+1[31:0]}
     * - {Rx[31:0] X Ry[31:0]}[63:32] ) */
    int16_t tmp_y = y >> 16;
    uint64_t res = ((int64_t)(int32_t)x * (int64_t)tmp_y + 0x8000) >> 16;
    return res;
}

uint64_t DSPV2_HELPER(pmul_s16)(uint32_t x, uint32_t y)
{
    int16_t tmp_x = x & 0xffff;
    int16_t tmp_y = y & 0xffff;
    uint64_t res = (uint64_t)((int32_t)tmp_x * (int32_t)tmp_y) & 0xffffffff;
    tmp_x = x >> 16;
    tmp_y = y >> 16;
    res |= (int64_t)((int32_t)tmp_x * (int32_t)tmp_y) << 32;
    return res;
}

uint64_t DSPV2_HELPER(pmul_u16)(uint32_t x, uint32_t y)
{
    uint16_t tmp_x = x & 0xffff;
    uint16_t tmp_y = y & 0xffff;
    uint64_t res = (uint64_t)((uint32_t)tmp_x * (uint32_t)tmp_y) & 0xffffffff;
    tmp_x = x >> 16;
    tmp_y = y >> 16;
    res |= (uint64_t)((uint32_t)tmp_x * (uint32_t)tmp_y) << 32;
    return res;
}

uint64_t DSPV2_HELPER(pmulx_s16)(uint32_t x, uint32_t y)
{
    int16_t tmp_x = x & 0xffff;
    int16_t tmp_y = y >> 16;
    uint64_t res = (uint64_t)((int32_t)tmp_x * (int32_t)tmp_y) & 0xffffffff;
    tmp_x = x >> 16;
    tmp_y = y & 0xffff;
    res |= (int64_t)((int32_t)tmp_x * (int32_t)tmp_y) << 32;
    return res;
}

uint64_t DSPV2_HELPER(pmulx_u16)(uint32_t x, uint32_t y)
{
    uint16_t tmp_x = x & 0xffff;
    uint16_t tmp_y = y >> 16;
    uint64_t res = (uint64_t)((uint32_t)tmp_x * (uint32_t)tmp_y) & 0xffffffff;
    tmp_x = x >> 16;
    tmp_y = y & 0xffff;
    res |= (uint64_t)((uint32_t)tmp_x * (uint32_t)tmp_y) << 32;
    return res;
}

uint32_t DSPV2_HELPER(mulcs_s16)(uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = (int32_t)tmp_x * (int32_t)tmp_y
        - ((int32_t)x >> 16) * ((int32_t)y >> 16);
    return res;
}

uint32_t DSPV2_HELPER(mulcsr_s16)(uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = ((int32_t)x >> 16) * ((int32_t)y >> 16)
        - (int32_t)tmp_x * (int32_t)tmp_y;
    return res;
}

uint32_t DSPV2_HELPER(mulcsx_s16)(uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    int32_t res;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = (int32_t)tmp_x * ((int32_t)y >> 16)
        - ((int32_t)x >> 16) * ((int32_t)tmp_y);
    return res;
}

uint64_t DSPV2_HELPER(mulaca_s16_e)(uint32_t z, u_int32_t z1,
                                    uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    uint64_t res;
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = ((int64_t)(int32_t)x >> 16) * ((int64_t)(int32_t)y >> 16)
        + (int64_t)(int32_t)tmp_x * (int64_t)(int32_t)tmp_y;
    return res + z_long;
}

uint64_t DSPV2_HELPER(mulacax_s16_e)(uint32_t z, u_int32_t z1,
                                    uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    uint64_t res;
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = ((int64_t)(int32_t)x >> 16) * (int64_t)(int32_t)tmp_y
        + (int64_t)(int32_t)tmp_x * ((int64_t)(int32_t)y >> 16);
    return res + z_long;
}

uint64_t DSPV2_HELPER(mulacs_s16_e)(uint32_t z, u_int32_t z1,
                                    uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    uint64_t res;
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = (int64_t)(int32_t)tmp_x * (int64_t)(int32_t)tmp_y
        - ((int64_t)(int32_t)x >> 16) * ((int64_t)(int32_t)y >> 16);
    return res + z_long;
}

uint64_t DSPV2_HELPER(mulacsr_s16_e)(uint32_t z, u_int32_t z1,
                                    uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    uint64_t res;
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = ((int64_t)(int32_t)x >> 16) * ((int64_t)(int32_t)y >> 16)
        - (int64_t)(int32_t)tmp_x * (int64_t)(int32_t)tmp_y;
    return res + z_long;
}

uint64_t DSPV2_HELPER(mulacsx_s16_e)(uint32_t z, u_int32_t z1,
                                    uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    uint64_t res;
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = (int64_t)(int32_t)tmp_x * ((int64_t)(int32_t)y >> 16)
        -((int64_t)(int32_t)x >> 16) * (int64_t)(int32_t)tmp_y;
    return res + z_long;
}

uint64_t DSPV2_HELPER(mulsca_s16_e)(uint32_t z, u_int32_t z1,
                                    uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    uint64_t res;
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = ((int64_t)(int32_t)x >> 16) * ((int64_t)(int32_t)y >> 16)
        + (int64_t)(int32_t)tmp_x * (int64_t)(int32_t)tmp_y;
    return z_long - res;
}

uint64_t DSPV2_HELPER(mulscax_s16_e)(uint32_t z, u_int32_t z1,
                                    uint32_t x, uint32_t y)
{
    int16_t tmp_x;
    int16_t tmp_y;
    uint64_t res;
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    tmp_x = x & 0xffff;
    tmp_y = y & 0xffff;
    res = ((int64_t)(int32_t)x >> 16) * (int64_t)(int32_t)tmp_y
        + (int64_t)(int32_t)tmp_x * ((int64_t)(int32_t)y >> 16);
    return z_long - res;
}

uint64_t DSPV2_HELPER(mul_u32)(uint32_t x, u_int32_t y)
{
    return (uint64_t)x * (u_int64_t)y;
}

uint64_t DSPV2_HELPER(mul_s32)(uint32_t x, u_int32_t y)
{
    return (uint64_t)(int32_t)x * (u_int64_t)(int32_t)y;
}

uint64_t DSPV2_HELPER(mula_u32)(uint32_t z, u_int32_t z1,
                                uint32_t x, u_int32_t y)
{
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    return z_long + (uint64_t)x * (u_int64_t)y;
}

uint64_t DSPV2_HELPER(mula_s32)(uint32_t z, u_int32_t z1,
                                uint32_t x, u_int32_t y)
{
    uint64_t z_long = ((uint64_t)z1 << 32) + z;
    return z_long + (uint64_t)(int32_t)x * (u_int64_t)(int32_t)y;
}

uint32_t DSPV2_HELPER(mul_s32_h)(uint32_t x, u_int32_t y)
{
    return ((uint64_t)(int32_t)x * (u_int64_t)(int32_t)y) >> 32;
}

uint32_t DSPV2_HELPER(mul_s32_rh)(uint32_t x, u_int32_t y)
{
    return ((uint64_t)(int32_t)x * (u_int64_t)(int32_t)y + 0x80000000) >> 32;
}

uint32_t DSPV2_HELPER(mulll_s16)(uint32_t x, uint32_t y)
{
    int16_t tmp_x = x & 0xffff;
    int16_t tmp_y = y & 0xffff;
    return ((int32_t)tmp_x * (int32_t)tmp_y);
}

uint32_t DSPV2_HELPER(mulhh_s16)(uint32_t x, uint32_t y)
{
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y >> 16;
    return ((int32_t)tmp_x * (int32_t)tmp_y);
}

uint32_t DSPV2_HELPER(mulhl_s16)(uint32_t x, uint32_t y)
{
    int16_t tmp_x = x >> 16;
    int16_t tmp_y = y & 0xffff;
    return ((int32_t)tmp_x * (int32_t)tmp_y);
}

