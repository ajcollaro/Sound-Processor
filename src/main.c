#include "main.h"

int main(void)
{
    /* Setup hardware. */
    adc_init();
    i2c_init();

    adc_t adc_, *adc = &adc_;
    i2c_t i2c_, *i2c = &i2c_;

    sei();

    while(1)
    {

    }
}