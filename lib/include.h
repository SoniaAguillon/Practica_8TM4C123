
#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "TM4C123GH6PM.h"



#define _40MHZ 9
#define _20MHZ 19
#define _10MHZ 39
#define _50MHZ 0x07
#define _25MHZ 0x0F
#define _80MHZ 0x04

// Define OLED dimensions
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define slaveaddress 0x3C
// Define command macros
#define OLED_SETCONTRAST 0x81
#define OLED_DISPLAYALLON_RESUME 0xA4
#define OLED_DISPLAYALLON 0xA5
#define OLED_NORMALDISPLAY 0xA6
#define OLED_INVERTDISPLAY 0xA7
#define OLED_DISPLAYOFF 0xAE
#define OLED_DISPLAYON 0xAF
#define OLED_SETDISPLAYOFFSET 0xD3
#define OLED_SETCOMPINS 0xDA
#define OLED_SETVCOMDETECT 0xDB
#define OLED_SETDISPLAYCLOCKDIV 0xD5
#define OLED_SETPRECHARGE 0xD9
#define OLED_SETMULTIPLEX 0xA8
#define OLED_SETLOWCOLUMN 0x00
#define OLED_SETHIGHCOLUMN 0x10
#define OLED_SETSTARTLINE 0x40
#define OLED_MEMORYMODE 0x20
#define OLED_COLUMNADDR 0x21
#define OLED_PAGEADDR   0x22
#define OLED_COMSCANINC 0xC0
#define OLED_COMSCANDEC 0xC8
#define OLED_SEGREMAP 0xA0
#define OLED_CHARGEPUMP 0x8D

// fin  = fxtal / [(Q+1) * (N+1)]
//      = 25MHz / [(0+1) * (4+1)] = 5MHz
// fvoc = fin * MDIV
//      = 5MHz * 96.00 = 480MHz
// fsyclk = fvco / (PSYSDIV + 1)
//        = 480 / (3 + 1 ) = 120MHz

#define MINT    96
#define MFRAC   0
#define N       4
#define Q       0
#define PSYSDIV 23

#define FBCHT   0x6
#define EBCHT   0x6
#define FBCE    0
#define EBCE    0
#define FWS     0x5
#define EWS     0x5
#define MB1     0x00100010

#define F100HZ (20000000/100)

#define NVIC_ST_CTRL_COUNT      0x00010000  // Count flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Counter mode
#define NVIC_ST_RELOAD_M        0x00FFFFFF  // Counter load value



#include "PLL.h"
#include "GPIO.h"
#include "UART.h"
#include "ADC.h"
#include "PWM.h"
#include "OLED.h"






#endif /* INCLUDE_H_ */