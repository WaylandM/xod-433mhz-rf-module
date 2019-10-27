
struct State {
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    CStringView view;
    State() : view(buf) {}
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto state = getState(ctx);

    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `RH_ASK` class instance
    auto driver = getValue<input_DEV>(ctx);

    uint8_t buflen = sizeof(state->buf);

    // clear buffer
    memset(state->buf, 0, buflen);

    if (driver->recv(state->buf, &buflen)) // Non-blocking
    {
        emitValue<output_MSG>(ctx, XString(&state->view));
        emitValue<output_REC>(ctx, 1);
    }
}
