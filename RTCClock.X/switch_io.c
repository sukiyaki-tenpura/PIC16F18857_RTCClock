/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   switch_io.c
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on August 13, 2020, 3:45 PM
 */
#include <stdint.h>
#include <stdbool.h>

#include "mcc_generated_files/mcc.h"
#include "switch_io.h"



bool sw_detected = false;

switch_state_t switch_state = { 0,0,0,0, 0,0,0,0 };

uint16_t sw0_press_count = 0;   // raw count of timer interval
uint16_t sw1_press_count = 0;
uint16_t sw2_press_count = 0;
uint16_t sw3_press_count = 0;
bool sw0_pending_press = false;
bool sw1_pending_press = false;
bool sw2_pending_press = false;
bool sw3_pending_press = false;
bool sw0_ignore_press = false;
bool sw1_ignore_press = false;
bool sw2_ignore_press = false;
bool sw3_ignore_press = false;

#if 0
// insert interrupt_manager.c 
        else if(PIE2bits.TMR4IE == 1 && PIR2bits.TMR4IF == 1)
        {
            TMR4_ISR();
        } 
#endif

void sw_sensing(void);

static inline void stopTMR4(void)
{
    T4CONbits.TMR4ON = 0;
}
static inline void qickStartTMR4(void)
{
    // Start the Timer by writing to TMRxON bit
    T4CONbits.TMR4ON = 0;
    TMR4 = T4PR / 2;
    T4CONbits.TMR4ON = 1;
}
// IOC interrupt handler
void sw0_ioc_interrupt(void)
{
    qickStartTMR4();
}
void sw1_ioc_interrupt(void)
{
    qickStartTMR4();
}
void sw2_ioc_interrupt(void)
{
    qickStartTMR4();
}
void sw3_ioc_interrupt(void)
{
    qickStartTMR4();
}


void switch_io_initialize(void)
{
    switch_state.sw0_pressed = false;
    switch_state.sw1_pressed = false;
    switch_state.sw2_pressed = false;
    switch_state.sw3_pressed = false;
    switch_state.sw0_long_press_count = 0;
    switch_state.sw1_long_press_count = 0;
    switch_state.sw2_long_press_count = 0;
    switch_state.sw3_long_press_count = 0;

    sw0_press_count = 0;
    sw1_press_count = 0;
    sw2_press_count = 0;
    sw3_press_count = 0;
    sw0_pending_press = false;
    sw1_pending_press = false;
    sw2_pending_press = false;
    sw3_pending_press = false;

    sw_detected = false;

    T4CONbits.TMR4ON = 0;
}
void sw0_ignore_long_press(void) {
    sw0_ignore_press = true;
}
void sw1_ignore_long_press(void) {
    sw1_ignore_press = true;
}
void sw2_ignore_long_press(void) {
    sw2_ignore_press = true;
}
void sw3_ignore_long_press(void) {
    sw3_ignore_press = true;
}
void sw_sensing(void)
{
    bool sw0_now = PORTCbits.RC3;
    bool sw1_now = PORTCbits.RC2;
    bool sw2_now = PORTCbits.RC1;
    bool sw3_now = PORTCbits.RC0;
    uint16_t interval;

    if (sw0_now == PRESS) {
        if (sw0_press_count == 0) {
            sw0_pending_press = true;
        }
        sw0_press_count++;
        if (sw0_press_count >= LONG_PRESS_BEGIN) {
            interval = (sw0_press_count - LONG_PRESS_BEGIN) % LONG_PRESS_INTERVAL;
            if (interval == 0 && !sw0_ignore_press) {
                switch_state.sw0_long_press_count++;
                sw_detected = true;
            }
            sw0_pending_press = false;
        }
    } else {
        if (sw0_pending_press) {
            switch_state.sw0_pressed = true;
            sw_detected = true;
        }
        sw0_pending_press = false;
        sw0_press_count = 0;
        switch_state.sw0_long_press_count = 0;
        sw0_ignore_press = false;
    }

    if (sw1_now == PRESS) {
        if (sw1_press_count == 0) {
            sw1_pending_press = true;
        }
        sw1_press_count++;
        if (sw1_press_count >= LONG_PRESS_BEGIN) {
            interval = (sw1_press_count - LONG_PRESS_BEGIN) % LONG_PRESS_INTERVAL;
            if (interval == 0 && !sw1_ignore_press) {
                switch_state.sw1_long_press_count++;
                sw_detected = true;
            }
            sw1_pending_press = false;
        }
    } else {
        if (sw1_pending_press) {
            switch_state.sw1_pressed = true;
            sw_detected = true;
        }
        sw1_pending_press = false;
        sw1_press_count = 0;
        switch_state.sw1_long_press_count = 0;
        sw1_ignore_press = false;
    }

    if (sw2_now == PRESS) {
        if (sw2_press_count == 0) {
            sw2_pending_press = true;
        }
        sw2_press_count++;
        if (sw2_press_count >= LONG_PRESS_BEGIN) {
            interval = (sw2_press_count - LONG_PRESS_BEGIN) % LONG_PRESS_INTERVAL;
            if (interval == 0 && !sw2_ignore_press) {
                switch_state.sw2_long_press_count++;
                sw_detected = true;
            }
            sw2_pending_press = false;
        }
    } else {
        if (sw2_pending_press) {
            switch_state.sw2_pressed = true;
            sw_detected = true;
        }
        sw2_pending_press = false;
        sw2_press_count = 0;
        switch_state.sw2_long_press_count = 0;
        sw2_ignore_press = false;
    }

    if (sw3_now == PRESS) {
        if (sw3_press_count == 0) {
            sw3_pending_press = true;
        }
        sw3_press_count++;
        if (sw3_press_count >= LONG_PRESS_BEGIN) {
            interval = (sw3_press_count - LONG_PRESS_BEGIN) % LONG_PRESS_INTERVAL;
            if (interval == 0 && !sw3_ignore_press) {
                switch_state.sw3_long_press_count++;
                sw_detected = true;
            }
            sw3_pending_press = false;
        }
    } else {
        if (sw3_pending_press) {
            switch_state.sw3_pressed = true;
            sw_detected = true;
        }
        sw3_pending_press = false;
        sw3_press_count = 0;
        switch_state.sw3_long_press_count = 0;
        sw3_ignore_press = false;
    }

    if (sw0_now == RELEASE && sw1_now == RELEASE && sw2_now == RELEASE && sw3_now == RELEASE) {
        stopTMR4();
    }
}
bool is_sw_detected(void) {
    return sw_detected;
}
switch_state_t get_switches(void) {
    switch_state_t state = switch_state;

    switch_state.sw0_pressed = false;
    switch_state.sw1_pressed = false;
    switch_state.sw2_pressed = false;
    switch_state.sw3_pressed = false;
    switch_state.sw0_long_press_count = 0;
    switch_state.sw1_long_press_count = 0;
    switch_state.sw2_long_press_count = 0;
    switch_state.sw3_long_press_count = 0;
    sw_detected = false;
    return state;
}
