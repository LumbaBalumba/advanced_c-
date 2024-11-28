#include <cstdint>
#include <print>


struct Fib {
    uint64_t value_;
    uint64_t a = 0;
    uint64_t b = 1;

    int state = 0;

    void
    set_value(uint64_t value)
    {
        value_ = value;
    }

public:
    void
    operator()()
    {
        switch (state) {
            case 0:
                value_ = 0;
                state = 1;
                break;
            case 1:
                value_ = 1;
                state = 2;
                break;
            case 2:
                auto c = a + b;
                value_ = c;
                a = b;
                b = c;
                state = 2;
        }
    }
};


int
main()
{
    Fib fib;
    while (true) {
        fib();
        std::println("{}", fib.value_);
    }
}
