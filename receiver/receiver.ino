//Pinout
//GND       VCC-3.3V
//CE-d9     CSN-D8
//SCK-D13   MOSI-D11
//MISO-D12  IRQ-null
#define CE_pin 9
#define CSN_pin 8

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(CE_pin, CSN_pin);

const byte address[6] = "100000";

void setup() {
  while(!Serial){
    Serial.begin(9600);
  }

  radio.begin();

  radio.openReadingPipe(0, address);

  radio.startListening();
}

void loop() {
  if(radio.available()){
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
