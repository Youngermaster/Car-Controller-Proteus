#include <Servo.h>
#define out1 22
#define out2 23
#define out3 25
#define out4 27

Servo myservo;
int pos = 93; //93 es el numero en el cual servo está en cero grados
int state = 0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(29);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
    state = Serial.read();
  
  switch (state) {
    case 'A':
      stop();
      accelerate();
      break;
    case 'B':
      stop();
      reverse();
      break;
    case 'L':
      turnLeft();
      delay(100);
      break;
    case 'R':
      turnRight();
      delay(100);
      break;
    case 'S':
      stop();
      break;
    default:
      break;
  }
  state = 0;
}

void accelerate() {
  digitalWrite(out1, HIGH);
  digitalWrite(out2, LOW);
  digitalWrite(out3, LOW);
  digitalWrite(out4, HIGH);
}

void reverse() {
  digitalWrite(out1, LOW);
  digitalWrite(out2, HIGH);

  //Doy energia al servo motor
  digitalWrite(out3, LOW);
  digitalWrite(out4, HIGH);
}

void stop() {
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
  digitalWrite(out3, LOW);
  digitalWrite(out4, LOW);
}

void turnRight() {
  for (pos; pos <= 117; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
}

void turnLeft() {
  for (pos; pos >= 68; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}
