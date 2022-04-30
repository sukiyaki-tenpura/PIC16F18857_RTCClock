/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   utility.c
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on October 1, 2020, 10:48 PM
 */

#include "utility.h"


uint8_t bin_to_bcd(int8_t bin_num) {
    BCD_CONV_t bcd_data;
    uint8_t bcd8bit;
    bcd_data.bcd_conv16 = (uint16_t)bin_num;

    for (int8_t i=0; i<8; i++) {
        if (bcd_data.bcd_high >= 5) {
            bcd_data.bcd_8bit += 0x30;
        }
        if (bcd_data.bcd_low >= 5) {
            bcd_data.bcd_8bit += 0x03;
        }
        bcd_data.bcd_conv16 <<= 1;
    }
    bcd8bit = bcd_data.bcd_high;
    bcd8bit = (uint8_t)(bcd8bit << 4) | (uint8_t)bcd_data.bcd_low;
    return bcd8bit;
}

int8_t bcd_to_bin(uint8_t bcd_data) {
    int8_t result;
    result = ((bcd_data >> 4) * 10) + (bcd_data & 0x0F);
    
    return result;
}