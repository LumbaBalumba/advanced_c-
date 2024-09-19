#include "hello.hpp"

auto
main() -> int
{
    Hello hello("user");
    hello.say();
    return 0;
}
