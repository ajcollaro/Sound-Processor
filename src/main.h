#pragma once

#include "avr.h"
#include <avr/interrupt.h>

/* Analog to digital converter. */
typedef union {
    struct {
        uint8_t ret_hi;
        uint8_t ret_lo;
    };
    uint16_t ret;
} adc_t;

/* Digital to analog converter. */
typedef union {
    struct {
        uint8_t byte_hi;
        uint8_t byte_lo;
    };
    uint16_t put;
} dac_t;

/* i2c TWI. */
typedef struct {
    uint8_t byte;
} i2c_t;

void adc_init(void);

void dac_put(dac_t *, i2c_t *);

void i2c_tx(i2c_t *);
void i2c_tx_stop(void);
void i2c_tx_start(void);
void i2c_init(void);