/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   RTC_DS3234.c
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on October 1, 2020, 8:04 PM
 */

#include "mcc_generated_files/mcc.h"
#include "datetime.h"
#include "RTC_DS3234.h"
#include "utility.h"

// RA0 RX DATA
// RA1 TX DATA
// RA2 SCLK
// RA3 CS_
// RA4 LED COLON
// RA5 INT_
// RA6 N.C.
// RA7 32.768

void RTC_init(void) {
    RTC_CS_ = 1;
    RTC_SCLK = 1;
}

// Transfer with no wait if FOSC is 4MHz
static void write_register(uint8_t reg, uint8_t data) {
    uint8_t i;

    RTC_SCLK = 1;
    RTC_CS_ = 0;
    RTC_TX = 0;
    for (i=0; i<8; i++) {
        RTC_SCLK = 0;
        if(reg & 0x80) {
            RTC_TX = 1;
        }
        RTC_SCLK = 1;
        RTC_TX = 0;
        reg <<= 1;
    }
    for (i=0; i<8; i++) {
        RTC_SCLK = 0;
        if(data & 0x80) {
            RTC_TX = 1;
        }
        RTC_SCLK = 1;
        RTC_TX = 0;
        data <<= 1;
    }
    RTC_CS_ = 1;
}
static uint8_t read_register(uint8_t reg) {
    uint8_t data = 0;
    uint8_t i;

    RTC_SCLK = 1;
    RTC_CS_ = 0;
    RTC_TX = 0;
    for (i=0; i<8; i++) {
        RTC_SCLK = 0;
        if(reg & 0x80) {
            RTC_TX = 1;
        }
        RTC_SCLK = 1;
        RTC_TX = 0;
        reg <<= 1;
    }
    NOP();
    for (i=0; i<8; i++) {
        data <<= 1;
        RTC_SCLK = 0;
        NOP();
        RTC_SCLK = 1;
        NOP();
        data |= RTC_RX;
    }
    RTC_CS_ = 1;
    return data;
}

int8_t RTC_get_seconds(void) {
    uint8_t bcd_data;
    bcd_data = read_register(RTC_R_SECONDS);
    return bcd_to_bin(bcd_data);
}
void RTC_set_seconds(int8_t sec) {
    uint8_t bcd_data;
    bcd_data = bin_to_bcd(sec);
    write_register(RTC_T_SECONDS, bcd_data);
}
int8_t RTC_get_minutes(void) {
    uint8_t bcd_data;
    bcd_data = read_register(RTC_R_MINUTES);
    return bcd_to_bin(bcd_data);
}
void RTC_set_minutes(int8_t min) {
    uint8_t bcd_data;
    bcd_data = bin_to_bcd(min);
    write_register(RTC_T_MINUTES, bcd_data);
}
int8_t RTC_get_hours(void) {
    uint8_t bcd_data;
    bcd_data = read_register(RTC_R_HOURS);
    return bcd_to_bin(bcd_data);
}
void RTC_set_hours(int8_t hor) {
    uint8_t bcd_data;
    bcd_data = bin_to_bcd(hor);
    write_register(RTC_T_HOURS, bcd_data);
}
int8_t RTC_get_day(void) {
    uint8_t bcd_data;
    bcd_data = read_register(RTC_R_DAY);
    return bcd_to_bin(bcd_data);
}
void RTC_set_day(int8_t dy) {
    uint8_t bcd_data;
    bcd_data = bin_to_bcd(dy);
    write_register(RTC_T_DAY, bcd_data);
}
int8_t RTC_get_month(void) {
    uint8_t bcd_data;
    bcd_data = read_register(RTC_R_MONTH);
    bcd_data &= 0x3F;
    return bcd_to_bin(bcd_data);
}
void RTC_set_month(int8_t dy) {
    uint8_t bcd_data;
    bcd_data = bin_to_bcd(dy);
    write_register(RTC_T_MONTH, bcd_data);
}
int16_t RTC_get_year(void) {
    uint8_t bcd_data;
    int16_t year;

    bcd_data = read_register(RTC_R_YEAR);
    year = (int16_t)bcd_to_bin(bcd_data) + 2000;
    return year;
}
void RTC_set_year(int16_t yr) {
    uint8_t bcd_data;
    bcd_data = bin_to_bcd((int8_t)(yr - 2000));
    write_register(RTC_T_YEAR, bcd_data);
}
void RTC_days_timer(void) {
    write_register(RTC_T_A1_1, 0x00);
    write_register(RTC_T_A1_2, 0x00);
    write_register(RTC_T_A1_3, 0x00);
    write_register(RTC_T_A1_4, 0x80);
}

void RTC_set_initial_datetime(void) {
    RTC_set_year(master_time.year);
    RTC_set_month(master_time.month);
    RTC_set_day(master_time.day);
    RTC_set_hours(master_time.hours);
    RTC_set_minutes(master_time.minutes);
    RTC_set_seconds(master_time.seconds);
    RTC_days_timer();
}
void RTC_get_datetime(void) {
    master_time.year    = RTC_get_year();
    master_time.month   = RTC_get_month();
    master_time.day     = RTC_get_day();
    master_time.hours   = RTC_get_hours();
    master_time.minutes = RTC_get_minutes();
    master_time.seconds = RTC_get_seconds();
}