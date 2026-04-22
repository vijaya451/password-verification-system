#include<LPC21XX.H>
#include"UART_header.h"
#define THRE (U0LSR & (1<<5))
#define RDR (U0LSR&1)
void uart0_init(unsigned int baud)
{
	int pclk,result;
	int a[]={15,60,30,0,15};
	pclk=a[VPBDIV]*1000000;
	result=pclk/(16*baud);
	PINSEL0|=0X5;
	U0LCR=0X83;
	U0DLL=result&0XFF;
	U0DLM=(result>>8)&0XFF;
	U0LCR=0X3;
}
void uart0_tx(unsigned char data)
{
	while(THRE==0);
	U0THR=data;
}
unsigned char uart0_rx(void)
{
	while(RDR==0);
	return U0RBR;
}
void uart0_string(char *p)
{
	while(*p){
		uart0_tx(*p);
		p++;
	}
}




