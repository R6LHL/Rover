#ifndef VARIABLES_H
#define VARIABLES_H

#include "config.h"
#include <Servo.h>
#include <Ultrasonic.h>
#include <TaskManager.h>
unsigned const char T_TASK_QUEUE_SIZE = 5;  //for Task Manager - size of Task Queue

typedef TaskManager <T_TASK_QUEUE_SIZE> TaskManager5; //define task manager with queue size lenght = 5
extern TaskManager5 OS;

extern Ultrasonic rangeSensorFront;
extern Ultrasonic rangeSensorBack;

extern Servo rangeSensorArm;

extern volatile unsigned int rangeForward;
extern volatile unsigned int rangeLeft;
extern volatile unsigned int rangeRight;
extern volatile unsigned int rangeBackward;

#endif
