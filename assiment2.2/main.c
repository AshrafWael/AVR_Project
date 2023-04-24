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
	DDRA &=~(1<<0); // all this pines is input
	DDRA &=~(1<<1);

	PORTA |=(1<<0); //all this pin is 1 to activate puul up reg
	PORTA |=(1<<1);

	u8 segCTHD []={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	DDRB=0xff;
	PORTB =0X00;
	u8 sw1 ,sw2,counter =0;
	while(1){
		sw1 =((PINA>>0)&1);
		sw2 =((PINA>>1)&1);
		 if (sw1 ==0 ){
			 while(((PINA>>0)&1)==0);
			 if(counter <9){
			 counter++;
			 }
			 //while(((PINA>>0)&1)==0);
			// while(counter>9);
		 }
		 if (sw2 ==0  ){
			 while(((PINA>>1)&1)==0);
			 if (counter >0){
				 counter--;
			 }
				 //while(counter==0);
			 }
		 PORTB =segCTHD [counter];
		}
		return 0;
		}




	/*
		while(1)
			sw1 =((PINA>>0)&1);
			sw2 =((PINA>>1)&1);
{
		 if (sw1 ==0 )
		 {
			 _delay_ms(10);
			 if (sw1 ==0 )
			 		 {
				 if(counter<=9)
				         {
					 counter++;
			 		      }
			 		  }
		   }
		 if (sw2 ==0 )
				 {
			 _delay_ms(10);
					 if (sw2 ==0 )
					 		 {
						 if(counter>=0)
						         {
							 counter--;
					 		      }
					 		  }
				   }
		 PORTB =segCTHD [counter];
}
		 return 0;
}

*/


				 /*
			 		 }
			 counter++;//5
			 while(((PINA>>0)&1)==0);

			// while(counter==9);//x
		 }
		 else if (sw2 ==0 )
		 { //x  yes
				 counter--;
			//	 while(counter==0);// x
	      }
		 PORTB =segCTHD [counter];
        }
      return 0;
}
*/
	/*
	while(1)
	{
			sw1 =((PINA>>0)&1);
			sw2 =((PINA>>1)&1);
			for(counter=0;counter<=9;counter++){
						if (sw1 ==0 )
						{
							PORTB =segCTHD [counter];
							 while(sw1==0);
						}

						for(counter2=counter;counter2>=0;counter2--){
							if (sw2 ==0 )
						{
							PORTB =segCTHD [counter];
							 while(sw1==0);
						}
						   	   	   	   	   	   	   	   	   }
												}
	}
*/





	/*
	while(1){
		sw1 =((PINA>>0)&1);
		sw2 =((PINA>>1)&1);
		for(counter=0;counter<=9;counter++){
			if (sw1 ==0 ){
				PORTB =segCTHD [counter];
				 while(sw1==0);
			}
			else if(sw2 ==0){
				counter--;
				PORTB =segCTHD [counter];
				 while(sw2==0);
			}
		}
	}

*/











