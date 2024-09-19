#pragma once
#include <string>

class Hello
{
    std::string who_;

public:
    using result_t = int;

    Hello(std::string who);

    auto
    say(this const Hello &self) -> void;

    result_t
    func1();

    auto
    func2() -> result_t;

    auto
    func3(auto x) -> decltype(x)
    {
        return x + 1;
    }
};
