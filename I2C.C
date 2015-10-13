/*
 * File name : i2c.c
 * Author    : Mani
 * Created on: 27.5.2015
 */

#include<p18f4550.h>
#include"i2c.h"

void i2c_init()
{
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    SSPADD = 49;          // Value for 100kbps for OSC = 20MHz
    ADCON1 = 0x0f;        // Make I/O PORTA pins as digital
    SSPCON1 = 0b00101000; // Turn ON MSSP and set master mode
    SSPSTATbits.SMP = 1;  // Master mode
    return;
}

void i2c_start()
{
    PIR1bits.SSPIF = 0;
    SSPCON2bits.SEN = 1;
    while(PIR1bits.SSPIF==0);
    return;
}

void i2c_stop()
{
    PIR1bits.SSPIF = 0;
    SSPCON2bits.PEN = 1;
    while(PIR1bits.SSPIF==0);
    TRISBbits.RB0 = 0;
    TRISBbits.RB1 = 0;
    return;
}

void i2c_rep_start()
{
    PIR1bits.SSPIF = 0;
    SSPCON2bits.RSEN = 1;
    while(PIR1bits.SSPIF==0);
    return;
}

void i2c_write(unsigned int data)
{
    PIR1bits.SSPIF = 0;
    SSPBUF = data;
    while(PIR1bits.SSPIF==0);
    return;
}

unsigned int i2c_single_read()
{
    unsigned int r_data;
    PIR1bits.SSPIF = 0;
    SSPCON2bits.RCEN = 1;
    while(PIR1bits.SSPIF==0);
    r_data = SSPBUF;
    PIR1bits.SSPIF = 0;
    SSPCON2bits.ACKDT = 1;
    SSPCON2bits.ACKEN = 1;
    while(PIR1bits.SSPIF==0);
    return r_data;
}

unsigned int i2c_multiple_read()
{
    unsigned int r_data;
    PIR1bits.SSPIF = 0;
    SSPCON2bits.RCEN = 1;
    while(PIR1bits.SSPIF==0);
    r_data = SSPBUF;
    PIR1bits.SSPIF = 0;
    SSPCON2bits.ACKDT = 0;
    SSPCON2bits.ACKEN = 1;
    while(PIR1bits.SSPIF==0);
    return r_data;
}
