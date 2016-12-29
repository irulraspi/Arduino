int m1 = 13;
int m2 = 12;
int m3 = 11;
int m4 = 10;
int data;

void setup()
{
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  
  if(Serial.available() > 0)
  {
    data = Serial.read();
  }
  
  if(data == '1')
  {
    maju();
  }
  else if(data == '2')
  {
    kanan();
  }
  else if(data == '3')
  {
    mundur();
  }
  else if(data == '4')
  {
    kiri();
  }
  else
  {
    berhenti();
  }                                  
}

void maju()
{
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void mundur()
{
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}

void kiri()
{
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void kanan()
{
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}

void berhenti()
{ 
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
