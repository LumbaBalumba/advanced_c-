#include <mutex>
#include <print>
#include <thread>

volatile int count = 0;

int
main()
{
    std::mutex m;
    std::jthread th1([&m] {
        for (int i = 0; i < 10000000; ++i) {
            // std::lock_guard g{m};
            // std::unique_lock g{m};
            std::scoped_lock g{m};
            count += 1;
        }
    });
    std::jthread th2([&m] {
        for (int i = 0; i < 10000000; ++i) {
            // std::lock_guard g{m};
            // std::unique_lock g{m};
            std::scoped_lock g{m};
            count += 2;
        }
    });

    th1.join();
    th2.join();

    std::println("{}", count);
}
