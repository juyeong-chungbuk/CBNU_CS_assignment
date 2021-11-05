#include <TimerOne.h>
#define LED 2
volatile uint8_t tSec = 0;
volatile long tPeriod = 100000;
int led = 1;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Timer1.initialize(tPeriod); // 1sec
  Timer1.attachInterrupt(OneSec);  // ISR
}

void OneSec()
{
  tSec = tSec + 1;
  if(tSec == 3){
    led = 0;
  }
  else if(tSec == 10){
    led = 1;
    tSec = 0;
  }

}

void loop(){
  if(led == 1){   
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
}
