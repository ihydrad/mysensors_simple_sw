#include <Arduino.h>
#include <SPI.h>
#include <avr/sleep.h>
#include <RF24.h>

//#define DEBUG

#ifdef DEBUG
  #include <printf.h>
#endif

#define SBR(port, bit)        port |= (1<<bit)
#define CBR(port, bit)        port &= (~(1<<bit))
#define INV(port, bit)        port ^= (1<<bit)
#define SBRC(port, bit)      ((port & (1<<bit)) == 0)
#define SBRS(port, bit)      ((port & (1<<bit)) != 0)

#define PayloadSize          5
#define Channel              121

uint8_t nrf_data[PayloadSize];

uint8_t         tx_adrr[]="3Node";

RF24            radio(9, 10);

void setup(){
  nrf_data[0]=1;
  initdev();
}

void loop(){
}
