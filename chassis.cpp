#include "headers.h"

void CHASSIS::stop(void){

  HARDWARE::frontLeftMotorOFF();
  HARDWARE::frontRightMotorOFF();
  HARDWARE::rearLeftMotorOFF();
  HARDWARE::rearRightMotorOFF();
}
//////////////////////////////////////////////////////////////

void CHASSIS::moveForward(){

  HARDWARE::frontLeftMotorFORWARD();
  HARDWARE::frontRightMotorFORWARD();
  HARDWARE::rearLeftMotorFORWARD();
  HARDWARE::rearRightMotorFORWARD();
    
  OS.SetTask_(ARMS::rangeSensorForward,0); 
  //END POINT OF LOGIC WAIT DIRECTION CHOOSE
}
///////////////////////////////////////////////////////////////////

void CHASSIS::moveBackward(){

  HARDWARE::frontRightMotorBACKWARD();
  HARDWARE::rearRightMotorBACKWARD();
  HARDWARE::frontLeftMotorBACKWARD();
  HARDWARE::rearLeftMotorBACKWARD();

  OS.SetTask_(CHASSIS::stop,MOVE_BACKWARD_TIME_MS);
  OS.SetTask_(ARMS::rangeSensorForward,0);
  //END POINT OF LOGIC WAIT DIRECTION CHOOSE
}
///////////////////////////////////////////////////////////////////

void CHASSIS::turnRight(void){

  HARDWARE::frontRightMotorBACKWARD();
  HARDWARE::rearRightMotorBACKWARD();
  HARDWARE::frontLeftMotorFORWARD();
  HARDWARE::rearLeftMotorFORWARD();

  OS.SetTask_(CHASSIS::stop,TURN_TIME_MS);
  OS.SetTask_(ARMS::rangeSensorForward,0);
}
/////////////////////////////////////////////////////////////////////

void CHASSIS::turnLeft(void){

  HARDWARE::frontRightMotorFORWARD();
  HARDWARE::rearRightMotorFORWARD();
  HARDWARE::frontLeftMotorBACKWARD();
  HARDWARE::rearLeftMotorBACKWARD();
  
  OS.SetTask_(CHASSIS::stop,TURN_TIME_MS);
  OS.SetTask_(ARMS::rangeSensorForward,0);
}

////////////////////////////////////////////////////////////
