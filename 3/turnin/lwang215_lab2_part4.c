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
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA = PINA&0xF0;
	tmpB = PINA&0x0F;
	tmpA = tmpA>>4;
	tmpB = tmpB<<4;
	PORTC = tmpB;
	PORTB = tmpA;
}
	
return 0;

}
