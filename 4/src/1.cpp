#include <print>
#include <string>

template<typename... Ts>
struct MyTuple {
};

template<typename T>
struct MyTuple<T> {
    T value;
};

template<typename T, typename... Ts>
struct MyTuple<T, Ts...> {
    T value;
    MyTuple<Ts...> tail;
};


int
main()
{
    MyTuple<int, char *, std::string> s1;
    MyTuple<> s2;
    MyTuple<int, char> s3;

    std::println("{} {} {}", sizeof(s1), sizeof(s2), sizeof(s3));
}
