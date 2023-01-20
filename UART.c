#include "lib/include.h"

extern void Configurar_UART7(void)
{
    SYSCTL->RCGCUART  |= (1<<7);  //Paso 1 (RCGCUART) pag.344 UART/modulo0 0->Disable 1->Enable         *se habilita la señal de reloj del UART7*
    SYSCTL->RCGCGPIO |= (1<<4);     //Paso 2 (RCGCGPIO) pag.340 Enable clock port A     *Se activa el registro de reloj del GPIO, para el UART7 corresponde puerto E, el cual es el bit 4*    
    //(GPIOAFSEL) pag.671 Enable alternate function         *Se habilitan funcion alternativa del GPIO para configurar los pines*
    GPIOE->AFSEL |= (1<<1) | (1<<0);   //*Corresponde puerto E, pines 0 y 1 
    //GPIO Port Control (GPIOPCTL) PE0-> Entrada (U0Rx) PE1-> Salida (U0Tx) pag.688
    GPIOE->PCTL |= 0x00000011;  // (1<<0) | (1<<4);//0x00000011          ** El pin 0 y 1 corresponde al port mux 0 y 1, por ello se pone en 1 el 1 y 4, checar tabla***  
    // GPIO Digital Enable (GPIODEN) pag.682      **GPIODEN - Para habilitar el pin como pin digital**
    GPIOE->DEN |= (1<<0) | (1<<1);//PE0 PE1          **Puerto E, pines 0 y 1 habilitados como digitales**
    //GPIODIR indica cual pin es entrada y cual es salida pag.663
    // GPIOE->DIR = (1<<1) | (0<<0); //Puerto E, pin 1 (PE1) es salida y pin 0 (PE0) es entrada
   
    //UART0 UART Control (UARTCTL) pag.918 DISABLE!!
    /* Desactivar el UART hasta terminar su configuración -  El bit que lo activa es UARTCTL
    El bit0 UARTEN es el habilitador, por eso se debe poner en 0 
    El bit9 es para RXE y el 8 para TXE, recibir y transmitir, también se ponen en 0 para desactivar */
    UART7->CTL = (0<<9) | (0<<8) | (0<<0);

    // UART Integer Baud-Rate Divisor (UARTIBRD) pag.914
    /*
    BRD = 25,000,000 / (16*57600) = 27.1267
    UARTFBRD[DIVFRAC] = integer(.1267 * 64 + 0.5)
    */

    //CALCULO VELOCIDAD COMUNICACIÓN
    /*
    BRD = 20,000,000/(16∗57,600) = 21.701388
    
    Redondeo --->    UARTFBRD =  (.701388∗64) + 0.5 = 45.388832 = 45
    
    */

    UART7->IBRD = 21;
    // UART Fractional Baud-Rate Divisor (UARTFBRD) pag.915
    UART7->FBRD = 45;
    //Parte decima - No se si esta bien???
    
    //  UART Line Control (UARTLCRH) pag.916
    /* La configuración de la trama se hace con el regitro de nombre generico UARTLCRH - Son 8 bits que se deben configurar:
        Solo nos intereza configurar WLEN -Longitud de palabra UART - Los bits indican el número de bits de datos transmitidos o recibidos 
        FEN -Habilita si es que esta en 1 o deshabilita si es que esta en 0 los FIFOS de recepción y transmición Se recomienda siempre habilitarlos para tener más espacio de almacenamiento de datos
    */
    UART7->LCRH = (0x3<<5)|(1<<4);//WLEN (bit5 conf) - para 8 bits indicado en  0x3      FEN (bit4 conf) - Habilita (1)  los FIFOS

    //  UART Clock Configuration(UARTCC) pag.939        controla la fuente de reloj en baudios para el módulo UART.

    UART7->CC =(0<<0);//Se pone en 0 para indicar Reloj del sistema
    //Disable UART0 UART Control (UARTCTL) pag.918
    UART7->CTL = (1<<0) | (1<<8) | (1<<9);    //Termino la configuración y ahora si se activa el UART  El Rx, Tx y el bit de activacion


}

extern char readChar(void)
{
    //UART FR flag pag 911
    //UART DR data 906
    int v;
    char c;
    while((UART7->FR & (1<<4)) != 0 );      //Se activan  bits de comprobación - Se pregunta si esta ocupada la memoria para recibir datos
    v = UART7->DR & 0xFF;
    c = v;
    return c;
}
extern void printChar(char c)
{
    while((UART7->FR & (1<<5)) != 0 );      //Se activan  bits de comprobación 
    UART7->DR = c;
}
extern void printString(char* string)       //Cadena de caracteres -para escribir 
{
    while(*string)
    {
        printChar(*(string++));
    }
}

extern char * readString(char delimitador)
{

   int i=0;
   char *string = (char *)calloc(10,sizeof(char));
   char c = readChar();
   while(c != delimitador)
   {
       *(string+i) = c;
       i++;
       if(i%10==0)
       {
           string = realloc(string,(i+10)*sizeof(char));
       }
       c = readChar();
   }

   return string;

}
//Experimento 2

//El envio es su nombre  (rave) 

// invertirlo y regresarlo con numeros consecutivos
// entre letras (e1v2a3r) 

