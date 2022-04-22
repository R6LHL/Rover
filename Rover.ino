#include "headers.h"

TaskManager5 OS;

Ultrasonic rangeSensorFront(FRONT_RANGE_SENSOR_TRIGGER_PIN, FRONT_RANGE_SENSOR_ECHO_PIN);
Ultrasonic rangeSensorBack(BACK_RANGE_SENSOR_TRIGGER_PIN, BACK_RANGE_SENSOR_ECHO_PIN);

Servo rangeSensorArm;

volatile unsigned int rangeForward = 0;
volatile unsigned int rangeLeft = 0;
volatile unsigned int rangeRight = 0;
volatile unsigned int rangeBackward = 0;


#include "interrupts.h"


///////////////////////////////////////////////////

void setup() {
  noInterrupts();
  
  #ifdef DEBUG
    Serial.begin(9600);
  #endif
  
  TCCR2B |= (1<<CS22);    // (clk/64)
  TIMSK2 |= (1<<TOIE2);   // ovf interrupt enabled
/*
  PCICR |= (1<<PCIE2);   //SONIC ECHO INTERRUPT
  PCMSK2 |= (1<<PCINT23);
*/
  interrupts();
  
  //FRONT RANGE SENSOR PINS
  pinMode(FRONT_RANGE_SENSOR_TRIGGER_PIN, OUTPUT);
  digitalWrite(FRONT_RANGE_SENSOR_TRIGGER_PIN, LOW);
  pinMode(FRONT_RANGE_SENSOR_ECHO_PIN, INPUT);
  
  //BACK RANGE SENSOR PINS
  pinMode(BACK_RANGE_SENSOR_TRIGGER_PIN, OUTPUT);
  digitalWrite(BACK_RANGE_SENSOR_TRIGGER_PIN, LOW);
  pinMode(BACK_RANGE_SENSOR_ECHO_PIN, INPUT);
  
  //RANGE SENSOR ARM PINS    
  pinMode(RANGE_SENSOR_ARM_PIN, OUTPUT);
  digitalWrite(RANGE_SENSOR_ARM_PIN, LOW);
  
  //CHASSIS MOTORS PINS
  pinMode(FRONT_LEFT_MOTOR_PIN_1, OUTPUT);
  digitalWrite(FRONT_LEFT_MOTOR_PIN_1, LOW);
  pinMode(FRONT_LEFT_MOTOR_PIN_2, OUTPUT);
  digitalWrite(FRONT_LEFT_MOTOR_PIN_2, LOW);
  
  pinMode(FRONT_RIGHT_MOTOR_PIN_3, OUTPUT);
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_3, LOW);
  pinMode(FRONT_RIGHT_MOTOR_PIN_4, OUTPUT);
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_4, LOW);
  
  pinMode(REAR_LEFT_MOTOR_PIN_1, OUTPUT);
  digitalWrite(REAR_LEFT_MOTOR_PIN_1, LOW);
  pinMode(REAR_LEFT_MOTOR_PIN_2, OUTPUT);
  digitalWrite(REAR_LEFT_MOTOR_PIN_2, LOW);
  
  pinMode(REAR_RIGHT_MOTOR_PIN_3, OUTPUT);
  digitalWrite(REAR_RIGHT_MOTOR_PIN_3, LOW);
  pinMode(REAR_RIGHT_MOTOR_PIN_4, OUTPUT);
  digitalWrite(REAR_RIGHT_MOTOR_PIN_4, LOW);
  
  rangeSensorArm.attach(RANGE_SENSOR_ARM_PIN);
  

//
  //TESTING MOTORS
  //TESTING FRONT LEFT
  HARDWARE::frontLeftMotorFORWARD();
  delay(500);
  HARDWARE::frontLeftMotorOFF();
  delay(500);

  //TESTING REAR LEFT
  HARDWARE::rearLeftMotorBACKWARD();
  delay(500);
  HARDWARE::rearLeftMotorOFF();
  delay(500);
  
  //TESTING FRONT RIGHT
  HARDWARE::frontRightMotorFORWARD();
  delay(500);
  HARDWARE::frontRightMotorOFF();
  delay(500);

  //TESTING REAR RIGHT
  HARDWARE::rearRightMotorBACKWARD();
  delay(500);
  HARDWARE::rearRightMotorOFF();
  delay(500);

  OS.SetTask_(ARMS::rangeSensorForward,0); //LOGIC ENTER POINT
}
/////////////////////////////////////////////////
void loop() {OS.ProcessTaskQueue_();}
/////////////////////////////////////////////////
