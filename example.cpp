
#include "TLC5940.h"

TLC5940 tlc;

uint16_t intense = 0;
void setup() {
    //setup
    tlc.init();
    //since setup clears, we need to call update to set everything blank
    tlc.update();
}

void loop() {

    //reset intense if it's over the max value
    if (intense >= 4096) intense = 0;
    
    //set every channel to the intense value
    for (uint8_t i = val; i < 48; i += 1) {
        tlc.set(i, intense);
    }
    //increment the intense
    intense += 160;
    
    tlc.update();
    delay(10);
}
