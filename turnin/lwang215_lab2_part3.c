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

    /* Insert your solution below */
DDRA = 0x00; PORTA = 0xFF;
DDRC = 0xFF; PORTC = 0x00;
unsigned char tmpA = 0x00;
unsigned char tmpB = 0x00;
    while (1){
	tmpA = PINA;
	tmpB = 0x04;
if((tmpA&0x01) == 0x01){
	tmpB--;
}
if((tmpA&0x02) == 0x02){
        tmpB--;
}
if((tmpA&0x04) == 0x04){
        tmpB--;
}
if((tmpA&0x08) == 0x08){
        tmpB--;
}
PORTC  = tmpB;
if(tmpB == 0x00)
{
	PORTC = 0x80;
}	
    }
    return 0;
}
