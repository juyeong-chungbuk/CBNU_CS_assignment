#define CDS 0
#define LED 5

unsigned long previousMillis = 0; // will store last time LED was updated
const long interval = 1000; // interval at which to blink (milliseconds)
int time = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis; // save the last time you blinked the LED
    Serial.print(time++); Serial.println("초");
    int val = analogRead(CDS);
    Serial.println(255-(val/4));
    analogWrite(LED, 255-(val/4));
  }
}
