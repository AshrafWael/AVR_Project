typedef unsigned char u8;
#include <util/delay.h>
#include <stdint.h>
#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x39)

#define DDRB *((u8*)0x37)
#define PORTB *((u8*)0x38)
#define PINB *((volatile u8*)0x36)

int main (void){
	DDRA |=(1<<0); // binA0, binA1 is out
	DDRA |=(1<<1);

	PORTA &=~(1<<0); // set two bin 0
	PORTA &=~(1<<1);

	DDRB &=~(1<<0); // all this pines is input
	DDRB &=~(1<<1);
	DDRB &=~(1<<2);

	PORTB |=(1<<0); //all this pin is 1 to activate puul up reg
	PORTB |=(1<<1);
	PORTB |=(1<<2);
	while(1){
		if (((PINB>>0)&1)==0 & ((PINB>>1)&1)==1 &((PINB>>2)&1)==1){
			PORTA |=(1<<0);
		}
		else if (((PINB>>1)&1)==0 &((PINB>>0)&1)==1 &((PINB>>2)&1)==1){
			PORTA |=(1<<1);
		}
		else if (((PINB>>2)&1)==0 &((PINB>>1)&1)==1 &((PINB>>0)&1)==1){
					PORTA |=(1<<0);
					PORTA |=(1<<1);
				}
		else if (((PINB>>2)&1)==1 &((PINB>>1)&1)==1 &((PINB>>0)&1)==1){
			    PORTA &=~(1<<0);
				PORTA &=~(1<<1);
						}

	}


	return 0;
}






