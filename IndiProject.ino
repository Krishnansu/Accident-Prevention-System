#define ECHO_PIN1 2
#define TRIG_PIN1 3
#define buzzPin1 12
#define LED_Pin1 13
#define ECHO_PIN2 4
#define TRIG_PIN2 5
#define buzzPin2 10
#define LED_Pin2 11


void setup() {
  Serial.begin(9600);
  pinMode(LED_Pin1, OUTPUT);
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(buzzPin1, OUTPUT);
  pinMode(LED_Pin2, OUTPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(buzzPin2, OUTPUT);
}

float readDistanceCM1() {
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);
  unsigned int duration1 = pulseIn(ECHO_PIN1, HIGH);
  return duration1 * 0.034 / 2;
}

float readDistanceCM2() {
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  unsigned int duration2 = pulseIn(ECHO_PIN2, HIGH);
  return duration2 * 0.034 / 2;
}

void loop() {
  float distance1 = readDistanceCM1();
  float distance2 = readDistanceCM2();

  bool isNearby1 = distance1 < 25;
  bool isNearby2 = distance2 < 25;
  
  if(isNearby1)
 { 
  digitalWrite(LED_Pin2, 1);
  tone(buzzPin2, 250, 100);
 }
  else
  {
    digitalWrite(LED_Pin2, 0);
  }
  
  if(isNearby2)
  {
  digitalWrite(LED_Pin1, 1);
  tone(buzzPin1, 250, 100);
  }
  else
  {
    digitalWrite(LED_Pin1, 0);
  }

  Serial.print("Measured distance1: ");
  Serial.println(readDistanceCM1());
  Serial.print("Measured distance2: ");
  Serial.println(readDistanceCM2());

  delay(200);
}
