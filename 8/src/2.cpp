#include <boost/coroutine2/coroutine.hpp>
#include <print>

int
main()
{
    using coro_t = boost::coroutines2::coroutine<int>;
    coro_t::push_type coro([](coro_t::pull_type &in) {
        // while (in) {
        //     std::println("{}", in.get());
        //     in();
        // }
        for (auto v: in) {
            std::println("{}", v);
        }
    });
}
