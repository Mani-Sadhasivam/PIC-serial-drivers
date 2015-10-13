#include<p18f4550.h>
#include"i2c.h"
#pragma config FOSC=HS, FCMEN=ON, WDT=OFF, IESO=OFF, XINST=OFF, LVP=OFF
void main()
{
    i2c_start();
    i2c_write(0b11010000);
    i2c_write();
    i2c_stop();
    
}
