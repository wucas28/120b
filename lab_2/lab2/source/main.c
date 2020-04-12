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
    DDRA = 0x00;
    PORTA = 0xFF;
    DDRC = 0xFF;
    PORTC = 0x00;

    unsigned char numSpaces = 0x00;
    /* Insert your solution below */
    while (1) {
numSpaces = 0x00;  //resets numSpaces everytime the while loop starts
	    if (PINA & 0x01){ //checks to see if PINA at the zero bit is "occupied or not"
		    numSpaces = numSpaces + 1;
	    }
	    if (PINA & 0x02){ //chcks the first bit of PINA
		    numSpaces = numSpaces + 1;
	    }
	    if (PINA & 0x04){ //so on and so forth
		    numSpaces = numSpaces + 1;
	    }
	    if (PINA & 0x08){
		    numSpaces = numSpaces + 1;
	    }
	    PORTC = 4 - numSpaces;}
	    
   
    return 0;
}
