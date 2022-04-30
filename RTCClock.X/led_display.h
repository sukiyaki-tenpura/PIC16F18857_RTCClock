/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   led_display.h
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on October 1, 2020, 10:48 PM
 */

#ifndef LED_DISPLAY_H
#define	LED_DISPLAY_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    DISPLAY_HOURS,
    DISPLAY_SECONDS,
    DISPLAY_YEAR,
    DISPLAY_MONTH,
    DISPLAY_TIMER,
    DISPLAY_DIMADC,
} DISPLAY_MODE_t;

#define DIGIT_MAX   4
//digit cycle 256us * 2000 .5sec
#define BLINK_PRIOD 2000
#define BLINK_BLANK 1500
// open drain drive
#define ACTIVE      1
#define INACTIVE    0
#define BLANK   0x00

// Perdigit count 256us * n
#define BRIGHT_COLON_COUNT  1000

extern int16_t bright_colon_count;
extern adc_result_t dim_adc;

extern DISPLAY_MODE_t display_mode;

void init_led_display(void);
void update_seconds(void);
void update_minutes(void);
void update_hours(void);
void update_day(void);
void update_month(void);
void update_year(void);
void update_timer(void);
void update_dimadc(void);

void set_display_mode(DISPLAY_MODE_t mode);
void increment_display_mode(void);

void set_display_mode();
void set_blink_all(bool on);
void set_blink_high(bool on);
void set_blink_low(bool on);

void render_digit(void);
void toggle_colon(void);
void hold_colon(void);

#endif	/* LED_DISPLAY_H */
