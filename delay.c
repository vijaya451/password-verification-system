#include<LPC21XX.H>
#include"UART_header.h"
void delay_sec(unsigned int s)
{
	T0PR=15000000-1;
	T0PC=T0TC=0;
	T0TCR=1;
	while(T0TC<s);
	T0TCR=0;
}




