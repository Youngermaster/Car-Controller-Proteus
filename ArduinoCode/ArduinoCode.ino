#define SERVO 27

void setup()
{
  pinMode(SERVO, OUTPUT);
}

void loop()
{
  digitalWrite(SERVO, HIGH);
  delayMicroseconds(1500); // Wait for 1000 millisecond(s)
  digitalWrite(SERVO, LOW);
  delay(20); // Wait for 1000 millisecond(s)
}f
