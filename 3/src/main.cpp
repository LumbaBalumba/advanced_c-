#include <ostream>
#include <print>
#include <string>
#include <utility>

void
f(int &x)
{
    std::println("{}", __PRETTY_FUNCTION__);
}

void
f(int &&x)
{
    std::println("{}", __PRETTY_FUNCTION__);
}

void
f(const int &x)
{
    std::println("{}", __PRETTY_FUNCTION__);
}

void
f(const int &&x)
{
    std::println("{}", __PRETTY_FUNCTION__);
}


template<typename T>
int
ff(T &&x)
{
    std::println("{}", __PRETTY_FUNCTION__);
    return 0;
}

template<typename T1, typename T2>
int
fff(T1 &&x1, T2 &&x2)
{
    std::println("{}", __PRETTY_FUNCTION__);
    ff(std::forward<T1>(x1));
    ff(std::forward<T2>(x2));
}

template<typename... T>
void
doall2(T &&...args)
{
    // std::println("{}", __PRETTY_FUNCTION__);
}

template<typename... T>
void
doall(T &&...args)
{
    std::println("{}", __PRETTY_FUNCTION__);
    doall2(ff<T>(std::forward<T>(args))...);
}


template<typename... T>
struct data {
};

int
main()
{
    int x{};
    int &v1 = x;
    const int &v2 = x;

    // f(x);
    // f(v1);
    // f(v2);
    // f(10);
    //
    // ff(x);
    // ff(v1);
    // ff(v2);
    // ff(10);

    // fff(v1, 10);
    // fff(5, x);
    // fff(22, x);
    //
    // fff(std::move(x), 5);// move == static_cast<int&&>
    //
    // {
    //     std::string x = "23232";
    //     std::string y = std::move(x);//результат зависит от реализации move
    //     std::println("{}", x);
    // }
    //
    //
    // doall(1, 2, 3);
    // doall("str", 4.0);
    // doall(nullptr);
}
