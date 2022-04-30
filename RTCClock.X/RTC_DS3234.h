/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   RTC_DS3234.h
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on October 1, 2020, 8:04 PM
 */

#ifndef RTC_DS3234_H
#define	RTC_DS3234_H

#include <stdint.h>
#include <stdbool.h>


#define RTC_RX     PORTAbits.RA0
#define RTC_TX     LATAbits.LATA1
#define RTC_SCLK   LATAbits.LATA2
#define RTC_CS_    LATAbits.LATA3

#define RTC_R_SECONDS 0x00
#define RTC_T_SECONDS 0x80
#define RTC_R_MINUTES 0x01
#define RTC_T_MINUTES 0x81
#define RTC_R_HOURS   0x02
#define RTC_T_HOURS   0x82
#define RTC_R_WEEKDAY 0x03
#define RTC_T_WEEKDAY 0x83
#define RTC_R_DAY     0x04
#define RTC_T_DAY     0x84
#define RTC_R_MONTH   0x05
#define RTC_T_MONTH   0x85
#define RTC_R_YEAR    0x06
#define RTC_T_YEAR    0x86

#define RTC_R_A1_1    0x07
#define RTC_T_A1_1    0x87
#define RTC_R_A1_2    0x08
#define RTC_T_A1_2    0x88
#define RTC_R_A1_3    0x09
#define RTC_T_A1_3    0x89
#define RTC_R_A1_4    0x0A
#define RTC_T_A1_4    0x8A

#define RTC_R_A2_2    0x0B
#define RTC_T_A2_2    0x8B
#define RTC_R_A2_3    0x0C
#define RTC_T_A2_3    0x8C
#define RTC_R_A2_4    0x0D
#define RTC_T_A2_4    0x8D

void RTC_init(void);
int8_t RTC_get_seconds(void);
void RTC_set_seconds(int8_t sec);
int8_t RTC_get_minutes(void);
void RTC_set_minutes(int8_t min);
int8_t RTC_get_hours(void);
void RTC_set_hours(int8_t hor);
int8_t RTC_get_day(void);
void RTC_set_day(int8_t dy);
int8_t RTC_get_month(void);
void RTC_set_month(int8_t dy);
int16_t RTC_get_year(void);
void RTC_set_year(int16_t yr);
void RTC_set_initial_datetime(void);
void RTC_get_datetime(void);
#endif	/* RTC_DS3234_H */

