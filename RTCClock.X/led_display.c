/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   led_display.c
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on October 1, 2020, 10:48 PM
 */

#include "mcc_generated_files/mcc.h"
#include "led_display.h"
#include "datetime.h"
#include "utility.h"

DISPLAY_MODE_t display_mode = DISPLAY_HOURS;

int16_t bright_colon_count = 0;
adc_result_t dim_adc = 0;

uint16_t blink_count = 0;
bool blink_all_mode = false;
bool blink_low_mode = false;
bool blink_high_mode = false;
bool blank_all_now = false;
bool blank_low_now = false;
bool blank_high_now = false;

static uint8_t seven_segs[] = {
    // .GFEDCBA
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9
    0b01000000, // -
    0b01111001, // E
    0b01110110, // H
    0b00111000, // L
    0b01110011, // P
    0b00000000, // blank

//    (0b00111111 ^ 0xff), // 0
//    (0b00000110 ^ 0xff), // 1
//    (0b01011011 ^ 0xff), // 2
//    (0b01001111 ^ 0xff), // 3
//    (0b01100110 ^ 0xff), // 4
//    (0b01101101 ^ 0xff), // 5
//    (0b01111101 ^ 0xff), // 6
//    (0b00000111 ^ 0xff), // 7
//    (0b01111111 ^ 0xff), // 8
//    (0b01101111 ^ 0xff), // 9
//    (0b01000000 ^ 0xff), // -
//    (0b01111001 ^ 0xff), // E
//    (0b01110110 ^ 0xff), // H
//    (0b00111000 ^ 0xff), // L
//    (0b01110011 ^ 0xff), // P
//    (0b00000000 ^ 0xff), // blank
};


static inline BCD_CONV_t bcd_conv(int8_t bin_num) {
    BCD_CONV_t bcd_data;
    
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
    return bcd_data;
}

uint8_t current_position = 0;
uint8_t current_bcd_digit[] = { 0, 0, 0, 0 };   // digit 0, 1, 2, 3
uint8_t current_led_digit[] = { BLANK, BLANK, BLANK, BLANK };

bool zero_suppress = false;

static void update_digits(int8_t high, int8_t low);
static void blank_all(void);
static void show_all(void);
static void blank_low(void);
static void show_low(void);
static void blank_high(void);
static void show_high(void);


void init_led_display(void) {
    current_position = 0;
    current_bcd_digit[0] = 0;
    current_bcd_digit[1] = 0;
    current_bcd_digit[2] = 0;
    current_bcd_digit[3] = 0;
    current_led_digit[0] = 0;
    current_led_digit[1] = 0;
    current_led_digit[2] = 0;
    current_led_digit[3] = 0;
    LATCbits.LATC4 = INACTIVE;
    LATCbits.LATC5 = INACTIVE;
    LATCbits.LATC6 = INACTIVE;
    LATCbits.LATC7 = INACTIVE;
    LATB = BLANK;

    display_mode = DISPLAY_HOURS;
    blink_count = 0;
    blink_all_mode = false;
    blink_low_mode = false;
    blink_high_mode = false;
    blank_all_now = false;
    blank_low_now = false;
    blank_high_now = false;
    set_display_mode(display_mode);
}
void toggle_colon(void) {
    bright_colon_count = BRIGHT_COLON_COUNT;
}
void hold_colon(void) {
    bright_colon_count = -1;
}
void update_seconds(void) {
    if (display_mode == DISPLAY_SECONDS) {
        update_digits(master_time.minutes, master_time.seconds);
    }
}
void update_minutes(void) {
    if (display_mode == DISPLAY_SECONDS) {
        update_digits(master_time.minutes, master_time.seconds);
    } else if (display_mode == DISPLAY_HOURS) {
        update_digits(master_time.hours, master_time.minutes);
    }
}
void update_hours(void) {
    if (display_mode == DISPLAY_HOURS) {
        update_digits(master_time.hours, master_time.minutes);
        if (current_bcd_digit[3] == 0) {
             current_led_digit[3] = BLANK;
        }
    }
}
void update_month(void) {
    if (display_mode == DISPLAY_MONTH) {
        update_digits(master_time.month, master_time.day);
        if (current_bcd_digit[3] == 0) {
             current_led_digit[3] = BLANK;
        }
    }
}
void update_year(void) {
    if (display_mode == DISPLAY_YEAR) {
        update_digits((int8_t)(master_time.year/100), (int8_t)(master_time.year%100));
    }
}
void update_day(void) {
    update_seconds();
    update_hours();
    update_month();
    update_year();
}
void update_timer(void) {
    if (display_mode == DISPLAY_TIMER) {
        int16_t t_seconds;
        int8_t digit_minutes;
        int8_t digit_seconds;

        t_seconds = abs(current_timer_seconds);
        digit_minutes = (int8_t)(t_seconds / 60);
        digit_seconds = (int8_t)(t_seconds % 60);

        update_digits(digit_minutes, digit_seconds);
        if (current_timer_seconds < 0) {
            current_bcd_digit[3] = 0x0A;
            current_led_digit[3] = seven_segs[0x0A];
        }
    }
}
void update_dimadc(void) {
    if (display_mode == DISPLAY_DIMADC) {
        update_digits((int8_t)(dim_adc/100), (int8_t)(dim_adc%100));
    }
    uint16_t led_duty = (dim_adc / 3) + 230;
    if (led_duty > 800) {
        led_duty = 800;
    }
    CCPR3H = (uint8_t)(led_duty >> 8);
    CCPR3L = (uint8_t)(led_duty & 0xFF);
}
void set_display_mode(DISPLAY_MODE_t mode) {
    display_mode = mode;
    switch (mode) {
    case DISPLAY_HOURS:
        update_hours();
        zero_suppress = true;
        unset_display_normalyze();
        break;
    case DISPLAY_SECONDS:
        zero_suppress = false;
        update_seconds();
        set_display_normalyze();
        break;
    case DISPLAY_MONTH:
        zero_suppress = true;
        update_month();
        set_display_normalyze();
        break;
    case DISPLAY_YEAR:
        zero_suppress = false;
        update_year();
        set_display_normalyze();
        break;
    case DISPLAY_TIMER:
        zero_suppress = true;
        update_timer();
        unset_display_normalyze();
        break;
    case DISPLAY_DIMADC:
        zero_suppress = false;
        update_dimadc();
        unset_display_normalyze();
        break;
    }
}
void increment_display_mode(void) {
    DISPLAY_MODE_t mode = display_mode;
    mode++;
    if (mode == DISPLAY_TIMER) {
        mode = DISPLAY_HOURS;
    }
    set_display_mode(mode);
}
void set_blink_all(bool on) {
    blink_all_mode = on;
    blink_low_mode = blink_high_mode = false;
    if (blank_all_now || blank_low_now || blank_high_now) {
        show_all();
        blank_all_now = blank_low_now = blank_high_now = false;
    }
}
void set_blink_low(bool on) {
    blink_low_mode = on;
    blink_all_mode = blink_high_mode = false;
    if (blank_all_now || blank_low_now || blank_high_now) {
        show_all();
        blank_all_now = blank_low_now = blank_high_now = false;
    }
}
void set_blink_high(bool on) {
    blink_high_mode = on;
    blink_all_mode = blink_low_mode = false;
    if (blank_all_now || blank_low_now || blank_high_now) {
        show_all();
        blank_all_now = blank_low_now = blank_high_now = false;
    }
}


static void update_digits(int8_t high, int8_t low) {
    BCD_CONV_t bcd_data;
    bcd_data = bcd_conv(low);
    current_bcd_digit[0] = bcd_data.bcd_low;
    current_bcd_digit[1] = bcd_data.bcd_high;
    bcd_data = bcd_conv(high);
    current_bcd_digit[2] = bcd_data.bcd_low;
    current_bcd_digit[3] = bcd_data.bcd_high;
    show_all();
    if (blank_all_now) {
        blank_all();
    }
    if (blank_low_now) {
        blank_low();
    }
    if (blank_high_now) {
        blank_high();
    }
}
static void blank_all(void) {
    current_led_digit[0] = BLANK;
    current_led_digit[1] = BLANK;
    current_led_digit[2] = BLANK;
    current_led_digit[3] = BLANK;
}
static void show_all(void) {
    current_led_digit[0] = seven_segs[current_bcd_digit[0]];
    current_led_digit[1] = seven_segs[current_bcd_digit[1]];
    current_led_digit[2] = seven_segs[current_bcd_digit[2]];
    if (zero_suppress && current_bcd_digit[3] == 0) {
         current_led_digit[3] = BLANK;
    } else {
        current_led_digit[3] = seven_segs[current_bcd_digit[3]];
    }
}
static void blank_low(void) {
    current_led_digit[0] = BLANK;
    current_led_digit[1] = BLANK;
}
static void show_low(void) {
    current_led_digit[0] = seven_segs[current_bcd_digit[0]];
    current_led_digit[1] = seven_segs[current_bcd_digit[1]];
}
static void blank_high(void) {
    current_led_digit[2] = BLANK;
    current_led_digit[3] = BLANK;
}
static void show_high(void) {
    current_led_digit[2] = seven_segs[current_bcd_digit[2]];
    if (zero_suppress && current_bcd_digit[3] == 0) {
         current_led_digit[3] = BLANK;
    } else {
        current_led_digit[3] = seven_segs[current_bcd_digit[3]];
    }
}
// most inactive digit drive. call for CLC3 both edge interrupt 
static volatile uint8_t current_digit_segment;
void render_digit(void) {
    // falling edge for change digit
    if (CLC3CONbits.LC3OUT == 0) {
        LATB = 0;   // ghost blanking
        LATC = 0;
        current_position++;
        if (current_position >= DIGIT_MAX) {
            current_position = 0;
        }
        switch (current_position) {
        case 0:
//            LATCbits.LATC7 = 0;
            RC7PPS = 0;
            RC4PPS = 0x03;
            break;
        case 1:
//            LATCbits.LATC4 = 0;
            RC4PPS = 0;
            RC5PPS = 0x03;
            break;
        case 2:
//            LATCbits.LATC5 = 0;
            RC5PPS = 0;
            RC6PPS = 0x03;
            break;
        case 3:
//            LATCbits.LATC6 = 0;
            RC6PPS = 0;
            RC7PPS = 0x03;
            break;
        }
        blink_count++;
        if (blink_count >= BLINK_PRIOD) {
            blink_count = 0;
            if (blink_all_mode) {
                show_all();
                blank_all_now = false;
            }
            if (blink_high_mode) {
                show_high();
                blank_high_now = false;
            }
            if (blink_low_mode) {
                show_low();
                blank_low_now = false;
            }
        }
        if (blink_count == BLINK_BLANK) {
            if (blink_all_mode) {
                blank_all();
                blank_all_now = true;
            }
            if (blink_high_mode) {
                blank_high();
                blank_high_now = true;
            }
            if (blink_low_mode) {
                blank_low();
                blank_low_now = true;
            }
        }
        current_digit_segment = current_led_digit[current_position];
        if (bright_colon_count != 0) {
            current_digit_segment |= 0x80;
            if (bright_colon_count > 0) {
                bright_colon_count--;
            }
        }
    } else {
    // rising edge for set segment
        LATB = current_digit_segment;
    }
}