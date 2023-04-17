
typedef unsigned char u8;
#include <util/delay.h>
#include <stdint.h>
#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x3A)
int main (void){
while(1){
	int i,x=0;
for(i=0;i<7;i++){
	//set pin Ax out
	DDRA|=(1<<x);
	//set pin Ax high
	PORTA |=(1<<x);
	_delay_ms(500);
	x++;
}
x=0;
	for(i=0;i<7;i++){
		//set pin Ax low
		PORTA &=~(1<<x);
		_delay_ms(500);
		x++;
	}
}
return 0;
}



