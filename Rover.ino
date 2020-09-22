#include "headers.h"

#ifdef Ultrasonic_h
  Ultrasonic rangeSensor(RANGE_SENSOR_EMITTER, RANGE_SENSOR_RECEIVER);
#endif //Ultrasonic_h
unsigned int rangeForward;
unsigned int rangeLeft;
unsigned int rangeRight;

///////////////////////////////////////////////////
ISR(TIMER2_OVF_vect){
  TaskManager::TimerTaskService_();
}
////////////////////////////////////////////////////


///////////////////////////////////////////////////
void setup() {
  noInterrupts();
  TCCR2B |= (1<<CS22);    // (clk/64)
  TIMSK2 |= (1<<TOIE2);   // ovf interrupt enabled
  
  TaskManager::SetTask_(CHASSIS_stop,0); //LOGIC ENTER POINT
//
  
  interrupts();
}
/////////////////////////////////////////////////
void loop() {TaskManager::ProcessTaskQueue_();}
/////////////////////////////////////////////////
