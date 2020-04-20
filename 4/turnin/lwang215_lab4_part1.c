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
enum led{init,onp,onr,offp,offr}state;

void tick()
{
unsigned char tmpA = PINA;
switch(state){
case init:
{
	state=onp;
	break;
}

case onp:
if((tmpA&0x01)==0x01)
{
	state = onr;
	break;
}
else{   
        state = onp; 
        break;  
}

case onr:
if((tmpA&0x01)==0x00)
{
	state = offp;
	break;
}
else{
	state = onr;
	break;
}

case offp:
if((tmpA&0x01)==0x01)
{
	state = offr;
	break;
}
else{
	state = offp;
	break;
}

case offr:
if((tmpA&0x01)==0x00)
{
	state = onp;
	break;
}
else{
	state = offr;
	break;
}
}
switch(state){
case onp:
	PORTB = 0x01;
	break;
case offp:
	PORTB = 0x02;
	break;
default:
	PORTB = 0x01;
	break;
} 
}

int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA = 0xFF;
DDRB = 0xFF; PORTB = 0x00;
state = init;

    /* Insert your solution below */
    while (1){
	tick();
    }
    return 1;
}
