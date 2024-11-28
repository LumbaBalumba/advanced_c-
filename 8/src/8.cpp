#include <cctype>
#include <generator>
#include <print>
#include <string>

std::generator<const std::string_view &>
split(std::string_view sv)
{
    size_t pos = 0;
    size_t len = 0;
    while (1) {
        while (pos < sv.size() && std::isspace(char8_t(sv[pos]))) {
            ++pos;
        }
        if (pos == sv.size()) co_return;
        while (pos + len < sv.size() && !std::isspace(char8_t(sv[pos + len]))) {
            ++len;
        }
        co_yield std::string_view(&sv[pos], len);
        pos += len;
        len = 0;
    }
}

int
main()
{
    std::string str;
    for (int i = 0; i < 10000000; ++i) {
        str += ' ';
        str += std::to_string(i);
    }

    for (auto sv: split(str)) {
        std::println("{}", sv);
    }
}
