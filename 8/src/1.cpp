#include <boost/coroutine2/coroutine.hpp>
#include <print>

int
main()
{
    using coro_t = boost::coroutines2::coroutine<int>;
    coro_t::pull_type coro([](coro_t::push_type &sink) {
        std::println("in coro 1");
        sink(1);
        std::println("in coro 2");
        sink(2);
        std::println("in coro 2");
        sink(3);
        std::println("in coro 3");
    });

    std::println("in main 1");
    std::println("{}", coro.get());
    std::println("in main 2");
    coro();
    std::println("in main 3");
    std::println("{}", coro.get());
    std::println("in main 4");
    coro();
    std::println("in main 5");
    std::println("{}", coro.get());

    // while (coro) {
    //     std::println("{}", coro.get());
    //     coro();
    // }

    // for (auto it = coro.begin(); it != coro.end(); ++it) {
    //     std::println("{}", *it);
    // }

    for (auto v: coro) {

        std::print("{}", v);
    }
}
