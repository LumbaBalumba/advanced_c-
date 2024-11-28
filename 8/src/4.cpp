#include <cstdint>
#include <functional>
#include <print>

class Fib
{
    std::function<void(uint64_t)> cb_;
    uint64_t value_;


    void
    set_value(uint64_t value)
    {
        cb_(value);
    }

public:
    Fib(std::function<void(uint64_t)> callback) : cb_(callback) {}

    void
    operator()()
    {
        uint64_t a = 0, b = 1;
        set_value(0);
        set_value(1);
        while (true) {
            auto c = a + b;
            set_value(c);
            a = b;
            b = c;
        }
    }
};


int
main()
{
    Fib f([](auto x) {
        std::println("{}", x);
    });
    f();
}
