#include "lib/include.h"

/////////////////////////////////////////////////////////////////////////////////////////////////// VARIABLES GLOBLALES
uint8_t dc = 25;

char data_str[32];

uint16_t adc_data[3] = {0};
uint8_t i = 0;

uint8_t servo1_dc = 0;
uint8_t servo2_dc = 0;
uint8_t servo3_dc = 0;
int main(void)
{
	 I2C3_Init();
	 OLED_Init();
	 OLED_Clear();
    
    // variables for counting
    //int count = 0;
    //float dec = 0.0;

        while ( 1 ) {
            
            /////////////////////
            // Strings
            ///////////////////
            
             OLED_YX( 0, 0 );
             OLED_Write_String( "SONIA" );
                             Delay_ms(1000);

            OLED_YX(1, 1);
             OLED_Write_String ("261520");
                         Delay_ms(1000);
            

             OLED_YX(2, 2);
             OLED_Write_String ("MICRO <3 :)");
                         Delay_ms(1000);
            
            /////////////////////
            // Integer Count
            ////////////////////
            
                Delay_ms(100);
            }
          
   }
