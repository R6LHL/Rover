#include "arms.h"
#include "headers.h"
#include <Servo.h>
#include "variables.h"

void ARMS::rangeSensorForward(void){

   rangeSensorArm.write(RANGE_SENSOR_ARM_CENTER);
   OS.SetTask_(SENSORS::searchObstaclesForward, SERVO_HALF_MOVE_DELAY_MS);
}
/////////////////////////////////////////////////////////////

void ARMS::rangeSensorLeft(void){

  rangeSensorArm.write(RANGE_SENSOR_ARM_LEFT);

  OS.SetTask_(SENSORS::searchObstaclesLeft,SERVO_MOVE_DELAY_MS);
}
/////////////////////////////////////////////////////////////

void ARMS::rangeSensorRight(void){

  rangeSensorArm.write(RANGE_SENSOR_ARM_RIGHT);
  
  OS.SetTask_(SENSORS::searchObstaclesRight, SERVO_MOVE_DELAY_MS);
}
/////////////////////////////////////////////////////////////
