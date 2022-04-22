#include "headers.h"
#include <Arduino.h>

void HARDWARE::frontLeftMotorFORWARD(void){
  digitalWrite(FRONT_LEFT_MOTOR_PIN_2, LOW);
  digitalWrite(FRONT_LEFT_MOTOR_PIN_1, HIGH);
}
////////////////////////////////////////////

void HARDWARE::frontLeftMotorOFF(void){
  digitalWrite(FRONT_LEFT_MOTOR_PIN_1, LOW);
  digitalWrite(FRONT_LEFT_MOTOR_PIN_2, LOW);
}
////////////////////////////////////////////

void HARDWARE::frontLeftMotorBACKWARD(void){
  digitalWrite(FRONT_LEFT_MOTOR_PIN_1, LOW);
  digitalWrite(FRONT_LEFT_MOTOR_PIN_2, HIGH);
}
/////////////////////////////////////////////

void HARDWARE::frontRightMotorFORWARD(void){
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_4, LOW);
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_3, HIGH);
}
///////////////////////////////////////////////

void HARDWARE::frontRightMotorOFF(void){
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_3, LOW);
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_4, LOW);
}
///////////////////////////////////////////////

void HARDWARE::frontRightMotorBACKWARD(void){
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_3, LOW);
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_4, HIGH);
}
////////////////////////////////////////////////

void HARDWARE::rearLeftMotorFORWARD(void){
  digitalWrite(REAR_LEFT_MOTOR_PIN_2, LOW);
  digitalWrite(REAR_LEFT_MOTOR_PIN_1, HIGH);  
}
/////////////////////////////////////////////////

void HARDWARE::rearLeftMotorOFF(void){
  digitalWrite(REAR_LEFT_MOTOR_PIN_1, LOW);
  digitalWrite(REAR_LEFT_MOTOR_PIN_2, LOW);
}
/////////////////////////////////////////////////

void HARDWARE::rearLeftMotorBACKWARD(void){
  digitalWrite(REAR_LEFT_MOTOR_PIN_1, LOW);
  digitalWrite(REAR_LEFT_MOTOR_PIN_2, HIGH);
}
/////////////////////////////////////////////////

void HARDWARE::rearRightMotorFORWARD(void){
  digitalWrite(REAR_RIGHT_MOTOR_PIN_3, HIGH);
  digitalWrite(REAR_RIGHT_MOTOR_PIN_4, LOW);
}
/////////////////////////////////////////////////

void HARDWARE::rearRightMotorOFF(void){
  digitalWrite(REAR_RIGHT_MOTOR_PIN_3, LOW);
  digitalWrite(REAR_RIGHT_MOTOR_PIN_4, LOW);
}
///////////////////////////////////////////////////

void HARDWARE::rearRightMotorBACKWARD(void){
  digitalWrite(REAR_RIGHT_MOTOR_PIN_3, LOW);
  digitalWrite(REAR_RIGHT_MOTOR_PIN_4, HIGH);
}
///////////////////////////////////////////////////
