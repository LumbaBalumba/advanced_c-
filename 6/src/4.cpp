#include <atomic>
#include <print>
#include <thread>

int
main()
{
    using namespace std::literals;

    std::atomic<bool> stop_flag = false;

    std::jthread thr(
            [&](int a, int b) {
                while (!stop_flag) {
                    std::println("{} {}", a, b);
                    std::this_thread::sleep_for(500ms);
                }
            },
            1, 2);
    stop_flag = true;
    std::this_thread::sleep_for(2s);
}
