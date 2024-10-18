// func(int, 0) -> tuple<>
// func(int, 1) -> tuple<int>
// func(int, 2) -> tuple<int, int>
// func(int, 3) -> tuple<int, int, int>
//

#include <print>
#include <tuple>

template<typename T, int n>
auto
func(const T &v, char (*)[n == 0] = nullptr)
{
    return std::tuple<>{};
}

template<typename T, int n>
auto
func(const T &v, char (*)[n == 1] = nullptr)
{
    return std::tuple<T>{v};
}

template<typename T, int n>
auto
func(const T &v, char (*)[n == 2] = nullptr)
{
    return std::tuple<T, T>{v, v};
}

template<typename T, int n>
auto
func(const T &v, char (*)[n == 3] = nullptr)
{
    return std::tuple<T, T, T>{v, v, v};
}

int
main()
{
    int x = 10;

    auto v1 = func<int, 0>(x);
    auto v2 = func<int, 1>(x);
    auto v3 = func<int, 2>(x);
    auto v4 = func<int, 3>(x);


    std::println("{}", sizeof v1);
    std::println("{}", sizeof v2);
    std::println("{}", sizeof v3);
    std::println("{}", sizeof v4);
}
