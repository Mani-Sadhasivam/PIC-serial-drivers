/*
 * File name : i2c.h
 * Author    : Mani
 * Created on: 17.5.2015
 */
#ifndef I2C_HEADER
#define I2C_HEADER

void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_rep_start(void);
void i2c_write(unsigned int);
unsigned int i2c_single_read(void);
unsigned int i2c_multipe_read(void);

#endif
