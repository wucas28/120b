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
enum num{init,waitP,waitY,lock,unlock}state;

void tick()
{
unsigned char tmpA = PINA;
	switch(state){
case init:
state = lock;
break;

case lock:
if(tmpA==0x04){
	state = waitP;
}
else{
	state = lock;
}
break;

case waitP:
if(tmpA==0x00){
	state = waitY;
}
else{
	state = lock;
}
break;

case waitY:
if(tmpA==0x02){
	state = unlock;
}
else{
	state = lock;
}
break;

case unlock:
if(tmpA==0x80){
	state = lock;
}
break;
}


switch(state){
case init:
PORTB = 0x00;
break;

case lock:
break;

case waitP:
break;

case waitY:
break;

case unlock:
PORTB = 0x01;
break;

default:
break;
}
}

int main(void){
DDRA=0x00; PORTA=0xFF;
DDRB=0xFF; PORTB=0x00;

state = init;

while(1){
	tick();
}
}

