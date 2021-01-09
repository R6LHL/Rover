#include "headers.h"

#ifdef Ultrasonic_h
  Ultrasonic rangeSensorFront(FRONT_RANGE_SENSOR_TRIGGER_PIN, FRONT_RANGE_SENSOR_ECHO_PIN);
  Ultrasonic rangeSensorBack (BACK_RANGE_SENSOR_TRIGGER_PIN, BACK_RANGE_SENSOR_ECHO_PIN);
#endif //Ultrasonic_h

Servo rangeSensorArm;

volatile unsigned int rangeForward;
volatile unsigned int rangeLeft;
volatile unsigned int rangeRight;
volatile unsigned int rangeBackward;

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
  HARDWARE_frontLeftMotorFORWARD();
  delay(500);
  HARDWARE_frontLeftMotorOFF();
  delay(500);

  //TESTING REAR LEFT
  HARDWARE_rearLeftMotorBACKWARD();
  delay(500);
  HARDWARE_rearLeftMotorOFF();
  delay(500);
  
  //TESTING FRONT RIGHT
  HARDWARE_frontRightMotorFORWARD();
  delay(500);
  HARDWARE_frontRightMotorOFF();
  delay(500);

  //TESTING REAR RIGHT
  HARDWARE_rearRightMotorBACKWARD();
  delay(500);
  HARDWARE_rearRightMotorOFF();
  delay(500);

  TaskManager::SetTask_(ARMS_rangeSensorForward,0); //LOGIC ENTER POINT
}
/////////////////////////////////////////////////
void loop() {TaskManager::ProcessTaskQueue_();}
/////////////////////////////////////////////////
