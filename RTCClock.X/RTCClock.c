/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   datetime.c
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on October 1, 2020, 8:04 PM
 */

#include "mcc_generated_files/mcc.h"
#include "switch_io.h"
#include "datetime.h"
#include "RTC_DS3234.h"
#include "led_display.h"

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    init_led_display();

    switch_io_initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    RTC_init();
    init_date_time();
    set_display_mode(DISPLAY_HOURS);

 
    while (1) {
        if (rtc_get_datetime_momentarily) {
            INTERRUPT_GlobalInterruptDisable();
            INTERRUPT_PeripheralInterruptDisable();
            RTC_get_datetime();
            rtc_get_datetime_momentarily = false;
            INTERRUPT_GlobalInterruptEnable();
            INTERRUPT_PeripheralInterruptEnable();
            if (!timer_mode) {
                update_day();
            }
        }
        if (display_normalyze) {
            unset_display_normalyze();
            if (setup_mode) {
                exit_setup_mode();
            } else if (timer_mode) {
                exit_timer_mode();
            } else {
                set_display_mode(DISPLAY_HOURS);
            }
        }
        if (is_sw_detected()) {
            switch_state_t sw_now = get_switches();
            if (normal_mode) {
                if (sw_now.sw0_long_press_count > 0) {
                    RTC_get_datetime();
                    update_day();
                }
                if (sw_now.sw3_pressed) {
                    increment_display_mode();
                }
                if (sw_now.sw3_long_press_count > 0) {
                    sw3_ignore_long_press();
                    enter_setup_mode();
                }
                if (sw_now.sw0_pressed) {
                    enter_timer_mode();
                }
            } else if (setup_mode) {
                if (sw_now.sw0_long_press_count > 0) {
                    sw0_ignore_long_press();
                    RTC_set_initial_datetime();
                    set_display_mode(DISPLAY_HOURS);
                }
                if (sw_now.sw3_pressed) {
                    change_setup_element();
                }
                if (sw_now.sw3_long_press_count > 0) {
                    sw3_ignore_long_press();
                    exit_setup_mode();
                } else if (sw_now.sw0_pressed) {
                    setup_reset_value();
                }
                if (sw_now.sw1_long_press_count > 0 || sw_now.sw1_pressed) {
                    setup_value_up();
                }
                if (sw_now.sw2_long_press_count > 0 || sw_now.sw2_pressed) {
                    setup_value_down();
                }
            } else if (timer_mode) {
                if (sw_now.sw0_pressed) {
                    action_timer_start_key();
                } else
                if (sw_now.sw1_long_press_count > 0 || sw_now.sw1_pressed) {
                    increase_timer_time();
                } else
                if (sw_now.sw2_long_press_count > 0 || sw_now.sw2_pressed) {
                    decrease_timer_time();
                } else
                if (sw_now.sw3_pressed) {
                    exit_timer_mode();
                }
            }
        }        
    }
}
/**
 End of File
*/