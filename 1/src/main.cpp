#include "hello.hpp"

auto
main(int argc, char *argv[]) -> int
{
    Hello hello("user");
    hello.say();
    return 0;
}
