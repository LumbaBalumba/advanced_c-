#include <print>
#include <type_traits>

// template<typename T>
// void
// myswap(T &a, T &b)
// {
//     std::println("{}", __PRETTY_FUNCTION__);
//     T tmp{a};
//     a = b;
//     b = tmp;
// }

// template<>
// void
// myswap(int &a, int &b)
// {
//     a ^= b;
//     b ^= a;
//     a ^= b;
// }
//

template<typename T>
void
myswap(T &a, T &b, typename std::enable_if<!std::is_integral<T>::value, bool>::type = false)
{
    std::println("{}", __PRETTY_FUNCTION__);
    a ^= b;
    b ^= a;
    a ^= b;
}

template<typename T>
void
myswap(T &a, T &b, typename std::enable_if<std::is_integral<T>::value, bool>::type = false)
{
    std::println("{}", __PRETTY_FUNCTION__);
    a ^= b;
    b ^= a;
    a ^= b;
}

int
main()
{
    int x = 2, y = 3;

    myswap(x, y);

    std::println("{} {}", x, y);
}
