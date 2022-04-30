/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   nco_music.c
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on October 9, 2020, 6:48 PM
 */

#include "mcc_generated_files/mcc.h"
#include "nco_music.h"

uint16_t track_position = 0;
static const uint16_t timeup_track[] = {
    M_G6, M_G6, M_G6, M_SIN,
    M_E6, M_E6, M_E6, M_SIN,
    M_D6, M_D6, M_SIN,
    M_A6, M_A6, M_A6, M_SIN,
    M_G6, M_G6, M_G6, M_G6, M_SIN,

    M_A6, M_A6, M_SIN,
    M_B6, M_B6, M_SIN,
    M_C7, M_C7, M_C7, M_SIN,
    M_A6, M_SIN,
    M_E7, M_E7, M_SIN,
    M_E7, M_E7, M_SIN,
    M_D7, M_D7, M_D7, M_D7, M_SIN,

    M_SIN, M_SIN,

    M_D7, M_D7, M_D7, M_SIN,
    M_E7, M_E7, M_E7, M_SIN,
    M_D7, M_SIN,
    M_D7, M_D7, M_SIN,
    M_C7, M_SIN,
    M_A6, M_A6, M_A6, M_A6, M_SIN,

    M_A6, M_A6, M_SIN,
    M_B6, M_B6, M_SIN,
    M_A6, M_A6, M_SIN,
    M_G6, M_SIN,
    M_D7, M_D7, M_SIN,
    M_D7, M_D7, M_SIN,
    M_C7, M_C7, M_C7, M_C7, M_SIN,

    M_SIN, M_SIN,
    M_REP, };

static const uint16_t going_track[] = {
    M_G6, M_SIN,
    M_B6, M_SIN,
    M_D7, 
    M_END,
};
static const uint16_t pause_track[] = {
    M_D7, M_SIN,
    M_G7, M_SIN,
    M_C7,
    M_END,
};

uint16_t* current_track = (uint16_t*)timeup_track;
void sing_timeup(bool on) {
    // TODO: sing a song!
    if (on) {
        current_track = (uint16_t*)timeup_track;
        T2PR = TEMPO;
        track_position = 0;
        NCO1INCH = (uint8_t)(current_track[track_position] >> 8);
        NCO1INCL = (uint8_t)(current_track[track_position] & 0xFF);
        NCO1CONbits.N1EN = 1;
        T2CONbits.TMR2ON = 1;
    } else {
        NCO1CONbits.N1EN = 0;
        T2CONbits.TMR2ON = 0;
        T2TMR = 0;
    }
}
void sing_going(void) {
    current_track = (uint16_t*)going_track;
    T2PR = TEMPO;
    track_position = 0;
    NCO1INCH = (uint8_t)(current_track[track_position] >> 8);
    NCO1INCL = (uint8_t)(current_track[track_position] & 0xFF);
    NCO1CONbits.N1EN = 1;
    T2CONbits.TMR2ON = 1;
}
void sing_pause(void) {
    current_track = (uint16_t*)pause_track;
    T2PR = TEMPO;
    track_position = 0;
    NCO1INCH = (uint8_t)(current_track[track_position] >> 8);
    NCO1INCL = (uint8_t)(current_track[track_position] & 0xFF);
    NCO1CONbits.N1EN = 1;
    T2CONbits.TMR2ON = 1;
}
void rhythm_interrupt(void)
{
    track_position++;
    if (current_track[track_position] == M_END) {
        NCO1CONbits.N1EN = 0;
        T2CONbits.TMR2ON = 0;
        T2TMR = 0;
    }
    if (current_track[track_position] == M_REP) {
        track_position = 0;
    }
    NCO1INCH = (uint8_t)(current_track[track_position] >> 8);
    NCO1INCL = (uint8_t)(current_track[track_position] & 0xFF);
    if (current_track[track_position] == M_SIN) {
        NCO1CONbits.N1EN = 0;
    } else {
        NCO1CONbits.N1EN = 1;
    }
}
