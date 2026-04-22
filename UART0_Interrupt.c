#include<LPC21XX.H>
#include"UART_header.h"
extern unsigned int flag;
extern char array[6];
void UART0_handler(void)__irq
{
	static unsigned int i=0;
	int v=U0IIR;
	if((v&0x0E)==4){
		char ch=U0RBR;
		array[i]=ch;
		if (ch == '\r')
        {
            array[i] = '\0';  
            flag = 1;
            i = 0;
        }
        else
        {
            if (i < 5)  
            {
                array[i] = ch;
                uart0_tx(ch);  
                i++;
            }
        }
	}
	VICVectAddr=0;
}
void config_vic_for_uart0(void)
{
	VICIntSelect=0;
	VICVectCntl0=6|(1<<5);
	VICVectAddr0=(unsigned int)UART0_handler;
	VICIntEnable=(1<<6);
	U0IER=1;
}




