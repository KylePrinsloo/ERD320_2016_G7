/* 
 * File:   motor.h
 * Author: Kyle Prinsloo
 *
 * Created on 20 October 2016, 11:37 AM
 */
//#include "config.h"
#ifndef MOTOR_H
#define	MOTOR_H
#include <p18f45k20.h>
#define SLOW 75
#define MEDIUM 85
#define FAST 95
#define STEP_ON  1
#define STEP_OFF 0

extern int dcDirection;//0 for forward, 1 for reverse
extern int speed;
extern int position;
extern int pos0, pos1, pos2, pos3;
/*
 0 - off
 1 - slow   35%
 2 - medium 65%
 3 - fast   95%
 */
    
void moveStepper(int dir);
void changeDCDir(int dir);
void changeDCSpeed(int newSpeed);
void motorInit();
int getDir();
int getPos();
int getSpeed();


#endif	/* MOTOR_H */

