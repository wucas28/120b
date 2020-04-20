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
enum num{init,add,minus,reset,wait,check}state;

void tick()
{
unsigned char tmpA = PINA;
	switch(state){
case init:
state = check;
break;

case check:
if(tmpA==0x01){
	state = add;
}
else if(tmpA==0x02){
	state = minus;
}
else if(tmpA==0x03){
	state = reset;
}
else{
	state = check;
}
break;

case add:
state = wait;
break;

case minus:
state = wait;
break;

case wait:
if(tmpA==0x01)
{
	state = add;
}
else if(tmpA==0x02)
{
	state = minus;
}
else if(tmpA==0x03)
{
	state = reset;
}
break;

case reset:
state = check;
break;

default:
state = init;
break;
}

switch(state){
case init:
PORTC = 0x07;
break;

case check:
break;

case add:
if(PORTC<0x09){
	PORTC++;
}
break;

case minus:
if(PORTC>0x00){
	PORTC--;
}

case wait:
break;

case reset:
PORTC = 0x00;
break;

default:
break;
}
}

int main(void){
DDRA=0x00; PORTA=0xFF;
DDRC=0xFF; PORTC=0x00;

state = init;

while(1){
	tick();
}
}

