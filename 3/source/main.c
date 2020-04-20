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
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	unsigned short tmpA = 0x0000;
	unsigned char tmpB = 0x00;
    /* Insert your solution below */
while(1)
{
	tmpA=(PIND<<1)|(PINB&0x01);
	if(tmpA>=70)
{
	tmpB=0x02;
}
	else if(tmpA>5)
{
	tmpB=0x04;
}
	else
{
	tmpB=0x00;
}
PORTB = tmpB; 
}	
return 0;

}
