// Blink for Canzasi-Prot(ATtiny841)
// with https://github.com/SpenceKonde/ATTinyCore
// 
// License CC by 4.0 2016 D.F.Mac.
//
//                   +----+
//                VCC|    |GND
// LED    PB0/A11/ D0|    |D10/A0 /PA0
//        PB1/A10/ D1|    |D9 /A1 /PA1
//        PB3/ A9/D11|    |D8 /A2 /PA2
//        PB2/ A8/ D2|    |D7 /A3 /PA3
//        PA7/ A7/ D3|    |D6 /A4 /PA4
//        PA6/ A6/ D4|    |D5 /A5 /PA5
//                   +----+
//
#include "i2c841s2.h"

#define LED_PIN 0 // PB0

uint8_t errorFlg = false;

void onI2CWrite(volatile uint8_t *pbuf, uint8_t size){
  if(size == 1){
    if(*pbuf == 1){
      digitalWrite(LED_PIN,HIGH);
    }else{
      digitalWrite(LED_PIN,LOW);
    }
  }else{
    errorFlg = true;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN,OUTPUT);
  i2cs.setOnWriteReq(onI2CWrite);
  i2cs.init(0x30);            
}

void loop() {
  if(errorFlg){
    digitalWrite(LED_PIN,HIGH);
    delay(100);
    digitalWrite(LED_PIN,LOW);
    delay(100);
  }
}
