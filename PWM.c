
#include "lib/include.h"

extern void Configura_Reg_PWM1(uint16_t freq)
{ 
/*
    SYSCTL->RCGCPWM |= (1<<0); //Enable reloj de modulo PWM0 pag 354 ------------    Se habilita reloj del modulo 0   
    SYSCTL->RCGCGPIO |= (1<<1); //Habilitar reloj de GPIO Puerto B  pin 4 (Solo se esta poniendo 1 del puerto b)   - Pag 1233
   // GPIOF->AFSEL |= (1<<3)|(1<<2)|(1<<1); //Control de registros ya sea por GPIO o Otros Pag 672    //ESTO SI SE COMENTA
    SYSCTL->RCC |=(1<<20);  //Activamos USEPWMDIV para dividir la señal del reloj 
    SYSCTL->RCC &= 0xFFF0FFFF; //Indicamos en los pines 17-19 que se divida entre 2
    
    GPIOB->AFSEL |= (1<<4); //Indicamos que queremos una funcion alterna en el pin b4 
    GPIOB->PCTL |= 0x00040000; //Combinado con la tabla Pag 1351 y el registro PCTL le digo que es pwm Pag 689
    //Aqui habilitamos la funcion 4 del pin PB4 - en el port mux 4 
    //Se usa el enmascaramiento porque no tiene valores por default 

    GPIOB->DEN |= (1<<4); // para decirle al pin 4 que es digital Pag 682
    // PWM0->CC &= ~(1<<8);  //Enable o Disable Divisor  Pag 1747 ------TIVA GRANDE ESTO SI SE COMENTA

    //El número indica el generador que se va a usar
    PWM0->_1_CTL &= ~(1<<0);  //Se deshabilita el generador 1 del PWM0 para poder configurarlo POR??
    PWM0->_1_GENA = 0x008C; //Se utilizara el generador A del generador 1 del 
    // El 8C es para decir que cuando coincidan, el otro baje para que se genere el PWM 
    //Se va a tener un contador descendente cuando el contador llegue al valor de la carga y va a bajar cuando sea igual 
    //al valor del comparador va a bajar  

    //SE COMIENZAN A HACER LOS CALCULOS 

    PWM0->_1_LOAD = 2500; //cuentas=fclk/fpwm  para 1khz cuentas = (25,000,000/10000)= 2500 ***Se fija a 2499 porque es 2500-1 pq inicia en 0
    //Se utilizo un duty cycle de 20%
    PWM0->_1_CMPB = 2000; // El duty cycle es de 80% (Es el 80% de 2499)
    PWM0->_1_CMPA = 2000; //El duty cycle es 80%
    
    PWM0->_1_CTL |= (1<<0);// Se habilita el generador 1 del PWM0
    PWM0->ENABLE = (1<<2); //habilitar el PWM2EN (Es ese porque es el modulo 0 generador 1) bloque pa que pase Pag 1247
    //La señal pwm1A' generada se pasa al pin MnPWM2
    
//*/
// ---------------------------------------------------------------------------------- EXPERIMENTO PRUEBA 2
    
/*
    
    SYSCTL->RCGCPWM |= (1<<0); //Enable reloj de modulo PWM0 pag 354 ------------    Se habilita reloj del modulo 0   
    SYSCTL->RCGCGPIO |= (1<<1); //Habilitar reloj de GPIO Puerto B  pin 4 (Solo se esta poniendo 1 del puerto b)   - Pag 1233
    SYSCTL->RCGCGPIO |= (1<<4); //Habilitar reloj de GPIO Puerto E  pin 4 (Solo se esta poniendo 1 del puerto E)   - Pag 1233
    // GPIOF->AFSEL |= (1<<3)|(1<<2)|(1<<1); //Control de registros ya sea por GPIO o Otros Pag 672
    SYSCTL->RCC &= 0xFFF0FFFF; //Indicamos en los pines 17-19 que se divida entre 2
    SYSCTL->RCC |=(1<<20);  //Activamos USEPWMDIV para dividir la señal del reloj 
    SYSCTL->RCC &= 0xFFF8FFFF; //Indicamos en los pines 17-19 que se divida entre 2
    
    GPIOB->AFSEL |= (1<<4); //Indicamos que queremos una funcion alterna en el pin b4 
    GPIOE->AFSEL |= (1<<4); //Indicamos que queremos una funcion alterna en el pin E4                   GENERADOR 2

    GPIOB->PCTL |= 0x00040000; //Combinado con la tabla Pag 1351 y el registro PCTL le digo que es pwm Pag 689
    GPIOE->PCTL |= (0xFFF0FFFF) |0x00040000; //Combinado con la tabla Pag 1351 y el registro PCTL le digo que es pwm Pag 689 ---- Aqui habilitamos la funcion 4 del pin PE4 - en el port mux 4 
    //Se usa el enmascaramiento porque no tiene valores por default 
    //Aqui habilitamos la funcion 4 del pin PB4 - en el port mux 4 
    //Se usa el enmascaramiento porque no tiene valores por default 

    GPIOB->DEN |= (1<<4); // para decirle al pin 4 que es digital Pag 682
    GPIOE->DEN |= (1<<4); // para decirle al pin 4 E que es digital Pag 682   --PIN E4 - generador 2
    // PWM0->CC &= ~(1<<8);  //Enable o Disable Divisor  Pag 1747 ------TIVA GRANDE
    // PWM0->CC &= ~(1<<8);  //Enable o Disable Divisor  Pag 1747 ------TIVA GRANDE ESTO SI SE COMENTA

    //El número indica el generador que se va a usar
    PWM0->_1_CTL &= ~(1<<0);  //Se deshabilita el generador 1 del PWM0 para poder configurarlo POR??
    PWM0->_2_CTL &= ~(1<<0);  //Se deshabilita el generador 2 del PWM0 para poder configurarlo POR??
    PWM0->_1_GENA = 0x008C; //Se utilizara el generador A del generador 1 del 
    PWM0->_2_GENA = 0x008C; //Se utilizara el generador A del generador 2 del 
    // El 8C es para decir que cuando coincidan, el otro baje para que se genere el PWM 
    //Se va a tener un contador descendente cuando el contador llegue al valor de la carga y va a bajar cuando sea igual 
    //al valor del comparador va a bajar  

    //SE COMIENZAN A HACER LOS CALCULOS 

    PWM0->_1_LOAD = 2500; //cuentas=fclk/fpwm  para 1khz cuentas = (25,000,000/10000)= 2500 ***Se fija a 2499 porque es 2500-1 pq inicia en 0
    //Se utilizo un duty cycle de 20%
    PWM0->_1_CMPB = 2000; // El duty cycle es de 80% (Es el 80% de 2499)
    PWM0->_1_CMPA = 2000; //El duty cycle es 80%
    
//------------------------------------generador 2
    PWM0->_2_LOAD = 2500; //cuentas=fclk/fpwm  para 1khz cuentas = (25,000,000/10000)= 2500 ***Se fija a 2499 porque es 2500-1 pq inicia en 0
    //Se utilizo un duty cycle de 20%
    PWM0->_2_CMPB = 2000; // El duty cycle es de 80% (Es el 80% de 2499)
    PWM0->_2_CMPA = 2000; //El duty cycle es 80%


    PWM0->_1_CTL |= (1<<0);// Se habilita el generador 1 del PWM0
    PWM0->_2_CTL |= (1<<0);// Se habilita el generador 2 del PWM0
    
    PWM0->ENABLE |= (1<<4); //habilitar el PWM0EN (Es ese porque es el modulo 0 generador 2) bloque pa que pase Pag 1247
    //La señal pwm1A' generada se pasa al pin M0PWM4
    PWM0->ENABLE |= (1<<2); //habilitar el PWM2EN (Es ese porque es el modulo 0 generador 1) bloque pa que pase Pag 1247
    //La señal pwm1A' generada se pasa al pin MnPWM2


//*/

// EXPERIMENTO 2----------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------GENERADOR 0 
//*
    SYSCTL->RCGCPWM |= (1<<0); //Enable reloj de modulo PWM0 pag 354 ------------    Se habilita reloj del modulo 0  
    SYSCTL->RCGCGPIO |= (1<<1); //Habilitar reloj de GPIO Puerto B  pin 4 (Solo se esta poniendo 1 del puerto b)   - Pag 1233
    SYSCTL->RCGCGPIO |= (1<<4); //Habilitar reloj de GPIO Puerto E  pin 4 (Solo se esta poniendo 1 del puerto E)   - Pag 1233
    // GPIOF->AFSEL |= (1<<3)|(1<<2)|(1<<1); //Control de registros ya sea por GPIO o Otros Pag 672
   
    SYSCTL->RCC &= 0xFFF0FFFF; //Indicamos en los pines 17-19 que se divida entre 2
    SYSCTL->RCC |=(1<<20);  //Activamos USEPWMDIV para dividir la señal del reloj 
    SYSCTL->RCC |= 0x00040000; //Indicamos en los pines 17-19 que se divida entre 2

    GPIOB->AFSEL |= (1<<6); //Indicamos que queremos una funcion alterna en el pin b6                   GENERADOR 0
    GPIOB->AFSEL |= (1<<4); //Indicamos que queremos una funcion alterna en el pin b4                   GENERADOR 1
    GPIOE->AFSEL |= (1<<4); //Indicamos que queremos una funcion alterna en el pin E4                   GENERADOR 2

    GPIOB->PCTL |=0x04040000; //Combinado con la tabla Pag 1351 y el registro PCTL le digo que es pwm Pag 689 ---- Aqui habilitamos la funcion 4 del pin PB4 - en el port mux 4 
    GPIOE->PCTL |=0x00040000; //Combinado con la tabla Pag 1351 y el registro PCTL le digo que es pwm Pag 689 ---- Aqui habilitamos la funcion 4 del pin PE4 - en el port mux 4 
    //Se usa el enmascaramiento porque no tiene valores por default 

    GPIOB->DEN |= (1<<6); // para decirle al pin 6 B que es digital Pag 682   --PIN B6 - generador 0
    GPIOB->DEN |= (1<<4); // para decirle al pin 4 B que es digital Pag 682   --PIN B4 - generador 1
    GPIOE->DEN |= (1<<4); // para decirle al pin 4 E que es digital Pag 682   --PIN E4 - generador 2
    
    //El número indica el generador que se va a usar
    PWM0->_0_CTL &= ~(1<<0);  //Se deshabilita el generador 0 del PWM0 para poder configurarlo 
    PWM0->_1_CTL &= ~(1<<0);  //Se deshabilita el generador 1 del PWM0 para poder configurarlo POR?? 
    PWM0->_2_CTL &= ~(1<<0);  //Se deshabilita el generador 2 del PWM0 para poder configurarlo POR?? 

    PWM0->_0_GENA = 0x008C; //Se utilizara el generador A del generador 0 del 
    PWM0->_1_GENA = 0x008C; //Se utilizara el generador A del generador 1 del 
    PWM0->_2_GENA = 0x008C; //Se utilizara el generador A del generador 2 del 
    // El 8C es para decir que cuando coincidan, el otro baje para que se genere el PWM 
    //Se va a tener un contador descendente cuando el contador llegue al valor de la carga y va a bajar cuando sea igual 
    //al valor del comparador va a bajar  

    //SE COMIENZAN A HACER LOS CALCULOS 
    //----------------------------------- generador 0
    PWM0->_0_LOAD = 50000; //cuentas=fclk/fpwm  para 1khz cuentas = (25,000,000/10000)= 2500 ***Se fija a 2499 porque es 2500-1 pq inicia en 0
    //Se utilizo un duty cycle de 20%
    PWM0->_0_CMPB = 40000; // El duty cycle es de 80% (Es el 80% de 2499)
    PWM0->_0_CMPA = 40000; //El duty cycle es 80%

    //----------------------------------- generador 1
    PWM0->_1_LOAD = 50000; //cuentas=fclk/fpwm  para 1khz cuentas = (25,000,000/10000)= 2500 ***Se fija a 2499 porque es 2500-1 pq inicia en 0
    //Se utilizo un duty cycle de 20%
    PWM0->_1_CMPB = 40000; // El duty cycle es de 80% (Es el 80% de 2499)
    PWM0->_1_CMPA = 40000; //El duty cycle es 80%

    //------------------------------------generador 2
    PWM0->_2_LOAD = 50000; //cuentas=fclk/fpwm  para 1khz cuentas = (25,000,000/10000)= 2500 ***Se fija a 2499 porque es 2500-1 pq inicia en 0
    //Se utilizo un duty cycle de 20%
    PWM0->_2_CMPB = 40000; // El duty cycle es de 80% (Es el 80% de 2499)
    PWM0->_2_CMPA = 40000; //El duty cycle es 80%


    PWM0->_0_CTL = (1<<0); // Se habilita el generador 0 del PWM0
    PWM0->_1_CTL = (1<<0); // Se habilita el generador 1 del PWM0
    PWM0->_2_CTL = (1<<0); // Se habilita el generador 2 del PWM0

    PWM0->ENABLE |= (1<<2) | (1<<0); //habilitar el PWM0EN (Es ese porque es el modulo 0 generador 0) bloque pa que pase Pag 1247
    //La señal pwm1A' generada se pasa al pin M0PWM0
    PWM0->ENABLE |= (1<<4); //habilitar el PWM0EN (Es ese porque es el modulo 0 generador 2) bloque pa que pase Pag 1247
    //La señal pwm1A' generada se pasa al pin M0PWM4

//*/


    //------------------------------------------------------------------- GENERADOR 1







}
