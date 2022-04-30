/* 
 * Copyright 2020-2021 JL1TTD Hidenori Ishii
 * 
 * File:   nco_music.h
 * Author: JL1TTD Hidenori Ishii
 *
 * Created on October 9, 2020, 6:48 PM
 */

#ifndef NCO_MUSIC_H
#define	NCO_MUSIC_H

#include <stdint.h>
#include <stdbool.h>

// x = FOSC/(10^20) = 3.814697265625 Inc = Fx*2 / x
//    ド   261.626     C4  523.252    137.1673723 138
//    レ   293.665     D4  587.33     153.9650355 154
//    ミ   329.628     E4  659.256    172.8200049 173
//    ファ 349.228     F4  698.456    183.0960497 184
//    ソ   391.995     G4  783.99     205.5182746 206
//    ラ   440.000     A4  880        230.68672   231
//    シ   493.883     B4  987.766    258.9369303 259
//    ド   523.251     C5  1046.502   274.3342203 275
//    レ   587.330     D5  1174.66    307.930071  308
//    ミ   659.255     E5  1318.51    345.6394854 346
//    ファ 698.456     F5  1396.912   366.1920993 367
//    ソ   783.991     G5  1567.982   411.0370734 412
//    ラ   880.000     A5  1760       461.37344   462
//    シ   987.767     B5  1975.534   517.8743849 518
//    ド   1046.502    C6  2093.004   548.6684406 549
//    レ   1174.659    D6  2349.318   615.8596178 616
//    ミ   1318.510    E6  2637.02    691.2789709 692
//    ファ 1396.913    F6  2793.826   732.3847229 733
//    ソ   1567.982    G6  3135.964   822.0741468 823
//    ラ   1760.000    A6  3520       922.74688   923
//    シ   1975.533    B6  3951.066   1035.748246 1036
//    ド   2093.005    C7  4186.01    1097.337405 1098
//    レ   2349.318    D7  4698.636   1231.719236 1232
//    ミ   2637.020    E7  5274.04    1382.557942 1383
//    ファ 2793.826    F7  5587.652   1464.769446 1465
//    ソ   3135.963    G7  6271.926   1644.147769 1645
//    ラ   3520.000    A7  7040       1845.49376  1846
//    シ   3951.066    B7  7902.132   2071.496491 2072
//    ド   4186.009    C8  8372.018   2194.674287 2195

#define M_SIN   0
#define M_REP   0xFFFE
#define M_END   0xFFFF
#define M_C4  138
#define M_D4  154
#define M_E4  173
#define M_F4  184
#define M_G4  206
#define M_A4  231
#define M_B4  259
#define M_C5  275
#define M_D5  308
#define M_E5  346
#define M_F5  367
#define M_G5  412
#define M_A5  462
#define M_B5  518
#define M_C6  549
#define M_D6  616
#define M_E6  692
#define M_F6  733
#define M_G6  823
#define M_A6  923
#define M_B6  1036
#define M_C7  1098
#define M_D7  1232
#define M_E7  1383
#define M_F7  1465
#define M_G7  1645
#define M_A7  1846
#define M_B7  2072
#define M_C8  2195

// FOSC/4 = 1MHz 1us * 128 * 16 = 2048us * TEMPO
#define TEMPO 150

void rhythm_interrupt(void);

void sing_timeup(bool on);
void sing_going(void);
void sing_pause(void);

#endif	/* NCO_MUSIC_H */

