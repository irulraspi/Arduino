int m1 = 8;
int m2 = 9;

int inputPin = 2;
int val = 0;

void setup()
{
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(inputPin, INPUT);
}

void loop()
{
  val = digitalRead(inputPin);
  if (val == HIGH)
  {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    delay(4000);
  }
  else
  {
    
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    //delay(3000);
    //digitalWrite(m1, LOW);
    //digitalWrite(m2, LOW);
    
    
  }

}

