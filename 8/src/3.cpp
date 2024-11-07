#include <boost/coroutine2/coroutine.hpp>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <print>
#include <string>
#include <string_view>

class Splitter
{
    std::string_view sv_;
    using coro_sv_t = boost::coroutines2::coroutine<std::string_view>;
    coro_sv_t::pull_type coro_;

public:
    Splitter(std::string_view sv)
        : sv_(sv),
          coro_([this](coro_sv_t::push_type &sink) {
        size_t pos = 0;
        size_t len = 0;
        while (true) {
            while (pos < sv_.size() && std::isspace(char8_t(sv_[pos]))) {
                ++pos;
            }
            if (pos == sv_.size()) {
                return;
            }
            while(pos + len< sv_.size() && !std::isspace(char8_t(sv_[pos+len]))) {
                ++len;
            }
            sink(std::string_view(&sv_[pos], len));
            pos+=len;
            len=0;
        } })
    {}

    auto
    begin()
    {
        return coro_.begin();
    }

    auto
    end()
    {
        return coro_.end();
    }
};

int
main()
{
    std::string line;
    std::getline(std::cin, line);
    for (auto v: Splitter(line)) {
        std::println("{}", v);
    }
}
