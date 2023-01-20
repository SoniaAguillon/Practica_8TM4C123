#ifndef OLED_OLED
#define OLED_OLED_H_

// Function declarations
extern void OLED_Command( uint8_t temp);
extern void OLED_Data( uint8_t  temp);
extern void OLED_Init();
extern void OLED_YX(unsigned char Row, unsigned char Column); // *warning!* max 4 rows
extern void OLED_PutChar( char ch );
extern void OLED_Clear();
extern void OLED_Write_String( char *s );
//void OLED_Write_Integer(uint8_t  i);
//void OLED_Write_Float(float f);
extern void Delay_ms(int time_ms);

// Function prototypes initialize, tranmit and rea functions 
extern void I2C3_Init ( void );  
extern int I2C_wait_till_done(void);
extern char I2C3_Write_Multiple(int slave_address, char slave_memory_address, int bytes_count, uint8_t* data);
extern char I2C3_Wr(int slaveAddr, char memAddr, uint8_t data);


#endif 