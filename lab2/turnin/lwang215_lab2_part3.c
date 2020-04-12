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

    unsigned char ava = 0x00;
    /* Insert your solution below */
    while (1) {
	ava = 0x04;
	if(PINA & 0x01)
{
	ava--;
}
	if(PINA & 0x02)
{
        ava--;
}
	if(PINA & 0x04)
{
        ava--;
}
	if(PINA & 0x08)
{
        ava--;
}
PORTC = ava;
	if(PORTC == 0x00)
{
PORTC = 0x80;
}
    }
    return 0;
}
