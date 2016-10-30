/* 
 * File:   General.c
 * Author: Alistair Yan
 *
 * Created on 08 September 2016, 7:30 PM
 */


/*2.5 milliseconds multiplied by itime*/
void delay(unsigned int itime)
{
    unsigned int i; unsigned char j;
    for (i=0; i<itime; i++)
        for (j=0;j<165;j++);
    return;
}


