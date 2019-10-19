
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

    list<char> msg;
        for(int i=0;i<buflen;i++)
            msg.push_back(buf[i]);

    emitValue<output_MSG>(ctx, msg);
    emitValue<output_REC>(ctx, 1);
        
    }
}
