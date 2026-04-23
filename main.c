#include<LPC21XX.H>
#include<string.h>
#include"UART_header.h"
char array[6];
unsigned int flag;
char s[]="abcde";
int main()
{
	int c=0,i;
	uart0_init(9600);
	config_vic_for_uart0();
	uart0_string("enter password : ");
	while(1)
	{
		if(flag==1){
			uart0_string("\r\n");
			if(strcmp(s,array)==0)
				uart0_string("password correct..door opened\r\n");
			else{
				uart0_string("wrong password..try again\r\n");
				c++;
				if(c==3){
					uart0_string("locked..wait\r\n");
					for(i=3;i>0;i--){
						uart0_string("Time left : ");
						uart0_int(i);
						uart0_string(" sec\r");
						delay_sec(1);
					}
					c=0;
				}
			}
			uart0_string("\r\n");
			flag=0;
			uart0_string("enter password : ");
		}
	}
}





