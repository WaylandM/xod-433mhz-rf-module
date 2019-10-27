
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto state = getState(ctx);
    auto xString = getValue<input_STR>(ctx);

    int N=length(xString) + 1;
    char cString[N];
    for(int i=0;i<N;i++)
    cString[i]=0;
    dump(xString,cString);
    emitValue<output_NUM>(ctx, atof(cString));
}


