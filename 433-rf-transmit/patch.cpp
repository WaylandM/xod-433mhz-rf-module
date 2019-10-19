
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_SEND>(ctx))
        return;

    // Get a pointer to the `RH_ASK` class instance
    auto driver = getValue<input_DEV>(ctx);

    auto xString = getValue<input_MSG>(ctx);
    int N=length(xString) + 1;
    char cString[N];
    for(int i=0;i<N;i++)
    cString[i]=0;
    dump(xString, cString);
    driver->send(cString, strlen(cString));
    driver->waitPacketSent();

    emitValue<output_SENT>(ctx, 1);
}
