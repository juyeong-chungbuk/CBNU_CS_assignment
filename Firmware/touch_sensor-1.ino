#define TOUCH_SENSOR 10
#define LED_SENSOR 5
#define BAUDRATE 9600

void setup()
{
  pinMode(TOUCH_SENSOR, INPUT);
  pinMode(LED_SENSOR, OUTPUT);
  Serial.begin(BAUDRATE);
  Serial.println("Ready");
}

int prevTouch = 0;
int currTouch = 0;
void loop()
{
  currTouch = digitalRead(TOUCH_SENSOR);
  if (currTouch == HIGH)
  {
    if (prevTouch != currTouch)
    {
      Serial.println("Touched!");
      digitalWrite(LED_SENSOR, HIGH);
      Serial.println("LED ON");
    }
  }
  if (currTouch == LOW)
  {
    if (prevTouch != currTouch)
    {
      Serial.println("NOT Touched!");
      digitalWrite(LED_SENSOR, LOW);
      Serial.println("LED OFF");
    }
  }
  prevTouch = currTouch;
}

//#define TOUCH_SENSOR 10
//#define LED_SENSOR 5
//#define BAUDRATE 9600
//
//void setup() {
//  pinMode(TOUCH_SENSOR, INPUT);
//  pinMode(LED_SENSOR, OUTPUT);
//  Serial.begin(BAUDRATE);
//  Serial.println("Ready");
//}
//
//int Touched;
//void loop() {
//  Touched = digitalRead(TOUCH_SENSOR);
//  if(Touched == HIGH){
//    digitalWrite(LED_SENSOR,HIGH);
//    Serial.println("ON");
//  }
//  if(Touched == LOW){
//    digitalWrite(LED_SENSOR,LOW);
//    Serial.println("OFF");
//    }
//}