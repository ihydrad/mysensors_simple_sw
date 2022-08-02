void sleep(){
  radio.powerDown();
  sleep_enable();
  ADCSRA = 0;
  DDRB = 0XFF;
  DDRD = 0XFF;
  DDRC = 0XFF; // SDA, SCL HARD PULLED UP to VCC, set pin to HI-Z
  PORTB  = 0x00;
  PORTD  = 0x00;
  PORTC  = 0x30;// SDA, SCL HARD PULLED UP to VCC
  // turn off brown-out enable in software
  MCUCR = bit (6) | bit (5);
  MCUCR = bit (6);
  sleep_cpu ();
}
