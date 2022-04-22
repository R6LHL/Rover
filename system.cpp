#include "headers.h"
#include "variables.h"
#include <Arduino.h>

void SYSTEM::check_Forward(void){

  if (rangeForward < MINIMUM_RANGE_CM){
    OS.SetTask_(CHASSIS::stop,0);
    OS.SetTask_(ARMS::rangeSensorLeft,0);
  }
  else {OS.SetTask_(CHASSIS::moveForward,0);}
}
/////////////////////////////////////////////////////////////////////////

void SYSTEM::chooseDirection(void){
  
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
        
  OS.SetTask_(CHASSIS::turnLeft,0);     
  }
  
  else if ((rangeRight > rangeLeft) && (rangeRight > MINIMUM_RANGE_CM)){ // if right range is max
       
  OS.SetTask_(CHASSIS::turnRight,0);
  }
    
  else OS.SetTask_(CHASSIS::moveBackward,0);
}
//////////////////////////////////////////////////////////////////
