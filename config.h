#ifndef _CONFIG_H
#define _CONFIG_H

#define CPU_CLOCK (12000000)   // Hz at UNO328p
#define T_TASK_QUEUE_SIZE (5)

#define RANGE_SENSOR_EMITTER  (12)
#define RANGE_SENSOR_RECEIVER (13)

#define SERVO_HALF_MOVE_DELAY_MS   (500)
#define SERVO_MOVE_DELAY_MS         (2 * (SERVO_HALF_MOVE_DELAY_MS))
#define MEASURE_DELAY_MS            100

#define MINIMUM_RANGE_CM            (10)

#define MOVE_FORWARD_TIME_MS        (1000)
#define MOVE_BACKWARD_TIME_MS       (1000)
#define TURN_TIME_MS                (500)

#endif CONFIG_H
