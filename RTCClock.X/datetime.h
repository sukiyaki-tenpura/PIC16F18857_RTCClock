/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   datetime.h
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on October 1, 2020, 8:04 PM
 */

#ifndef DATETIME_H
#define	DATETIME_H

#include <stdint.h>
#include <stdbool.h>

#define DISPLAY_TIMEOUT 120
#define SETUP_TIMEOUT 300
#define TIMER_MAX_OVERRUN (-600)


typedef enum {
    SETUP_YEAR,
    SETUP_MONTH,
    SETUP_DAY,
    SETUP_HOURS,
    SETUP_MINUTES_LOW,
    SETUP_MINUTES_HIGH,
    SETUP_SECONDS,
    SETUP_TIMER,
    SETUP_DIMADC,
    SETUP_EXIT,
} SETUP_ELEMENT_t;

typedef enum {
    TIMER_SETUP,
    TIMER_RUN,
    TIMER_PAUSE,
    TIMER_GOAL,
    TIMER_OVERRUN,
    TIMER_FINISHED,
} TIMER_STATE_t;

typedef struct {
    int8_t seconds;
    int8_t minutes;
    int8_t hours;
    int8_t  day;
//  int8_t  day_of_week;
    int8_t  month;
    int16_t year;
} DATETIME_t;

extern DATETIME_t master_time;

extern bool rtc_get_datetime_momentarily;

extern bool normal_mode;
extern bool setup_mode;
extern SETUP_ELEMENT_t setup_element;

extern bool timer_mode;
extern TIMER_STATE_t timer_state;

extern int16_t timer_seconds;
extern int16_t current_timer_seconds;

extern bool display_normalyze;


void set_display_normalyze(void);
void set_setup_normalyze(void);
void unset_display_normalyze(void);

void enter_timer_mode(void);
void exit_timer_mode(void);
void increase_timer_time(void);
void decrease_timer_time(void);
void action_timer_start_key(void);
void init_date_time(void);
void enter_setup_mode(void);
void exit_setup_mode(void);
void change_setup_element(void);
void set_setup_element(SETUP_ELEMENT_t element);
void setup_reset_value(void);
void setup_value_up(void);
void setup_value_down(void);

void increase_second(void);
void rtc_timer_interrupt(void);

#endif	/* DATETIME_H */
