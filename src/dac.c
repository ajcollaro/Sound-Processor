#include "main.h"

/* Device Address:
   1100010 (0x62) or 1100011 (0x63)
   (depending on whether A0 wired to GND or VCC)
   0xC2 works in Proteus sim.
*/

enum MCP4725_MAGIC_NUMBERS {
    ADDRESS = 0x63<<1,
    ADDRESS_SIM = 0xC2,
    CO = 0x40
};

void dac_put(dac_t *dac, i2c_t *i2c)
{
    /* Start -> SLA+W -> CO -> MSBs -> LSBs = 5 bytes total. */
    i2c_tx_start();

    i2c->byte = ADDRESS;
    i2c_tx(i2c);
    i2c->byte = CO;
    i2c_tx(i2c);
    i2c->byte = dac->byte_hi;
    i2c_tx(i2c);
    i2c->byte = dac->byte_lo;
    i2c_tx(i2c);

    /* Release SCK and SDA lines. */
    i2c_tx_stop();
}