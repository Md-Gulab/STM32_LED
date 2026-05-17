
/*
	7 segment LED down counter from 9 to 0
	a  ->PA9,
    b  ->PA8,
	C  ->PB10,
	d  ->PB4
	e  ->PB5,
	f  ->PB3,
	g  ->PA10,
	dp ->PC7
*/

#include "stm32f4xx.h"

void delay( int n ) ;

#define wait 250

int main(){

	// enable peripheral clocks
	RCC->AHB1ENR |= 0X00000001 ; // Enable GPIOA clock
	RCC->AHB1ENR |= 0X00000002 ; // Enable GPIOB clock
	RCC->AHB1ENR |= 0X00000004 ; // Enable GPIOC clock

	// Setting individual pins to output modes via GPIOx-MODER
	GPIOA->MODER &= ~0X000C0000 ; // clear PA9
	GPIOA->MODER |=  0X00040000 ; // PA9 set to output mode

	GPIOA->MODER &= ~0X00030000 ; // clear PA8
	GPIOA->MODER |=  0X00010000 ; // PA8 set to output mode

	GPIOA->MODER &= ~0X00000C00 ; // clear PA5
	GPIOA->MODER |=  0X00000400 ; // PA5 set to output mode

	GPIOB->MODER &= ~0X00300000 ; // clear PB10
	GPIOB->MODER |=  0X00100000 ; // PB10 set to output mode

	GPIOB->MODER &= ~0X00000300 ; // clear PB4
	GPIOB->MODER |=  0X00000100 ; // PB4 set to output mode

	GPIOB->MODER &= ~0X00000C00 ; // clear PB5
	GPIOB->MODER |=  0X00000400 ; // PB5 set to output mode

	GPIOB->MODER &= ~0X000000C0 ; // clear PB3
	GPIOB->MODER |=  0X00000040 ; // PB3set to output mode

	GPIOA->MODER &= ~0X00300000 ; // clear PA10
	GPIOA->MODER |=  0X00100000 ; // PA10 set to output mode

	GPIOC->MODER &= ~0X0000C000 ; // clear PC7
	GPIOC->MODER |=  0X00004000 ; // PC7 set to output mode

	int j ;
	while(1){ // Put inside an infinite loop so it repeats counting down
		for( j = 0 ; j < 10 ; j++ ){

			switch(j){

			case 0 : // For displaying 9
				GPIOA->BSRR = (1 << 9);   // A ON
				GPIOA->BSRR = (1 << 8);   // B ON
				GPIOB->BSRR = (1 << 10);  // C ON
				GPIOB->BSRR = (1 << 4);   // D ON
				GPIOB->BSRR = (1 << 3);   // F ON
				GPIOA->BSRR = (1 << 10);  // G ON
				GPIOA->BSRR = (1 << 5) ; // PA5 ON
				delay(wait) ;
				GPIOA->BSRR = (1 << (9 + 16));   // A OFF
				GPIOA->BSRR = (1 << (8 + 16));   // B OFF
				GPIOB->BSRR = (1 << (10 + 16));  // C OFF
				GPIOB->BSRR = (1 << (4 + 16));   // D OFF
				GPIOB->BSRR = (1 << (3 + 16));   // F OFF
				GPIOA->BSRR = (1 << (10 + 16));  // G OFF
				GPIOA->BSRR = (1 << (5 + 16)) ;  // PA5 OFF
				delay(wait) ;
				break ;

			case 1 : // For displaying 8
				GPIOA->BSRR = (1 << 9); //A
				GPIOA->BSRR = (1 << 8); //B
				GPIOB->BSRR = (1 << 10);//C
				GPIOB->BSRR = (1 << 4); //D
				GPIOB->BSRR = (1 << 5); //E
				GPIOB->BSRR = (1 << 3); //F
				GPIOA->BSRR = (1 << 10);//G
				GPIOA->BSRR = (1 << 5) ; // PA5 ON
				delay(wait) ;
				GPIOA->BSRR = (1 << (9 + 16));
				GPIOA->BSRR = (1 << (8 + 16));
				GPIOB->BSRR = (1 << (10 + 16));
				GPIOB->BSRR = (1 << (4 + 16));
				GPIOB->BSRR = (1 << (5 + 16));
				GPIOB->BSRR = (1 << (3 + 16));
				GPIOA->BSRR = (1 << (10 + 16));
				GPIOA->BSRR = (1 << (5 + 16)) ;
				delay(wait) ;
				break ;

			case 2: // For displaying 7
				GPIOA->BSRR = (1 << 9);
				GPIOA->BSRR = (1 << 8);
				GPIOB->BSRR = (1 << 10);
				GPIOA->BSRR = (1 << 10);
				GPIOA->BSRR = (1 << 5) ;
				delay(wait) ;
				GPIOA->BSRR = (1 << (9 + 16));
				GPIOA->BSRR = (1 << (8 + 16));
				GPIOB->BSRR = (1 << (10 + 16));
				GPIOA->BSRR = (1 << (10 + 16));
				GPIOA->BSRR = (1 << (5 + 16)) ;
				delay(wait) ;
				break ;

			case 3: // For displaying 6
				GPIOA->BSRR = (1 << 9);
				GPIOB->BSRR = (1 << 10);
				GPIOB->BSRR = (1 << 4);
				GPIOB->BSRR = (1 << 5);
				GPIOB->BSRR = (1 << 3);
				GPIOA->BSRR = (1 << 10);
				GPIOA->BSRR = (1 << 5) ;
				delay(wait) ;
				GPIOA->BSRR = (1 << (9 + 16));
				GPIOB->BSRR = (1 << (10 + 16));
				GPIOB->BSRR = (1 << (4 + 16));
				GPIOB->BSRR = (1 << (5 + 16));
				GPIOB->BSRR = (1 << (3 + 16));
				GPIOA->BSRR = (1 << (10 + 16));
				GPIOA->BSRR = (1 << (5 + 16)) ;
				delay(wait) ;
				break ;

			case 4: // For displaying 5
				GPIOA->BSRR = (1 << 9);
				GPIOB->BSRR = (1 << 10);
				GPIOB->BSRR = (1 << 4);
				GPIOB->BSRR = (1 << 3);
				GPIOA->BSRR = (1 << 10);
				GPIOA->BSRR = (1 << 5) ;
				delay(wait) ;
				GPIOA->BSRR = (1 << (9 + 16));
				GPIOB->BSRR = (1 << (10 + 16));
				GPIOB->BSRR = (1 << (4 + 16));
				GPIOB->BSRR = (1 << (3 + 16));
				GPIOA->BSRR = (1 << (10 + 16));
				GPIOA->BSRR = (1 << (5 + 16)) ;
				delay(wait) ;
				break ;

			case 5: // For displaying 4
				GPIOA->BSRR = (1 << 8);
				GPIOB->BSRR = (1 << 10);
				GPIOB->BSRR = (1 << 3);
				GPIOA->BSRR = (1 << 10);
				GPIOA->BSRR = (1 << 5) ;
				delay(wait) ;
				GPIOA->BSRR = (1 << (8 + 16));
				GPIOB->BSRR = (1 << (10 + 16));
				GPIOB->BSRR = (1 << (3 + 16));
				GPIOA->BSRR = (1 << (10 + 16));
				GPIOA->BSRR = (1 << (5 + 16)) ;
				delay(wait) ;
				break ;

			case 6: // For displaying 3
				GPIOA->BSRR = (1 << 9);
				GPIOA->BSRR = (1 << 8);
				GPIOB->BSRR = (1 << 10);
				GPIOB->BSRR = (1 << 4);
				GPIOA->BSRR = (1 << 10);
				GPIOA->BSRR = (1 << 5) ;
				delay(wait) ;
				GPIOA->BSRR = (1 << (9 + 16));
				GPIOA->BSRR = (1 << (8 + 16));
				GPIOB->BSRR = (1 << (10 + 16));
				GPIOB->BSRR = (1 << (4 + 16));
				GPIOA->BSRR = (1 << (10 + 16));
				GPIOA->BSRR = (1 << (5 + 16)) ;
				delay(wait) ;
				break ;

			case 7: // For displaying 2
				GPIOA->BSRR = (1 << 9);
				GPIOA->BSRR = (1 << 8);
				GPIOB->BSRR = (1 << 4);
				GPIOB->BSRR = (1 << 5);
				GPIOA->BSRR = (1 << 10);
				GPIOA->BSRR = (1 << 5) ;
				delay(wait) ;
				GPIOA->BSRR = (1 << (9 + 16));
				GPIOA->BSRR = (1 << (8 + 16));
				GPIOB->BSRR = (1 << (4 + 16));
				GPIOB->BSRR = (1 << (5 + 16));
				GPIOA->BSRR = (1 << (10 + 16));
				GPIOA->BSRR = (1 << (5 + 16)) ;
				delay(wait) ;
				break ;

			case 8: // For displaying 1
				GPIOA->BSRR = (1 << 8);
				GPIOB->BSRR = (1 << 10);
				GPIOA->BSRR = (1 << 5) ;
				delay(wait) ;
				GPIOA->BSRR = (1 << (8 + 16));
				GPIOB->BSRR = (1 << (10 + 16));
				GPIOA->BSRR = (1 << (5 + 16)) ;
				delay(wait) ;
				break ;

			case 9: // For displaying 0
				GPIOA->BSRR = (1 << 9);
				GPIOA->BSRR = (1 << 8);
				GPIOB->BSRR = (1 << 10);
				GPIOB->BSRR = (1 << 4);
				GPIOB->BSRR = (1 << 5);
				GPIOB->BSRR = (1 << 3);
				GPIOA->BSRR = (1 << 5) ;
				delay(wait) ;
				GPIOA->BSRR = (1 << (9 + 16));
				GPIOA->BSRR = (1 << (8 + 16));
				GPIOB->BSRR = (1 << (10 + 16));
				GPIOB->BSRR = (1 << (4 + 16));
				GPIOB->BSRR = (1 << (5 + 16));
				GPIOB->BSRR = (1 << (3 + 16));
				GPIOA->BSRR = (1 << (5 + 16)) ;
				delay(wait) ;
				break ;
			}
		}
	}
}

void delay( int n ){
	int i ;
	for( ; n>0 ; n--)
		for( i=0 ; i<3195 ; i++) ;
	return ;
}
