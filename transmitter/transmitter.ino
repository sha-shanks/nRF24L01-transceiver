//Pinout
//GND       VCC-3.3V
//CE-d9     CSN-D8
//SCK-D13   MOSI-D11
//MISO-D12  IRQ-null
#define CE_pin 9
#define CSN_pin 8

//Libraries required
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//object for RF24
RF24 radio(CE_pin, CSN_pin); //radio(CE,CSN)

//address
const byte address[6] = "100000";

void setup(){
  while(!Serial){
    Serial.begin(9600);
  }

  radio.begin();

  radio.openWritingPipe(address);

  radio.stopListening();
}

void loop(){
  const char text[] = "Hello!";
  radio.write(&text, sizeof(text));

  delay(1000);
}