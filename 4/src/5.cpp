#include <algorithm>
#include <cstddef>
#include <print>
#include <type_traits>

template<typename... Ts>
struct MaxSize {
    static constexpr std::size_t size = 1;
};

template<typename T, typename... Ts>
struct MaxSize<T, Ts...> {
    static constexpr std::size_t size = std::max(sizeof(T), MaxSize<Ts...>::size);
};


template<size_t idx, typename X, typename... Ts>
struct Index {
};

template<size_t idx, typename X>
struct Index<idx, X> {
    static constexpr std::size_t index = sizeof(X);
};

template<size_t idx, typename X, typename T, typename... Ts>
    requires std::is_same<X, T>::value
struct Index<idx, X, T, Ts...> {
    static constexpr std::size_t index = idx;
};

template<size_t idx, typename X, typename T, typename... Ts>
    requires(!std::is_same<X, T>::value)
struct Index<idx, X, T, Ts...> {
    static constexpr std::size_t index = Index<idx + 1, X, Ts...>::index;
};


template<size_t idx, typename... Ts>
struct Type {
};

template<size_t idx, typename T, typename... Ts>
    requires(idx == 0)
struct Type<idx, T, Ts...> {
    using type = T;
};

template<size_t idx, typename T, typename... Ts>
    requires(idx > 0)
struct Type<idx, T, Ts...> {
    using type = Type<idx - 1, Ts...>::type;
};

template<typename... Ts>
struct Variant {
    int tag_;
    alignas(Ts...) std::byte data_[MaxSize<Ts...>::size];

    Variant() : tag_{sizeof...(Ts)} {}

    template<class T>
        requires(Index<0, T, Ts...>::index != sizeof...(Ts))
    Variant(const T &value) : tag_{Index<0, T, Ts...>::index}
    {
        new (data_) T(value);
    }


    template<std::size_t idx>
    auto
    get() noexcept -> typename Type<idx, Ts...>::type &
    {
        return *reinterpret_cast<typename Type<idx, Ts...>::type *>(data_);
    }


    template<size_t idx, typename... Tss>
    void
    destroy() noexcept
        requires(idx == sizeof...(Tss))
    {
    }

    template<size_t idx, typename T, typename... Tss>
    void
    destroy() noexcept
        requires(idx < sizeof...(Tss))
    {
        if (idx == tag_) {
            auto *p = reinterpret_cast<T *>(data_);
            p->~T();
        }
        destroy<idx + 1, Tss...>();
    }


    ~Variant()
    {
        destroy<0, Ts...>();
    }
};


int
main()
{
    std::println("{}", MaxSize<int, char, double>::size);

    using V = Variant<int, char, double, int[10]>;
    std::println("{}", sizeof(V));

    V v1 = 1;
    V v2 = 'c';
    V v3 = 1.2;

    std::println("{}", v1.get<0>());
    std::println("{}", v2.get<1>());
    std::println("{}", v3.get<2>());
}
