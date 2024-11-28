#include <coroutine>
#include <cstdint>
#include <print>

template<typename T>
struct Generator {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    handle_type handle_;

    Generator(handle_type handle) : handle_(handle) {}

    struct promise_type {
        T value_;

        Generator
        get_return_object()
        {
            std::println("{}", __PRETTY_FUNCTION__);
            return Generator(handle_type::from_promise(*this));
        }

        void
        unhandled_exception()
        {
        }

        std::suspend_always
        yield_value(T value)
        {
            std::println("{}", __PRETTY_FUNCTION__);
            value_ = value;
            return {};
        }


        void
        return_value(T value)
        {
            std::println("{}", __PRETTY_FUNCTION__);
            value_ = value;
        }

        std::suspend_always
        initial_suspend()
        {
            std::println("{}", __PRETTY_FUNCTION__);
            return {};
        }

        std::suspend_always
        final_suspend() noexcept
        {
            std::println("{}", __PRETTY_FUNCTION__);
            return {};
        }
    };
};

auto
func2()
{
    struct awaitable {
        bool
        await_ready() const
        {
            std::println("{}", __PRETTY_FUNCTION__);
            return true;
        }

        void
        await_suspend(Generator<uint64_t>::handle_type h)
        {
            std::println("{}", __PRETTY_FUNCTION__);
        }

        void
        await_resume()
        {
            std::println("{}", __PRETTY_FUNCTION__);
        }
    };
    return awaitable{};
}

Generator<uint64_t>
func()
{
    std::println("func 1");
    co_yield 1;
    std::println("func 2");
    co_yield 2;
    co_await func2();
    std::println("func 3");
    co_yield 3;

    co_return 4;
}


int
main()
{
    auto gen = func();
    while (true) {
        gen.handle_();
        if (gen.handle_.done()) {
            break;
        }
        std::println("{}", gen.handle_.promise().value_);
    }
}
