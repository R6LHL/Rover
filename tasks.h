#ifndef _TASKS_H
#define _TASKS_H

void SENSORS_searchObstaclesForward(void);
void SENSORS_searchObstaclesLeft(void);
void SENSORS_searchObstaclesRight(void);

void ARMS_rangeSensorLeft(void);
void ARMS_rangeSensorRight(void);
void ARMS_rangeSensorForward(void);

void CHASSIS_moveForward(void);
void CHASSIS_moveBackward(void);
void CHASSIS_stop(void);
void CHASSIS_turnForwardLeft(void);
void CHASSIS_turnForwardRight(void);
void CHASSIS_turnBackwardLeft(void);
void CHASSIS_turnBackwardRight(void);

void SYSTEM_chooseDirection(void);


extern unsigned int rangeForward;
extern unsigned int rangeLeft;
extern unsigned int rangeRight;
extern Ultrasonic rangeSensor;
//
/////////////////////////////////////////////////////////////
void SENSORS_searchObstaclesForward(void){

  //
  
  rangeForward = rangeSensor.read();
  TaskManager::SetTask_(ARMS_rangeSensorLeft,0);
}

/////////////////////////////////////////////////////////////
void SENSORS_searchObstaclesLeft(void){

  //
  
  rangeLeft = rangeSensor.read();

  TaskManager::SetTask_(ARMS_rangeSensorRight,MEASURE_DELAY_MS);
}

/////////////////////////////////////////////////////////////
void SENSORS_searchObstaclesRight(void){

  //
  
  rangeRight = rangeSensor.read();

  TaskManager::SetTask_(ARMS_rangeSensorForward,MEASURE_DELAY_MS);
}

//////////////////////////////////////////////////////////////
void ARMS_rangeSensorLeft(void){

  //

  TaskManager::SetTask_(SENSORS_searchObstaclesLeft,SERVO_MOVE_DELAY_MS);
}
//////////////////////////////////////////////////////////////

void ARMS_rangeSensorRight(void){

  //
  
  TaskManager::SetTask_(SENSORS_searchObstaclesRight, SERVO_MOVE_DELAY_MS);
}
//////////////////////////////////////////////////////////////

void ARMS_rangeSensorForward(void){

  //

  TaskManager::SetTask_(SYSTEM_chooseDirection, 0);
}
//////////////////////////////////////////////////////////////////////////////////

void SYSTEM_chooseDirection(void){

  if ((rangeForward > rangeLeft) && (rangeForward > rangeRight)){
    if(rangeForward > MINIMUM_RANGE_CM){
      TaskManager::SetTask_(CHASSIS_moveForward,0);
    }
    else {
      if (rangeLeft > rangeRight){
        if (rangeLeft > MINIMUM_RANGE_CM){
          TaskManager::SetTask_(CHASSIS_turnBackwardLeft,0);
        }
        else TaskManager::SetTask_(CHASSIS_moveBackward,0);
      }
      if (rangeRight > rangeLeft){
        if(rangeRight > MINIMUM_RANGE_CM){
          TaskManager::SetTask_(CHASSIS_turnBackwardRight,0);
        }
        else TaskManager::SetTask_(CHASSIS_moveBackward,0);
      }
      else TaskManager::SetTask_(CHASSIS_moveBackward,0);
    }
  }

  if ((rangeLeft > rangeRight) && (rangeLeft > rangeForward)){
    if (rangeLeft > MINIMUM_RANGE_CM){
      TaskManager::SetTask_(CHASSIS_turnForwardLeft,0);
    }
    else TaskManager::SetTask_(CHASSIS_turnBackwardRight,0);
  }

  if ((rangeRight > rangeLeft) && (rangeRight > rangeForward)){
    if(rangeRight > MINIMUM_RANGE_CM){
      TaskManager::SetTask_(CHASSIS_turnForwardRight,0);
    }
    else TaskManager::SetTask_(CHASSIS_turnBackwardLeft,0);
  }
  
  TaskManager::SetTask_(SENSORS_searchObstaclesForward, 0);
}
//////////////////////////////////////////////////////////////////

void CHASSIS_moveForward(){

//HARDWARE LOGIC
  
  TaskManager::SetTask_(CHASSIS_stop,MOVE_FORWARD_TIME_MS); 
  //END POINT OF LOGIC WAIT DIRECTION CHOOSE
}
///////////////////////////////////////////////////////////////////

void CHASSIS_moveBackward(){

//HARDWARE LOGIC

  TaskManager::SetTask_(CHASSIS_stop,MOVE_BACKWARD_TIME_MS);
  //END POINT OF LOGIC WAIT DIRECTION CHOOSE
}
////////////////////////////////////////////////////////////////////

void CHASSIS_turnBackwardLeft(void){

//HARDWARE LOGIC

  TaskManager::SetTask_(CHASSIS_stop,TURN_TIME_MS);
  //END POINT OF LOGIC WAIT DIRECTION CHOOSE
}
/////////////////////////////////////////////////////////////////////

void CHASSIS_turnBackwardRight(void){

//HARDWARE LOGIC

  TaskManager::SetTask_(CHASSIS_stop,TURN_TIME_MS);
  //END POINT OF LOGIC WAIT DIRECTION CHOOSE
}
////////////////////////////////////////////////////////////////////

void CHASSIS_turnForwardRight(void){

//HARDWARE LOGIC

  TaskManager::SetTask_(CHASSIS_stop,TURN_TIME_MS);
  //END POINT OF LOGIC WAIT DIRECTION CHOOSE
}
/////////////////////////////////////////////////////////////////////

void CHASSIS_turnForwardLeft(void){

//HARDWARE LOGIC

  TaskManager::SetTask_(CHASSIS_stop,TURN_TIME_MS);
  //END POINT OF LOGIC WAIT DIRECTION CHOOSE
}
/////////////////////////////////////////////////////////////////////////
void CHASSIS_stop(void){

////HARDWARE LOGIC
  
  TaskManager::SetTask_(SENSORS_searchObstaclesForward, 0);
  //END OF LOGIC, GOTO ENTER POINT;
}


/////////////////////////////////////////////////////////////////////
//END OF TASKS
//////////////////////////////////////////////////////////////
#endif //_TASKS_H
