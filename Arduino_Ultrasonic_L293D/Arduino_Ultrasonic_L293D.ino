//http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
#define trigPin 13
#define echoPin 12
#define m1 8
#define m2 9
#define m3 10
#define m4 11

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  //  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 20 ) {  // This is where the LED On/Off happens
    digitalWrite(m1,LOW); // When the Red condition is met, the Green LED should turn off
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW); // When the Red condition is met, the Green LED should turn off
    digitalWrite(m4,HIGH);
    delay(300);
    digitalWrite(m1,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(m2,LOW);
    digitalWrite(m3,LOW); // When the Red condition is met, the Green LED should turn off
    digitalWrite(m4,HIGH);
    delay(500);
  }
  else {
    digitalWrite(m1,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(m2,LOW);
    digitalWrite(m3,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(m4,LOW);
  }
 /* if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(100); */
}

