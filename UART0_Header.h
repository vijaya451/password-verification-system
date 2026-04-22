extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_string(char *p);
extern void config_vic_for_uart0(void);
extern unsigned int flag;
extern char array[6];


