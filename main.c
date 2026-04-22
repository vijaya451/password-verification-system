#include<LPC21XX.H>
#include<string.h>
#include"UART_header.h"
char array[6];
unsigned int flag;
char s[]="abcde";
int main()
{
	uart0_init(9600);
	config_vic_for_uart0();
	uart0_string("enter password : ");
	while(1)
	{
		if(flag==1){
			uart0_string("\r\n");
			if(strcmp(s,array)==0)
				uart0_string("password correct..door opened\r\n");
			else
				uart0_string("wrong password..try again\r\n");
			uart0_string("\r\n");
			flag=0;
			uart0_string("enter password : ");
		}
	}
}





