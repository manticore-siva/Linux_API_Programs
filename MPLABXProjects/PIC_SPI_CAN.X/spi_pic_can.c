


#include <xc.h>
#define _XTAL_FREQ 20000000


// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.



void uart_init(); 
void uart_print2(unsigned char s);
void uart_print(unsigned char *str);
void uart_tx(unsigned char data);

int main(){
    uart_init();
    uart_print("\n\r");
    uart_print("Sol");
    uart_print("\n\r");
    while(1);
}
void uart_init()
{
	TRISC6 = 0;     // c6 Transmiter pin enable
	TXSTA  = 0x20;   // transmision enable bit
    SPEN   = 1;       // serial port enable 
	SPBRG  = 31;     // Set baudrate
	TXIF   = 0;  
}
void uart_print2(unsigned char s)
{
	for(int i=7; i>=0; i--)
	{
			if(s & (1<<i))
		 		uart_tx('1');
		 else
		 	uart_tx('0');
	}
}
void uart_tx(unsigned char data)
{
	 TXREG=data;
	 while(!TXIF);
	 TXIF=0;
}
void uart_print(unsigned char *str)
{
	while(*str)
	{
		uart_tx(*str++);
	}
}
