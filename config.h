#ifndef _CONFIG_H
#define _CONFIG_H

#define CPU_CLOCK (12000000)   // Hz at UNO328p
#define T_TASK_QUEUE_SIZE (5)

#define FRONT_RANGE_SENSOR_TRIGGER_PIN  (12)
#define FRONT_RANGE_SENSOR_ECHO_PIN     (11)

#define BACK_RANGE_SENSOR_TRIGGER_PIN   (13)
#define BACK_RANGE_SENSOR_ECHO_PIN      (14)

#define SERVO_HALF_MOVE_DELAY_MS   (500)
#define SERVO_MOVE_DELAY_MS         (2 * (SERVO_HALF_MOVE_DELAY_MS))
#define MEASURE_DELAY_MS            100

#define MINIMUM_RANGE_CM            (10)

#define MOVE_FORWARD_TIME_MS        (500)
#define MOVE_BACKWARD_TIME_MS       (250)
#define TURN_TIME_MS                (500)

#define DRIVE_TYPE                  (AWD) //OR FWD OR AWD -Rear or Front or All Wheel Drive

#define RANGE_SENSOR_ARM_PIN        (10)
#define RANGE_SENSOR_ARM_CENTER     (85)
#define RANGE_SENSOR_ARM_LEFT       (180)
#define RANGE_SENSOR_ARM_RIGHT      (0)

#define FRONT_LEFT_MOTOR_PIN_1      (2)
#define FRONT_LEFT_MOTOR_PIN_2      (4)
#define FRONT_RIGHT_MOTOR_PIN_3     (8)
#define FRONT_RIGHT_MOTOR_PIN_4     (7)

#define REAR_LEFT_MOTOR_PIN_1       (3)
#define REAR_LEFT_MOTOR_PIN_2       (5)
#define REAR_RIGHT_MOTOR_PIN_3      (6)
#define REAR_RIGHT_MOTOR_PIN_4      (9)

//#define HARDWARE_DELAY_MS           (500)

#define DEBUG
/////////////////////////////////////////////

#endif CONFIG_H
