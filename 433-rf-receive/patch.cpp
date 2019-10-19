
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `RH_ASK` class instance
    auto driver = getValue<input_DEV>(ctx);

    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver->recv(buf, &buflen)) // Non-blocking
    {
  //int i;

  // Message with a good checksum received, dump it.
  //driver.printBuffer("Got:", (char*)buf, buflen);

    //XString msg[buflen];
    //for(int i=0;i<buflen;i++)
        //msg[i]=buf[i];

        //uint8_t msg[buflen+1];
        //uint8_t i;
        //for(i=0; i<buflen; i++)
          //  msg += buf[i];
    
        //msg += '\0';

        emitValue<output_MSG>(ctx, XString(buf));
        emitValue<output_REC>(ctx, 1);
        
    }
}
