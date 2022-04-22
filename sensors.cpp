#include "headers.h"
#include "variables.h"

void SENSORS::searchObstaclesForward(void){

  rangeForward = rangeSensorFront.read();
  OS.SetTask_(SYSTEM::check_Forward,MEASURE_DELAY_MS);
}
/////////////////////////////////////////////////////////////

void SENSORS::searchObstaclesLeft(void){

  rangeLeft = rangeSensorFront.read();
  OS.SetTask_(ARMS::rangeSensorRight,MEASURE_DELAY_MS);
}
//////////////////////////////////////////////////////////////

void SENSORS::searchObstaclesRight(void){

  rangeRight = rangeSensorFront.read();
  rangeSensorArm.write(RANGE_SENSOR_ARM_CENTER);
  
  OS.SetTask_(SYSTEM::chooseDirection, 0);
}
/////////////////////////////////////////////////////////////////////

void SENSORS::searchObstaclesBackward(void){
  rangeBackward = rangeSensorBack.read();

  OS.SetTask_(CHASSIS::stop,MOVE_BACKWARD_TIME_MS);
  OS.SetTask_(ARMS::rangeSensorForward,0);
}
//////////////////////////////////////////////////////////////
