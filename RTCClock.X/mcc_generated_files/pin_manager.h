/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC16F18857
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.30 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set D_IN aliases
#define D_IN_TRIS                 TRISAbits.TRISA0
#define D_IN_LAT                  LATAbits.LATA0
#define D_IN_PORT                 PORTAbits.RA0
#define D_IN_WPU                  WPUAbits.WPUA0
#define D_IN_OD                   ODCONAbits.ODCA0
#define D_IN_ANS                  ANSELAbits.ANSA0
#define D_IN_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define D_IN_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define D_IN_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define D_IN_GetValue()           PORTAbits.RA0
#define D_IN_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define D_IN_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define D_IN_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define D_IN_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define D_IN_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define D_IN_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define D_IN_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define D_IN_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set D_OUT aliases
#define D_OUT_TRIS                 TRISAbits.TRISA1
#define D_OUT_LAT                  LATAbits.LATA1
#define D_OUT_PORT                 PORTAbits.RA1
#define D_OUT_WPU                  WPUAbits.WPUA1
#define D_OUT_OD                   ODCONAbits.ODCA1
#define D_OUT_ANS                  ANSELAbits.ANSA1
#define D_OUT_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define D_OUT_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define D_OUT_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define D_OUT_GetValue()           PORTAbits.RA1
#define D_OUT_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define D_OUT_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define D_OUT_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define D_OUT_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define D_OUT_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define D_OUT_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define D_OUT_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define D_OUT_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set SCLK aliases
#define SCLK_TRIS                 TRISAbits.TRISA2
#define SCLK_LAT                  LATAbits.LATA2
#define SCLK_PORT                 PORTAbits.RA2
#define SCLK_WPU                  WPUAbits.WPUA2
#define SCLK_OD                   ODCONAbits.ODCA2
#define SCLK_ANS                  ANSELAbits.ANSA2
#define SCLK_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SCLK_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SCLK_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SCLK_GetValue()           PORTAbits.RA2
#define SCLK_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SCLK_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SCLK_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SCLK_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SCLK_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define SCLK_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define SCLK_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define SCLK_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set CS_ aliases
#define CS__TRIS                 TRISAbits.TRISA3
#define CS__LAT                  LATAbits.LATA3
#define CS__PORT                 PORTAbits.RA3
#define CS__WPU                  WPUAbits.WPUA3
#define CS__OD                   ODCONAbits.ODCA3
#define CS__ANS                  ANSELAbits.ANSA3
#define CS__SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define CS__SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define CS__Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define CS__GetValue()           PORTAbits.RA3
#define CS__SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define CS__SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define CS__SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define CS__ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define CS__SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define CS__SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define CS__SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define CS__SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set DIM aliases
#define DIM_TRIS                 TRISAbits.TRISA4
#define DIM_LAT                  LATAbits.LATA4
#define DIM_PORT                 PORTAbits.RA4
#define DIM_WPU                  WPUAbits.WPUA4
#define DIM_OD                   ODCONAbits.ODCA4
#define DIM_ANS                  ANSELAbits.ANSA4
#define DIM_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define DIM_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define DIM_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define DIM_GetValue()           PORTAbits.RA4
#define DIM_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define DIM_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define DIM_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define DIM_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define DIM_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define DIM_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define DIM_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define DIM_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RTC_INT_ aliases
#define RTC_INT__TRIS                 TRISAbits.TRISA5
#define RTC_INT__LAT                  LATAbits.LATA5
#define RTC_INT__PORT                 PORTAbits.RA5
#define RTC_INT__WPU                  WPUAbits.WPUA5
#define RTC_INT__OD                   ODCONAbits.ODCA5
#define RTC_INT__ANS                  ANSELAbits.ANSA5
#define RTC_INT__SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RTC_INT__SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RTC_INT__Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RTC_INT__GetValue()           PORTAbits.RA5
#define RTC_INT__SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RTC_INT__SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RTC_INT__SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define RTC_INT__ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define RTC_INT__SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define RTC_INT__SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define RTC_INT__SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define RTC_INT__SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RA6 procedures
#define RA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define RA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define RA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define RA6_GetValue()              PORTAbits.RA6
#define RA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define RA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define RA6_SetPullup()             do { WPUAbits.WPUA6 = 1; } while(0)
#define RA6_ResetPullup()           do { WPUAbits.WPUA6 = 0; } while(0)
#define RA6_SetAnalogMode()         do { ANSELAbits.ANSA6 = 1; } while(0)
#define RA6_SetDigitalMode()        do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set RA7 procedures
#define RA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define RA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define RA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define RA7_GetValue()              PORTAbits.RA7
#define RA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define RA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define RA7_SetPullup()             do { WPUAbits.WPUA7 = 1; } while(0)
#define RA7_ResetPullup()           do { WPUAbits.WPUA7 = 0; } while(0)
#define RA7_SetAnalogMode()         do { ANSELAbits.ANSA7 = 1; } while(0)
#define RA7_SetDigitalMode()        do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set SEG_A aliases
#define SEG_A_TRIS                 TRISBbits.TRISB0
#define SEG_A_LAT                  LATBbits.LATB0
#define SEG_A_PORT                 PORTBbits.RB0
#define SEG_A_WPU                  WPUBbits.WPUB0
#define SEG_A_OD                   ODCONBbits.ODCB0
#define SEG_A_ANS                  ANSELBbits.ANSB0
#define SEG_A_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define SEG_A_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define SEG_A_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SEG_A_GetValue()           PORTBbits.RB0
#define SEG_A_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define SEG_A_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define SEG_A_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define SEG_A_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define SEG_A_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define SEG_A_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define SEG_A_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define SEG_A_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set SEG_B aliases
#define SEG_B_TRIS                 TRISBbits.TRISB1
#define SEG_B_LAT                  LATBbits.LATB1
#define SEG_B_PORT                 PORTBbits.RB1
#define SEG_B_WPU                  WPUBbits.WPUB1
#define SEG_B_OD                   ODCONBbits.ODCB1
#define SEG_B_ANS                  ANSELBbits.ANSB1
#define SEG_B_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SEG_B_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SEG_B_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SEG_B_GetValue()           PORTBbits.RB1
#define SEG_B_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SEG_B_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SEG_B_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SEG_B_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SEG_B_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define SEG_B_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define SEG_B_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define SEG_B_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set SEG_C aliases
#define SEG_C_TRIS                 TRISBbits.TRISB2
#define SEG_C_LAT                  LATBbits.LATB2
#define SEG_C_PORT                 PORTBbits.RB2
#define SEG_C_WPU                  WPUBbits.WPUB2
#define SEG_C_OD                   ODCONBbits.ODCB2
#define SEG_C_ANS                  ANSELBbits.ANSB2
#define SEG_C_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SEG_C_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SEG_C_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SEG_C_GetValue()           PORTBbits.RB2
#define SEG_C_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SEG_C_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SEG_C_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SEG_C_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SEG_C_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define SEG_C_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define SEG_C_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define SEG_C_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set SEG_D aliases
#define SEG_D_TRIS                 TRISBbits.TRISB3
#define SEG_D_LAT                  LATBbits.LATB3
#define SEG_D_PORT                 PORTBbits.RB3
#define SEG_D_WPU                  WPUBbits.WPUB3
#define SEG_D_OD                   ODCONBbits.ODCB3
#define SEG_D_ANS                  ANSELBbits.ANSB3
#define SEG_D_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SEG_D_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SEG_D_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SEG_D_GetValue()           PORTBbits.RB3
#define SEG_D_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SEG_D_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SEG_D_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SEG_D_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SEG_D_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SEG_D_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SEG_D_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define SEG_D_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set SEG_E aliases
#define SEG_E_TRIS                 TRISBbits.TRISB4
#define SEG_E_LAT                  LATBbits.LATB4
#define SEG_E_PORT                 PORTBbits.RB4
#define SEG_E_WPU                  WPUBbits.WPUB4
#define SEG_E_OD                   ODCONBbits.ODCB4
#define SEG_E_ANS                  ANSELBbits.ANSB4
#define SEG_E_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SEG_E_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SEG_E_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SEG_E_GetValue()           PORTBbits.RB4
#define SEG_E_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SEG_E_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SEG_E_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SEG_E_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SEG_E_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SEG_E_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SEG_E_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SEG_E_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set SEG_F aliases
#define SEG_F_TRIS                 TRISBbits.TRISB5
#define SEG_F_LAT                  LATBbits.LATB5
#define SEG_F_PORT                 PORTBbits.RB5
#define SEG_F_WPU                  WPUBbits.WPUB5
#define SEG_F_OD                   ODCONBbits.ODCB5
#define SEG_F_ANS                  ANSELBbits.ANSB5
#define SEG_F_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SEG_F_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SEG_F_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SEG_F_GetValue()           PORTBbits.RB5
#define SEG_F_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SEG_F_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SEG_F_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SEG_F_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SEG_F_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SEG_F_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SEG_F_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define SEG_F_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set SEG_G aliases
#define SEG_G_TRIS                 TRISBbits.TRISB6
#define SEG_G_LAT                  LATBbits.LATB6
#define SEG_G_PORT                 PORTBbits.RB6
#define SEG_G_WPU                  WPUBbits.WPUB6
#define SEG_G_OD                   ODCONBbits.ODCB6
#define SEG_G_ANS                  ANSELBbits.ANSB6
#define SEG_G_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SEG_G_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SEG_G_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SEG_G_GetValue()           PORTBbits.RB6
#define SEG_G_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SEG_G_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SEG_G_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SEG_G_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SEG_G_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define SEG_G_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define SEG_G_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define SEG_G_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set SEG_DP aliases
#define SEG_DP_TRIS                 TRISBbits.TRISB7
#define SEG_DP_LAT                  LATBbits.LATB7
#define SEG_DP_PORT                 PORTBbits.RB7
#define SEG_DP_WPU                  WPUBbits.WPUB7
#define SEG_DP_OD                   ODCONBbits.ODCB7
#define SEG_DP_ANS                  ANSELBbits.ANSB7
#define SEG_DP_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define SEG_DP_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define SEG_DP_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define SEG_DP_GetValue()           PORTBbits.RB7
#define SEG_DP_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define SEG_DP_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define SEG_DP_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define SEG_DP_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define SEG_DP_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define SEG_DP_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define SEG_DP_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define SEG_DP_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set I_SW3 aliases
#define I_SW3_TRIS                 TRISCbits.TRISC0
#define I_SW3_LAT                  LATCbits.LATC0
#define I_SW3_PORT                 PORTCbits.RC0
#define I_SW3_WPU                  WPUCbits.WPUC0
#define I_SW3_OD                   ODCONCbits.ODCC0
#define I_SW3_ANS                  ANSELCbits.ANSC0
#define I_SW3_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define I_SW3_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define I_SW3_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define I_SW3_GetValue()           PORTCbits.RC0
#define I_SW3_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define I_SW3_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define I_SW3_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define I_SW3_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define I_SW3_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define I_SW3_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define I_SW3_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define I_SW3_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set I_SW2 aliases
#define I_SW2_TRIS                 TRISCbits.TRISC1
#define I_SW2_LAT                  LATCbits.LATC1
#define I_SW2_PORT                 PORTCbits.RC1
#define I_SW2_WPU                  WPUCbits.WPUC1
#define I_SW2_OD                   ODCONCbits.ODCC1
#define I_SW2_ANS                  ANSELCbits.ANSC1
#define I_SW2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define I_SW2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define I_SW2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define I_SW2_GetValue()           PORTCbits.RC1
#define I_SW2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define I_SW2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define I_SW2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define I_SW2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define I_SW2_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define I_SW2_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define I_SW2_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define I_SW2_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set I_SW1 aliases
#define I_SW1_TRIS                 TRISCbits.TRISC2
#define I_SW1_LAT                  LATCbits.LATC2
#define I_SW1_PORT                 PORTCbits.RC2
#define I_SW1_WPU                  WPUCbits.WPUC2
#define I_SW1_OD                   ODCONCbits.ODCC2
#define I_SW1_ANS                  ANSELCbits.ANSC2
#define I_SW1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define I_SW1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define I_SW1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define I_SW1_GetValue()           PORTCbits.RC2
#define I_SW1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define I_SW1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define I_SW1_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define I_SW1_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define I_SW1_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define I_SW1_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define I_SW1_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define I_SW1_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set I_SW0 aliases
#define I_SW0_TRIS                 TRISCbits.TRISC3
#define I_SW0_LAT                  LATCbits.LATC3
#define I_SW0_PORT                 PORTCbits.RC3
#define I_SW0_WPU                  WPUCbits.WPUC3
#define I_SW0_OD                   ODCONCbits.ODCC3
#define I_SW0_ANS                  ANSELCbits.ANSC3
#define I_SW0_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define I_SW0_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define I_SW0_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define I_SW0_GetValue()           PORTCbits.RC3
#define I_SW0_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define I_SW0_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define I_SW0_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define I_SW0_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define I_SW0_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define I_SW0_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define I_SW0_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define I_SW0_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set DIGI_0 aliases
#define DIGI_0_TRIS                 TRISCbits.TRISC4
#define DIGI_0_LAT                  LATCbits.LATC4
#define DIGI_0_PORT                 PORTCbits.RC4
#define DIGI_0_WPU                  WPUCbits.WPUC4
#define DIGI_0_OD                   ODCONCbits.ODCC4
#define DIGI_0_ANS                  ANSELCbits.ANSC4
#define DIGI_0_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define DIGI_0_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define DIGI_0_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define DIGI_0_GetValue()           PORTCbits.RC4
#define DIGI_0_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define DIGI_0_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define DIGI_0_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define DIGI_0_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define DIGI_0_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define DIGI_0_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define DIGI_0_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define DIGI_0_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set DIGI_1 aliases
#define DIGI_1_TRIS                 TRISCbits.TRISC5
#define DIGI_1_LAT                  LATCbits.LATC5
#define DIGI_1_PORT                 PORTCbits.RC5
#define DIGI_1_WPU                  WPUCbits.WPUC5
#define DIGI_1_OD                   ODCONCbits.ODCC5
#define DIGI_1_ANS                  ANSELCbits.ANSC5
#define DIGI_1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define DIGI_1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define DIGI_1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define DIGI_1_GetValue()           PORTCbits.RC5
#define DIGI_1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define DIGI_1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define DIGI_1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define DIGI_1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define DIGI_1_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define DIGI_1_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define DIGI_1_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define DIGI_1_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set DIGI_2 aliases
#define DIGI_2_TRIS                 TRISCbits.TRISC6
#define DIGI_2_LAT                  LATCbits.LATC6
#define DIGI_2_PORT                 PORTCbits.RC6
#define DIGI_2_WPU                  WPUCbits.WPUC6
#define DIGI_2_OD                   ODCONCbits.ODCC6
#define DIGI_2_ANS                  ANSELCbits.ANSC6
#define DIGI_2_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define DIGI_2_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define DIGI_2_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define DIGI_2_GetValue()           PORTCbits.RC6
#define DIGI_2_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define DIGI_2_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define DIGI_2_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define DIGI_2_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define DIGI_2_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define DIGI_2_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define DIGI_2_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define DIGI_2_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set DIGI_3 aliases
#define DIGI_3_TRIS                 TRISCbits.TRISC7
#define DIGI_3_LAT                  LATCbits.LATC7
#define DIGI_3_PORT                 PORTCbits.RC7
#define DIGI_3_WPU                  WPUCbits.WPUC7
#define DIGI_3_OD                   ODCONCbits.ODCC7
#define DIGI_3_ANS                  ANSELCbits.ANSC7
#define DIGI_3_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define DIGI_3_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define DIGI_3_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define DIGI_3_GetValue()           PORTCbits.RC7
#define DIGI_3_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define DIGI_3_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define DIGI_3_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define DIGI_3_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define DIGI_3_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define DIGI_3_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define DIGI_3_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define DIGI_3_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF5 pin functionality
 * @Example
    IOCAF5_ISR();
 */
void IOCAF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_InterruptHandler);

*/
extern void (*IOCAF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);

*/
void IOCAF5_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF0 pin functionality
 * @Example
    IOCCF0_ISR();
 */
void IOCCF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF0_SetInterruptHandler() method.
    This handler is called every time the IOCCF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(IOCCF0_InterruptHandler);

*/
extern void (*IOCCF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF0_SetInterruptHandler() method.
    This handler is called every time the IOCCF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF0_SetInterruptHandler(IOCCF0_DefaultInterruptHandler);

*/
void IOCCF0_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF1 pin functionality
 * @Example
    IOCCF1_ISR();
 */
void IOCCF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_InterruptHandler);

*/
extern void (*IOCCF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_DefaultInterruptHandler);

*/
void IOCCF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF2 pin functionality
 * @Example
    IOCCF2_ISR();
 */
void IOCCF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_InterruptHandler);

*/
extern void (*IOCCF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_DefaultInterruptHandler);

*/
void IOCCF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF3 pin functionality
 * @Example
    IOCCF3_ISR();
 */
void IOCCF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF3_SetInterruptHandler() method.
    This handler is called every time the IOCCF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(IOCCF3_InterruptHandler);

*/
extern void (*IOCCF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF3_SetInterruptHandler() method.
    This handler is called every time the IOCCF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF3_SetInterruptHandler(IOCCF3_DefaultInterruptHandler);

*/
void IOCCF3_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/