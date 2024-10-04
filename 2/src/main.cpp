#include <boost/array.hpp>
#include <boost/asio/detail/array_fwd.hpp>
#include <fmt/base.h>
#include <fmt/format.h>

int
main()
{
    fmt::println("Hello world");
    boost::array<int, 5> arr{};
    for (auto elem: arr) {
        fmt::println("{}", elem);
    }
}
