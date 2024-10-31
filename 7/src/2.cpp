#include <future>
#include <iostream>
#include <print>
#include <stdexcept>

int
main()
{
    int x;
    std::cin >> x;
    auto f = std::async(
            std::launch::async,
            [](auto x) {
                if (x < 0) {
                    throw std::runtime_error("whatever");
                }
                return x + 1;
            },
            x);
    try {
        int res = f.get();
        std::println("{}", res);
    } catch (std::exception &ex) {
        std::println("error: {}", ex.what());
    }
}
