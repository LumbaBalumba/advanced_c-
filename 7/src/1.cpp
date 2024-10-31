#include <exception>
#include <future>
#include <iostream>
#include <print>
#include <stdexcept>
#include <thread>
#include <utility>

int
main()
{
    int x;
    std::cin >> x;
    std::promise<int> p;
    auto f = p.get_future();
    std::jthread th1(
            [](std::promise<int> &&p, auto x) {
                if (x < 0) {
                    // throw std::runtime_error("whatever");
                    p.set_exception(std::make_exception_ptr(std::runtime_error("whatever")));
                }
                p.set_value(1);
            },
            std::move(p), x);

    try {
        auto res = f.get();
        std::println("{}", res);
    } catch (std::exception &ex) {
        std::println("error: {}", ex.what());
    }
}
