void initdev(){
  CLKPR=(1<<CLKPCE);
  CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (1<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);
  nrf_init();
  analogReference(INTERNAL);
  ACSR = 0x80;
#ifdef DEBUG
  //UART 9600
    UCSR0A=0x02;
    UCSR0B=0x08;
    UCSR0C=0x06;
    UBRR0H=0x00;
    UBRR0L=0x0C;
    printf_begin();
    radio.printDetails();    
    delay(200);
#endif
  nrfrun();
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);
  sleep();
}
