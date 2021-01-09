#ifndef _TASKS_H
#define _TASKS_H

void SENSORS_searchObstaclesForward(void);
void SENSORS_searchObstaclesLeft(void);
void SENSORS_searchObstaclesRight(void);
void SENSORS_searchObstaclesBackward(void);

void ARMS_rangeSensorLeft(void);
void ARMS_rangeSensorRight(void);
void ARMS_rangeSensorForward(void);

void CHASSIS_moveForward(void);
void CHASSIS_moveBackward(void);
void CHASSIS_stop(void);
void CHASSIS_turnLeft(void);
void CHASSIS_turnRight(void);

void SYSTEM_chooseDirection(void);
void SYSTEM_check_Forward(void);

void HARDWARE_frontLeftMotorFORWARD(void);
void HARDWARE_frontLeftMotorOFF(void);
void HARDWARE_frontLeftMotorBACKWARD(void);
void HARDWARE_frontRightMotorFORWARD(void);
void HARDWARE_frontRightMotorOFF(void);
void HARDWARE_frontRightMotorBACKWARD(void);
void HARDWARE_rearLeftMotorFORWARD(void);
void HARDWARE_rearLeftMotorOFF(void);
void HARDWARE_rearLeftMotorBACKWARD(void);
void HARDWARE_rearRightMotorFORWARD(void);
void HARDWARE_rearRightMotorOFF(void);
void HARDWARE_rearRightMotorBACKWARD(void);

extern volatile unsigned int rangeForward;
extern volatile unsigned int rangeLeft;
extern volatile unsigned int rangeRight;
extern volatile unsigned int rangeBackward;
extern Ultrasonic rangeSensorFront;
extern Ultrasonic rangeSensorBack;
extern Servo rangeSensorArm;

/////////////////////////////////////////////////////////////////////
void ARMS_rangeSensorForward(void){

  rangeSensorArm.write(RANGE_SENSOR_ARM_CENTER);
   TaskManager::SetTask_(SENSORS_searchObstaclesForward, SERVO_HALF_MOVE_DELAY_MS);
}
/////////////////////////////////////////////////////////////
void SENSORS_searchObstaclesForward(void){

  rangeForward = rangeSensorFront.read();
  TaskManager::SetTask_(SYSTEM_check_Forward,MEASURE_DELAY_MS);
}
/////////////////////////////////////////////////////////////
void SYSTEM_check_Forward(void){

  if (rangeForward < MINIMUM_RANGE_CM){
    TaskManager::SetTask_(CHASSIS_stop,0);
    TaskManager::SetTask_(ARMS_rangeSensorLeft,0);
  }
  else {TaskManager::SetTask_(CHASSIS_moveForward,0);}
}
/////////////////////////////////////////////////////////////////////////
void CHASSIS_stop(void){

  HARDWARE_frontLeftMotorOFF();
  HARDWARE_frontRightMotorOFF();
  HARDWARE_rearLeftMotorOFF();
  HARDWARE_rearRightMotorOFF();
}
//////////////////////////////////////////////////////////////
void ARMS_rangeSensorLeft(void){

  rangeSensorArm.write(RANGE_SENSOR_ARM_LEFT);

  TaskManager::SetTask_(SENSORS_searchObstaclesLeft,SERVO_MOVE_DELAY_MS);
}
/////////////////////////////////////////////////////////////
void SENSORS_searchObstaclesLeft(void){

  rangeLeft = rangeSensorFront.read();
  TaskManager::SetTask_(ARMS_rangeSensorRight,MEASURE_DELAY_MS);
}
//////////////////////////////////////////////////////////////

void ARMS_rangeSensorRight(void){

  rangeSensorArm.write(RANGE_SENSOR_ARM_RIGHT);
  
  TaskManager::SetTask_(SENSORS_searchObstaclesRight, SERVO_MOVE_DELAY_MS);
}
/////////////////////////////////////////////////////////////
void SENSORS_searchObstaclesRight(void){

  rangeRight = rangeSensorFront.read();
  rangeSensorArm.write(RANGE_SENSOR_ARM_CENTER);
  
  TaskManager::SetTask_(SYSTEM_chooseDirection, 0);
}
/////////////////////////////////////////////////////////////////////
void SENSORS_searchObstaclesBackward(void){
  rangeBackward = rangeSensorBack.read();

  TaskManager::SetTask_(CHASSIS_stop,MOVE_BACKWARD_TIME_MS);
  TaskManager::SetTask_(ARMS_rangeSensorForward,0);
}
//////////////////////////////////////////////////////////////
void SYSTEM_chooseDirection(void){
  
  #ifdef DEBUG
    Serial.print(F("F:"));
    Serial.println(rangeForward, DEC);
    Serial.print(F("L:"));
    Serial.println(rangeLeft, DEC);
    Serial.print(F("R:"));
    Serial.println(rangeRight, DEC);
    Serial.print(F("B:"));
    Serial.println(rangeRight, DEC);
  #endif
    
  if ((rangeLeft > rangeRight) && (rangeLeft > MINIMUM_RANGE_CM)){ // if left range is max
        
  TaskManager::SetTask_(CHASSIS_turnLeft,0);     
  }
  
  else if ((rangeRight > rangeLeft) && (rangeRight > MINIMUM_RANGE_CM)){ // if right range is max
       
  TaskManager::SetTask_(CHASSIS_turnRight,0);
  }
    
  else TaskManager::SetTask_(CHASSIS_moveBackward,0);
}
//////////////////////////////////////////////////////////////////

void CHASSIS_moveForward(){

  HARDWARE_frontLeftMotorFORWARD();
  HARDWARE_frontRightMotorFORWARD();
  HARDWARE_rearLeftMotorFORWARD();
  HARDWARE_rearRightMotorFORWARD();
    
  TaskManager::SetTask_(ARMS_rangeSensorForward,0); 
  //END POINT OF LOGIC WAIT DIRECTION CHOOSE
}
///////////////////////////////////////////////////////////////////

void CHASSIS_moveBackward(){

  HARDWARE_frontRightMotorBACKWARD();
  HARDWARE_rearRightMotorBACKWARD();
  HARDWARE_frontLeftMotorBACKWARD();
  HARDWARE_rearLeftMotorBACKWARD();

  TaskManager::SetTask_(CHASSIS_stop,MOVE_BACKWARD_TIME_MS);
  TaskManager::SetTask_(ARMS_rangeSensorForward,0);
  //END POINT OF LOGIC WAIT DIRECTION CHOOSE
}

////////////////////////////////////////////////////////////////////

void CHASSIS_turnRight(void){

  HARDWARE_frontRightMotorBACKWARD();
  HARDWARE_rearRightMotorBACKWARD();
  HARDWARE_frontLeftMotorFORWARD();
  HARDWARE_rearLeftMotorFORWARD();

  TaskManager::SetTask_(CHASSIS_stop,TURN_TIME_MS);
  TaskManager::SetTask_(ARMS_rangeSensorForward,0);
}
/////////////////////////////////////////////////////////////////////

void CHASSIS_turnLeft(void){

  HARDWARE_frontRightMotorFORWARD();
  HARDWARE_rearRightMotorFORWARD();
  HARDWARE_frontLeftMotorBACKWARD();
  HARDWARE_rearLeftMotorBACKWARD();
  
  TaskManager::SetTask_(CHASSIS_stop,TURN_TIME_MS);
  TaskManager::SetTask_(ARMS_rangeSensorForward,0);
}

////////////////////////////////////////////////////////////

void HARDWARE_frontLeftMotorFORWARD(void){
  digitalWrite(FRONT_LEFT_MOTOR_PIN_2, LOW);
  digitalWrite(FRONT_LEFT_MOTOR_PIN_1, HIGH);
}
////////////////////////////////////////////

void HARDWARE_frontLeftMotorOFF(void){
  digitalWrite(FRONT_LEFT_MOTOR_PIN_1, LOW);
  digitalWrite(FRONT_LEFT_MOTOR_PIN_2, LOW);
}
////////////////////////////////////////////

void HARDWARE_frontLeftMotorBACKWARD(void){
  digitalWrite(FRONT_LEFT_MOTOR_PIN_1, LOW);
  digitalWrite(FRONT_LEFT_MOTOR_PIN_2, HIGH);
}
/////////////////////////////////////////////

void HARDWARE_frontRightMotorFORWARD(void){
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_4, LOW);
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_3, HIGH);
}
///////////////////////////////////////////////

void HARDWARE_frontRightMotorOFF(void){
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_3, LOW);
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_4, LOW);
}
///////////////////////////////////////////////

void HARDWARE_frontRightMotorBACKWARD(void){
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_3, LOW);
  digitalWrite(FRONT_RIGHT_MOTOR_PIN_4, HIGH);
}
////////////////////////////////////////////////

void HARDWARE_rearLeftMotorFORWARD(void){
  digitalWrite(REAR_LEFT_MOTOR_PIN_2, LOW);
  digitalWrite(REAR_LEFT_MOTOR_PIN_1, HIGH);  
}
/////////////////////////////////////////////////

void HARDWARE_rearLeftMotorOFF(void){
  digitalWrite(REAR_LEFT_MOTOR_PIN_1, LOW);
  digitalWrite(REAR_LEFT_MOTOR_PIN_2, LOW);
}
/////////////////////////////////////////////////

void HARDWARE_rearLeftMotorBACKWARD(void){
  digitalWrite(REAR_LEFT_MOTOR_PIN_1, LOW);
  digitalWrite(REAR_LEFT_MOTOR_PIN_2, HIGH);
}
/////////////////////////////////////////////////

void HARDWARE_rearRightMotorFORWARD(void){
  digitalWrite(REAR_RIGHT_MOTOR_PIN_3, HIGH);
  digitalWrite(REAR_RIGHT_MOTOR_PIN_4, LOW);
}
/////////////////////////////////////////////////

void HARDWARE_rearRightMotorOFF(void){
  digitalWrite(REAR_RIGHT_MOTOR_PIN_3, LOW);
  digitalWrite(REAR_RIGHT_MOTOR_PIN_4, LOW);
}
///////////////////////////////////////////////////

void HARDWARE_rearRightMotorBACKWARD(void){
  digitalWrite(REAR_RIGHT_MOTOR_PIN_3, LOW);
  digitalWrite(REAR_RIGHT_MOTOR_PIN_4, HIGH);
}

/////////////////////////////////////////////////////////////////////
//END OF TASKS
//////////////////////////////////////////////////////////////
#endif //_TASKS_H
