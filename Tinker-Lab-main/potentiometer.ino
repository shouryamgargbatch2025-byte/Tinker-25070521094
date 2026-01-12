// C++ code
// Potentiometer using Arduino UNO R3
int Buzzer = 13;
int P = A0;
int pv = 0;
int Sound = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop()
{ 
  pv = analogRead(P);
  Serial.println(pv);
  Sound = pv/6;
  analogWrite(Buzzer, Sound);
  digitalWrite(Buzzer, HIGH);
}