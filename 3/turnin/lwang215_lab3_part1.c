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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char count;
    /* Insert your solution below */
    while (1) {
		unsigned char result = 0x00;
		for(count = 0; count <8 ; count++){
			if((PINA & (0x01 << count)) >> count){
				result++;
			}
			if((PINB & (0x01 << count)) >> count){
				result++;
			}
	}
		PORTC = result;
    }
    
return 0;

}
