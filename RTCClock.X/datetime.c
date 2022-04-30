/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   datetime.c
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on October 1, 2020, 8:04 PM
 */

#include "mcc_generated_files/mcc.h"
#include "datetime.h"
#include "led_display.h"
#include "RTC_DS3234.h"
#include "nco_music.h"

bool rtc_get_datetime_momentarily = false;
bool normal_mode = true;
bool setup_mode = false;
SETUP_ELEMENT_t setup_element;

bool timer_mode = false;
TIMER_STATE_t timer_state;

DATETIME_t master_time = { 0, 59, 23, 11, 11, 1962 };

int16_t timer_seconds = 180;
int16_t current_timer_seconds = 180;

int16_t reset_year;
int8_t  reset_month;
int8_t  reset_day;

bool display_normalyze = false;
int16_t display_timeout_count = 0;

static const uint8_t ee_version = '1'; 

#define EE_ADD_VERSION  0xF002
#define EE_ADD_YEAR_HI  0xF010
#define EE_ADD_YEAR_LO  0xF011
#define EE_ADD_MONTH    0xF012
#define EE_ADD_DAY      0xF013
#define EE_ADD_HOURS    0xF014
#define EE_ADD_MINUTES  0xF015
#define EE_ADD_SECONDS  0xF016
#define EE_ADD_TIMER_HI 0xF017
#define EE_ADD_TIMER_LO 0xF018

//__EEPROM_DATA(0x00, 0x00, '1', 0x00, 0x00, 0x00, 0x00, 0x00);
//__EEPROM_DATA(0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);
//__EEPROM_DATA(0x07, 0xE4, 0x0A, 0x05, 0x15, 0x2D, 0x0F, 0x00);
//__EEPROM_DATA(0xB2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03);

void set_display_normalyze(void) {
    display_timeout_count = DISPLAY_TIMEOUT;
}
void set_setup_normalyze(void) {
    display_timeout_count = SETUP_TIMEOUT;
}
void unset_display_normalyze(void) {
    display_timeout_count = 0;
    display_normalyze = false;
}
void enter_timer_mode(void) {
    timer_state = TIMER_SETUP;
    normal_mode = false;
    timer_mode = true;
    set_blink_all(true);
    hold_colon();
    current_timer_seconds = timer_seconds;
    set_display_mode(DISPLAY_TIMER);
}
void exit_timer_mode(void) {
    sing_timeup(false);
    normal_mode = true;
    timer_mode = false;
    set_blink_all(false);
    set_display_mode(DISPLAY_HOURS);
}
static void set_timer_time(int8_t delta) {
    switch (timer_state) {
    case TIMER_RUN:
        timer_state = TIMER_PAUSE;
        sing_pause();
        set_blink_all(true);
        break;
    case TIMER_PAUSE:
        timer_state = TIMER_RUN;
        set_blink_all(false);
        sing_going();
        break;
    case TIMER_SETUP:
        timer_seconds += delta;
        if (timer_seconds <= 0) {
            timer_seconds = 10;
        }
        uint8_t ee_data_hi, ee_data_lo;
        ee_data_hi = (uint8_t)(timer_seconds >> 8);
        ee_data_lo = (uint8_t)(timer_seconds & 0xFF);
        DATAEE_WriteByte(EE_ADD_TIMER_HI, ee_data_hi);
        DATAEE_WriteByte(EE_ADD_TIMER_LO, ee_data_lo);
        current_timer_seconds = timer_seconds;
        update_timer();
        break;
    case TIMER_GOAL:
        timer_state = TIMER_OVERRUN;
        sing_timeup(false);
        set_blink_all(false);
        break;
    case TIMER_OVERRUN:
    case TIMER_FINISHED:
        exit_timer_mode();
        break;
    }
}
void increase_timer_time(void) {
    set_timer_time(10);
}
void decrease_timer_time(void) {
    set_timer_time(-10);
}
void action_timer_start_key(void) {
    switch (timer_state) {
    case TIMER_RUN:
        timer_state = TIMER_PAUSE;
        sing_pause();
        set_blink_all(true);
        break;
    case TIMER_PAUSE:
        set_blink_all(false);
        sing_going();
        timer_state = TIMER_RUN;
        break;
    case TIMER_SETUP:
        set_blink_all(false);
        current_timer_seconds = timer_seconds;
        sing_going();
        timer_state = TIMER_RUN;
        break;
    case TIMER_GOAL:
        timer_state = TIMER_OVERRUN;
        sing_timeup(false);
        set_blink_all(false);
        break;
    case TIMER_OVERRUN:
    case TIMER_FINISHED:
        exit_timer_mode();
        return;
    }
    update_timer();
}
static inline void resetTMR6(void) {
    T6CONbits.TMR6ON = 0;
    TMR6 = 0;
    T6CONbits.TMR6ON = 1;
}

uint8_t check_EE_version(void) {
    return DATAEE_ReadByte(EE_ADD_VERSION);
}
static void init_datetime_by_EE(void) {
    uint8_t ee_data_hi, ee_data_lo;
    
    ee_data_hi = DATAEE_ReadByte(EE_ADD_VERSION);
    if (ee_data_hi != ee_version) {
        return;
    }
    ee_data_hi = DATAEE_ReadByte(EE_ADD_YEAR_HI);
    ee_data_lo = DATAEE_ReadByte(EE_ADD_YEAR_LO);

    master_time.year = (int16_t)ee_data_hi;
    master_time.year <<= 8;
    master_time.year += (int16_t)ee_data_lo;
    reset_year = master_time.year;
    master_time.month = (int8_t)DATAEE_ReadByte(EE_ADD_MONTH);
    reset_month = master_time.month;
    master_time.day   = (int8_t)DATAEE_ReadByte(EE_ADD_DAY);
    reset_day = master_time.day;

    master_time.hours   = (int8_t)DATAEE_ReadByte(EE_ADD_HOURS);
    master_time.minutes = (int8_t)DATAEE_ReadByte(EE_ADD_MINUTES);
    master_time.seconds = (int8_t)DATAEE_ReadByte(EE_ADD_SECONDS);

    ee_data_hi = DATAEE_ReadByte(EE_ADD_TIMER_HI);
    ee_data_lo = DATAEE_ReadByte(EE_ADD_TIMER_LO);
   
    timer_seconds = (int16_t)ee_data_hi;
    timer_seconds <<= 8;
    timer_seconds += ee_data_lo;
    
}
void init_date_time(void) {
    normal_mode = true;
    setup_mode = false;
    timer_mode = false;
    RTC_get_datetime();
//    if (check_EE_version() != ee_version) {
//        init_datetime_by_EE();
//        RTC_set_initial_datetime();
//    }
    uint8_t ee_data_hi, ee_data_lo;
    ee_data_hi = DATAEE_ReadByte(EE_ADD_TIMER_HI);
    ee_data_lo = DATAEE_ReadByte(EE_ADD_TIMER_LO);
    timer_seconds = (int16_t)ee_data_hi;
    timer_seconds <<= 8;
    timer_seconds += ee_data_lo;
}
void setup_RTC(SETUP_ELEMENT_t element) {
    uint8_t ee_data_hi, ee_data_lo;

    DATAEE_WriteByte(EE_ADD_VERSION, ee_version);

    switch (element) {
    case SETUP_YEAR:
        RTC_set_year(master_time.year);
        ee_data_hi = (uint8_t)(master_time.year >> 8);
        ee_data_lo = (uint8_t)(master_time.year & 0xFF);
        DATAEE_WriteByte(EE_ADD_YEAR_HI, ee_data_hi);
        DATAEE_WriteByte(EE_ADD_YEAR_LO, ee_data_lo);
        break;
    case SETUP_MONTH:
        RTC_set_month(master_time.month);
        DATAEE_WriteByte(EE_ADD_MONTH, (uint8_t)master_time.month);
        break;
    case SETUP_DAY:
        RTC_set_day(master_time.day);
        DATAEE_WriteByte(EE_ADD_DAY, (uint8_t)master_time.day);
        break;
    case SETUP_HOURS:
        RTC_set_hours(master_time.hours);
        DATAEE_WriteByte(EE_ADD_HOURS, (uint8_t)master_time.hours);
        break;
    case SETUP_MINUTES_LOW:
    case SETUP_MINUTES_HIGH:
        RTC_set_seconds(master_time.seconds);
        RTC_set_minutes(master_time.minutes);
        DATAEE_WriteByte(EE_ADD_MINUTES, (uint8_t)master_time.minutes);
        DATAEE_WriteByte(EE_ADD_SECONDS, (uint8_t)master_time.seconds);
        break;
    case SETUP_SECONDS:
        RTC_set_seconds(master_time.seconds);
        DATAEE_WriteByte(EE_ADD_SECONDS, (uint8_t)master_time.seconds);
    case SETUP_TIMER:
        ee_data_hi = (uint8_t)(timer_seconds >> 8);
        ee_data_lo = (uint8_t)(timer_seconds & 0xFF);
        DATAEE_WriteByte(EE_ADD_TIMER_HI, ee_data_hi);
        DATAEE_WriteByte(EE_ADD_TIMER_LO, ee_data_lo);
        break;
    default:
        break;
    }
}
void enter_setup_mode(void) {
    normal_mode = false;
    setup_mode = true;

    reset_year = master_time.year;
    reset_month = master_time.month;
    reset_day = master_time.day;

    switch (display_mode) {
    case DISPLAY_HOURS:
        set_setup_element(SETUP_HOURS);
        break;
    case DISPLAY_SECONDS:
        set_setup_element(SETUP_MINUTES_HIGH);
        break;
    case DISPLAY_MONTH:
        set_setup_element(SETUP_MONTH);
        break;
    case DISPLAY_YEAR:
        set_setup_element(SETUP_YEAR);
        break;
    case DISPLAY_TIMER:
        set_setup_element(SETUP_TIMER);
        break;
    default:
        break;
    }
    set_setup_normalyze();
}
void exit_setup_mode(void) {
    setup_RTC(setup_element);
    normal_mode = true;
    setup_mode = false;
    set_blink_all(false);
    set_display_mode(DISPLAY_HOURS);
}
void change_setup_element(void) {
    if (!setup_mode) {
        return;
    }
    setup_RTC(setup_element);
    setup_element++;
    if (setup_element == SETUP_EXIT) {
        setup_element = SETUP_YEAR;
    }
    set_setup_element(setup_element);
}
void set_setup_element(SETUP_ELEMENT_t element) {
    setup_element = element;
    switch (setup_element) {
    case SETUP_YEAR:
        set_display_mode(DISPLAY_YEAR);
        set_blink_all(true);
        break;
    case SETUP_MONTH:
        set_display_mode(DISPLAY_MONTH);
        set_blink_high(true);
        break;
    case SETUP_DAY:
        set_display_mode(DISPLAY_MONTH);
        set_blink_low(true);
        break;
    case SETUP_HOURS:
        set_display_mode(DISPLAY_HOURS);
        set_blink_high(true);
        break;
    case SETUP_MINUTES_LOW:
        set_display_mode(DISPLAY_HOURS);
        set_blink_low(true);
        break;
    case SETUP_MINUTES_HIGH:
        set_display_mode(DISPLAY_SECONDS);
        set_blink_high(true);
        break;
    case SETUP_SECONDS:
        set_display_mode(DISPLAY_SECONDS);
        set_blink_low(true);
        break;
    case SETUP_TIMER:
        current_timer_seconds = timer_seconds;
        set_display_mode(DISPLAY_TIMER);
        set_blink_all(true);
        break;
    case SETUP_DIMADC:
        set_display_mode(DISPLAY_DIMADC);
        set_blink_all(true);
        break;
    default:
        break;
    }
    set_setup_normalyze();
}
void setup_reset_value(void) {
    switch (setup_element) {
    case SETUP_YEAR:
        master_time.year = reset_year;
        update_year();
        break;
    case SETUP_MONTH:
        master_time.month = reset_month;
        update_month();
        break;
    case SETUP_DAY:
        master_time.day = reset_day;
        update_month();
        break;
    case SETUP_HOURS:
        master_time.hours = 0;
        update_hours();
        break;
    case SETUP_MINUTES_HIGH:
    case SETUP_MINUTES_LOW:
        resetTMR6();
        master_time.seconds = 0;
        master_time.minutes = 0;
        update_minutes();
        break;
    case SETUP_SECONDS:
        resetTMR6();
        master_time.seconds = 0;
        update_seconds();
        break;
    case SETUP_TIMER:
        current_timer_seconds = timer_seconds = 180;
        update_timer();
        break;
    default:
        break;
    }
}

static const int8_t days_of_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                                        0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // with leap day
//                                          1   2   3   4   5   6   7   8   9  10  11  12
int8_t leap_year = 0;
static inline void validate_day_of_month(void) {
    if ((master_time.year % 100) != 0 && (master_time.year % 4) == 0) {
        leap_year = 13;
    } else {
        leap_year = 0;
    }
    if (master_time.day > days_of_month[master_time.month+leap_year]) {
        master_time.day = 1;
    }
    if (master_time.day < 1) {
        master_time.day = days_of_month[master_time.month+leap_year];
    }
}
static inline void increase_day_of_month(void) {
    if ((master_time.year % 100) != 0 && (master_time.year % 4) == 0) {
        leap_year = 13;
    } else {
        leap_year = 0;
    }
    master_time.day++;
    if (master_time.day > days_of_month[master_time.month+leap_year]) {
        master_time.month++;
        master_time.day = 1;
        if (master_time.month > 12) {
            master_time.year++;
            master_time.month = 1;
        }
    }
}
static void setup_value(int8_t value) {

    switch (setup_element) {
    case SETUP_YEAR:
        master_time.year += value;
        validate_day_of_month();
        update_year();
        break;
    case SETUP_MONTH:
        master_time.month += value;
        if (master_time.month > 12) {
            master_time.month = 1;
        }
        if (master_time.month < 1) {
            master_time.month = 12;
        }
        validate_day_of_month();
        update_month();
        break;
    case SETUP_DAY:
        master_time.day += value;
        validate_day_of_month();
        update_month();
        break;
    case SETUP_HOURS:
        master_time.hours += value;
        if (master_time.hours < 0) {
            master_time.hours = 23;
        }
        if (master_time.hours > 23) {
            master_time.hours = 0;
        }
        update_hours();
        break;
    case SETUP_MINUTES_LOW:
        master_time.minutes += value;
        if (master_time.minutes < 0) {
            master_time.minutes = 59;
        }
        if (master_time.minutes > 59) {
            master_time.minutes = 0;
        }
        update_minutes();
        break;
    case SETUP_MINUTES_HIGH:
        resetTMR6();
        master_time.seconds = 0;
        master_time.minutes += value;
        if (master_time.minutes < 0) {
            master_time.minutes = 59;
        }
        if (master_time.minutes > 59) {
            master_time.minutes = 0;
        }
        update_minutes();
        break;
    case SETUP_SECONDS:
        master_time.seconds += value;
        if (master_time.seconds < 0) {
            master_time.seconds = 59;
        }
        if (master_time.seconds > 59) {
            master_time.seconds = 0;
        }
        update_seconds();
        break;
    case SETUP_TIMER:
        timer_seconds += value;
        if (timer_seconds < 0) {
            timer_seconds = 180;
        }
        current_timer_seconds = timer_seconds;
        update_timer();
        break;
    case SETUP_DIMADC:
        dim_adc += (adc_result_t)value;
        update_dimadc();
        break;
    default:
        break;
    }
}
void setup_value_up(void) {
    setup_value(1);
}
void setup_value_down(void) {
    setup_value(-1);
}
void increase_second(void) {
    bool change_minutes = false;
    bool change_hours = false;
    bool change_day = false;
    bool change_timer = false;

    if (display_timeout_count > 0) {
        display_timeout_count--;
        if (display_timeout_count <= 0) {
            display_normalyze = true;
        }
    }

    if (timer_mode) {
        if (timer_state == TIMER_RUN || timer_state == TIMER_GOAL|| timer_state == TIMER_OVERRUN) {
            toggle_colon();
            current_timer_seconds--;
            if (current_timer_seconds == 0) {
                timer_state = TIMER_GOAL;
                sing_timeup(true);
                set_blink_all(true);
            }
            if (current_timer_seconds < TIMER_MAX_OVERRUN) {
                timer_state = TIMER_FINISHED;
                set_blink_all(false);
                sing_pause();
                set_setup_normalyze();
            }
            change_timer = true;
        }
    } else {
        toggle_colon();
    }
    master_time.seconds++;
    if (master_time.seconds > 59) {
        master_time.seconds = 0;
        change_minutes = true;
        master_time.minutes++;
        if (master_time.minutes > 59) {
            master_time.minutes = 0;
            change_hours = true;
            master_time.hours++;
            if (master_time.hours > 23) {
                master_time.hours = 0;
                change_day = true;
                increase_day_of_month();
            }
        }
    }
    if (change_day) {
        rtc_get_datetime_momentarily = true;
    }
    if (timer_mode) {
        if (change_timer) {
            update_timer();
        }
    } else if (change_hours) {
        update_hours();
    } else if (change_minutes) {
        update_minutes();
    } else {
        update_seconds();
    }
    dim_adc = ADCC_GetSingleConversion(DIM);
    update_dimadc();
}
void rtc_timer_interrupt(void) {
    rtc_get_datetime_momentarily = true;
}

