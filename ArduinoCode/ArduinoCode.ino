/**
  Car Controller
  
  Author: Juan Manuel Young Hoyos.
*/
#include <SoftwareSerial.h>

// You can change the pins
#define BLUETOOTH_TX 50
#define BLUETOOTH_TD 51

#define MOTOR_1_A 22
#define MOTOR_1_B 23
#define MOTOR_1_PWM 24

#define MOTOR_2_A 27
#define MOTOR_2_B 28
#define MOTOR_2_PWM 29

const int state_0 = 0;
const int state_1 = 1;
const int state_2 = 2;
const int state_3 = 3;
const int state_4 = 4;

long int data;
SoftwareSerial Blue(BLUETOOTH_TX, BLUETOOTH_TD);

void stopCar() {
  Serial.println("Stopping...");
}

void accelerate() {
  Serial.println("Accelerating car");
}

void reverse() {
  Serial.println("Reversing");
}

void turnRight() {
  Serial.println("Turning Right");
}

void turnLeft() {
  Serial.println("Turning Left");
}

void setup() {

  pinMode(MOTOR_1_A, OUTPUT);
  pinMode(MOTOR_1_B, OUTPUT);
  pinMode(MOTOR_1_PWM, OUTPUT);
  
  pinMode(MOTOR_2_A, OUTPUT);
  pinMode(MOTOR_2_B, OUTPUT);
  pinMode(MOTOR_2_PWM, OUTPUT);
  
  stopCar();
  Serial.begin(9600);
  Blue.begin(9600);
}

void loop() {
  while (Blue.available() == 0);

  if (Blue.available() > 0)
    data = Blue.parseInt();
  
  switch(data) {
    case state_0:
      stopCar();
      break;
    case state_1:
      accelerate();
      break;
    case state_2:
      reverse();
      break;
    case state_3:
      turnRight();
      break;
    case state_4:
      turnLeft();
      break;
    default:
      stopCar();
      break;  
  }
}