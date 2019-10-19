// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/RadioHead"


//Include C++ libraries
{{#global}}
#include <RH_ASK.h>
#include <SPI.h>
{{/global}}

//Reserve memory to store an instance of the class RH_ASK
struct State {
    uint8_t mem[sizeof(RH_ASK)];
};

// Define our custom type as a pointer on the class instance.
using Type = RH_ASK*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    if (!isSettingUp()) return;

    auto state = getState(ctx);

    // Create a new object in the memory area reserved previously.
    Type driver = new (state->mem) RH_ASK();

    if (!driver->init()) {
      raiseError(ctx);
      return;
    }

    emitValue<output_DEV>(ctx, driver);
}
