#include <SimpleTimer.h>
#define CDS 0
#define LED 5

SimpleTimer Timer;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Timer.setInterval(1000);
}

void loop() {
  
  if(Timer.isReady()){
    Serial.println("Called  every 1 sec");
    int val = analogRead(CDS);
    Serial.println(255-(val/4));
    analogWrite(LED, 255-(val/4));
    Timer.reset();
  }
}
