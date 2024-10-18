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
//

template<typename T>
concept Moveable = std::is_nothrow_move_constructible<T>::value && std::is_nothrow_move_assignable<T>::value;


template<typename T>
void
myswap(T &a, T &b)
{
    std::println("{}", __PRETTY_FUNCTION__);
    T tmp{std::move(a)};
    a = std::move(b);
    b = std::move(tmp);
}


int
main()
{
    std::string x = "x", y = "y";

    myswap(x, y);

    std::println("{} {}", x, y);
}
