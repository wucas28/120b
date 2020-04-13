/*	Author: lwang215
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) { 
   /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char result = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char safe = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA&0x0F;
	safe = PINA&0xF0;
if(tmpA==0)
{
	result=0x40;
}
else if(tmpA<=2)
{
	result=0x60;		
}
else if(tmpA<=4)
{
	result=0x70;
}
else if(tmpA<=6)
{
	result=0x38;
}
else if(tmpA<=9)
{
	result=0x3C;
}
else if(tmpA<=12)
{
	result=0x3E;
}
else
{
	result=0x3F;
}

if(safe==0x30)
{
	result = result + 0x80;
}
PORTC = result;
}
	
return 0;

}
