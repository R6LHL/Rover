#include "headers.h"

#ifdef Ultrasonic_h
  Ultrasonic rangeSensor(RANGE_SENSOR_TRIGGER_PIN, RANGE_SENSOR_ECHO_PIN);
#endif //Ultrasonic_h

Servo rangeSensorArm;

volatile unsigned int rangeForward;
volatile unsigned int rangeLeft;
volatile unsigned int rangeRight;

///////////////////////////////////////////////////
ISR(TIMER2_OVF_vect){
  TaskManager::TimerTaskService_();
}
////////////////////////////////////////////////////


///////////////////////////////////////////////////
void setup() {
  noInterrupts();
  
  #ifdef DEBUG
    Serial.begin(9600);
  #endif
  
  TCCR2B |= (1<<CS22);    // (clk/64)
  TIMSK2 |= (1<<TOIE2);   // ovf interrupt enabled

  //RANGE SENSOR PINS
  pinMode(RANGE_SENSOR_TRIGGER_PIN, OUTPUT);
  digitalWrite(RANGE_SENSOR_TRIGGER_PIN, LOW);
  pinMode(RANGE_SENSOR_ECHO_PIN, INPUT);
  
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
  
  TaskManager::SetTask_(CHASSIS_stop,0); //LOGIC ENTER POINT
//
  //TESTING MOTORS
  //TESTING FRONT LEFT
  HARDWARE_frontLeftMotorFORWARD();
  delay(1000);
  HARDWARE_frontLeftMotorOFF();
  delay(1000);

  //TESTING REAR LEFT
  HARDWARE_rearLeftMotorBACKWARD();
  delay(1000);
  HARDWARE_rearLeftMotorOFF();
  delay(1000);
  
  //TESTING FRONT RIGHT
  HARDWARE_frontRightMotorFORWARD();
  delay(1000);
  HARDWARE_frontRightMotorOFF();
  delay(1000);

  //TESTING REAR RIGHT
  HARDWARE_rearRightMotorBACKWARD();
  delay(1000);
  HARDWARE_rearRightMotorOFF();
  delay(1000);
  
  interrupts();
}
/////////////////////////////////////////////////
void loop() {TaskManager::ProcessTaskQueue_();}
/////////////////////////////////////////////////
