/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   utility.h
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on October 1, 2020, 10:48 PM
 */

#ifndef UTILITY_H
#define	UTILITY_H

#include <stdint.h>
#include <stdbool.h>

typedef union {
   struct {
    uint8_t bin_8bit;
    uint8_t bcd_8bit;
   };
   struct {
    unsigned bin_low:4;
    unsigned bin_high:4;
    unsigned bcd_low:4;
    unsigned bcd_high:4;
   };
   struct {
      uint16_t bcd_conv16;
   };
} BCD_CONV_t;

uint8_t bin_to_bcd(int8_t bin_num);
int8_t  bcd_to_bin(uint8_t bcd_data);

#endif	/* UTILITY_H */

