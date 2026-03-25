#define TRIG_PIN 2
#define ECHO_PIN 3
#define VIB_PIN 8

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(VIB_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  long duration;
  int distance;

  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  
  duration = pulseIn(ECHO_PIN, HIGH);

  
  distance = duration * 0.034 / 2;

  
  Serial.print("Distance: ");
  Serial.print(distance);   
  Serial.println(" cm");

  
  if(distance > 0 && distance <= 30) {
    digitalWrite(VIB_PIN, HIGH);
  } 
  else {
    digitalWrite(VIB_PIN, LOW);
  }

  delay(200);
}