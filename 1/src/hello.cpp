#include "hello.hpp"
#include <print>


Hello::Hello(std::string who) : who_(std::move(who)) {}

auto
Hello::say(this const Hello &self) -> void
{
    std::println("Hello, {}", self.who_);
}

Hello::result_t
Hello::func1()
{
    return 0;
}


auto
Hello::func2() -> result_t
{
    return 0;
}
