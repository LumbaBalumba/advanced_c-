#include <thread>

int
main()
{
    std::thread thr(
            [](int a, int b) {
                using namespace std::literals;
                std::this_thread::sleep_for(100ms);
            },
            1, 2);
    thr.join();
}
