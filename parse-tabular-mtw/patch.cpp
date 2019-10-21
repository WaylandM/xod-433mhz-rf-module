class SplitCStringView : public ListView<char> {
  public:
      class Cursor : public detail::Cursor<char> {
      public:
        Cursor(Iterator<char>&& ptr, char del, int n)
            : _ptr(std::move(ptr))
	    , _del(del)
	    , _n(n)
	    , _curn(0)
        {
            while (_curn < _n && isValid()) next();
        }

        bool isValid() const override {
		    return _curn <= _n && (bool)_ptr;
        }

        bool value(char* out) const override {
            if (_curn > _n) return false;
	        return _ptr.value(out);
	    }

        void next() override {
 		    ++_ptr;
            char c;
            while (_ptr.value(&c) && c == _del) {
                ++_curn;
                ++_ptr;
            }
	    }

      private:
        Iterator<char> _ptr;
	char _del;
	int _n;
	int _curn;
    };

  public:
    SplitCStringView() { }

    SplitCStringView(List<char> str, char del, int n)
        : _str(str)
	, _del(del)
	, _n(n)
    { }

    SplitCStringView& operator=(const SplitCStringView& rhs) {
        _str = rhs._str;
	_del = rhs._del;
	_n = rhs._n;
        return *this;
    }

    virtual Iterator<char> iterate() const override {
        return Iterator<char>(new Cursor(_str.iterate(), _del, _n));
    }

  private:
    friend class Cursor;
    List<char> _str;
    char _del;
    int _n;
};

struct State {
    SplitCStringView view;
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    auto state = getState(ctx);
    auto str = getValue<input_STR>(ctx);
    auto num = getValue<input_IDX>(ctx);
    auto del = getValue<input_D>(ctx);
    state->view = SplitCStringView(str,del,num);
    emitValue<output_OUT>(ctx,XString(&state->view));
}
