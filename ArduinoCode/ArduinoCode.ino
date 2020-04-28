#include <Servo.h>
#define OUT_1 11
#define OUT_2 10
#define OUT_3 9
#define OUT_4 6

Servo myservo;
int pos = 93; //93 es el numero en el cual servo está en cero grados
int state = 0;
int motorSpeed = 150;
bool isAccelerating = false;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(29);
  pinMode(OUT_1, OUTPUT);
  pinMode(OUT_2, OUTPUT);
  pinMode(OUT_3, OUTPUT);
  pinMode(OUT_4, OUTPUT);
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
    case 'O':
      motorSpeed -= 10;
      if (motorSpeed < 0)
        motorSpeed = 0;

      if (isAccelerating)
        accelerate();
      else
        reverse();
      break;
    case 'P':
      motorSpeed += 10;
      if (motorSpeed > 255)
        motorSpeed = 255;
      if (isAccelerating)
        accelerate();
      else
        reverse();
      break;
    default:
      break;
  }
  state = 0;
}

void accelerate() {
  analogWrite(OUT_1, motorSpeed);
  digitalWrite(OUT_2, LOW);
  digitalWrite(OUT_3, LOW);
  analogWrite(OUT_4, motorSpeed);
  isAccelerating = true;
}

void reverse() {
  digitalWrite(OUT_1, LOW);
  analogWrite(OUT_2, motorSpeed);

  //Doy energia al servo motor
  digitalWrite(OUT_3, LOW);
  analogWrite(OUT_4, motorSpeed);
  isAccelerating = false;
}

void stop() {
  digitalWrite(OUT_1, LOW);
  digitalWrite(OUT_2, LOW);
  digitalWrite(OUT_3, LOW);
  digitalWrite(OUT_4, LOW);
  isAccelerating = false;
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
