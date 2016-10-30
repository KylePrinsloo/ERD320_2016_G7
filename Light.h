/* 
 * File:   Light.h
 * Author: Alistair Yan
 *
 * Created on 08 September 2016, 7:20 PM
 */

#ifndef LIGHT_H
#define	LIGHT_H
#include <p18f45k20.h>

unsigned int readLightADC(void);
unsigned int set_light_range(unsigned int);
unsigned int calculate_lux(unsigned int light);


#endif	/* LIGHT_H */

