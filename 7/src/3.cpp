//unbuffered channel, SPSC

#include <chrono>
#include <cstdint>
#include <print>
#include <random>
#include <stop_token>
#include <thread>

template<typename T>
class SPSC
{

public:
    void
    put(const T &val)
    {}


    void
    put(T &&val)
    {}

    T
    get()
    {
        return T();
    }
};

void
producer(std::stop_token t, uint32_t seed, SPSC<int> &q)
{
    int serial = 0;
    std::mt19937 rnd(seed);
    while (!t.stop_requested()) {
        auto interval = std::chrono::milliseconds(100 + (rnd() % 11) * 10);
        std::this_thread::sleep_for(interval);
        q.put(++serial);
        auto cur = std::chrono::system_clock::now().time_since_epoch().count();
        std::println("producer {} {}", serial, cur);
    }
}


void
consumer(std::stop_token t, uint32_t seed, SPSC<int> &q)
{
    std::mt19937 rnd(seed);
    while (!t.stop_requested()) {
        auto interval = std::chrono::milliseconds(100 + (rnd() % 11) * 10);
        std::this_thread::sleep_for(interval);
        auto val = q.get();
        auto cur = std::chrono::system_clock::now().time_since_epoch().count();
        std::println("producer {} {}", val, cur);
    }
}


int
main()
{
    uint32_t seed = uint32_t(std::chrono::system_clock::now().time_since_epoch().count());
    SPSC<int> queue;
    std::jthread t1(producer, seed, std::ref(queue));
    std::jthread t2(producer, seed, std::ref(queue));
    using namespace std::literals;
    std::this_thread::sleep_for(10s);
}
