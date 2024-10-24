#include <bits/chrono.h>
#include <chrono>
#include <iostream>
#include <print>
#include <thread>

int
main()
{
    auto t1 = std::chrono::system_clock::now();
    std::println("{}", t1.time_since_epoch());
    std::println("{}", t1.time_since_epoch().count());

    auto t2 = std::chrono::steady_clock::now();
    std::println("{}", t2.time_since_epoch());

    {
        using namespace std::literals;
        auto t3 = t1 + 24h;

        std::this_thread::sleep_for(500ms);
    }


    std::println("{}", std::chrono::duration_cast<std::chrono::days>(std::chrono::system_clock::now().time_since_epoch()));
}
