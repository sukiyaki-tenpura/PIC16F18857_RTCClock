/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   switch_io.h
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on August 13, 2020, 3:45 PM
 */
#ifndef SWITCH_IO_H
#define	SWITCH_IO_H

#include <stdint.h>
#include <stdbool.h>

#define RELEASE     true
#define PRESS       false
#define NONE        false
// long press time 20ms * 50 = 1000ms
#define LONG_PRESS_BEGIN    50
#define LONG_PRESS_INTERVAL 10

void switch_io_initialize(void);
void sw_sensing(void);
void sw0_ioc_interrupt(void);
void sw1_ioc_interrupt(void);
void sw2_ioc_interrupt(void);
void sw3_ioc_interrupt(void);


typedef struct {
    uint16_t sw0_long_press_count;  // long press starts after 1 second, increment every 200ms
    uint16_t sw1_long_press_count;
    uint16_t sw2_long_press_count;
    uint16_t sw3_long_press_count;
    unsigned sw0_pressed:1; // true as immediately press
    unsigned sw1_pressed:1;
    unsigned sw2_pressed:1;
    unsigned sw3_pressed:1;
} switch_state_t;

bool is_sw_detected(void);
switch_state_t get_switches(void);
void sw0_ignore_long_press(void);
void sw1_ignore_long_press(void);
void sw2_ignore_long_press(void);
void sw3_ignore_long_press(void);


#endif	/* SWITCH_IO_H */
