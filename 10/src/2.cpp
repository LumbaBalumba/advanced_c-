#include <print>
#include <ratio>
#include <type_traits>
#include <variant>
#include <vector>


class Rectangle
{
    double a{}, b{};

public:
    Rectangle(double a, double b) : a(a), b(b) {}

    double
    square() const noexcept
    {
        return a * b;
    }
};

class Square
{
    double a;

public:
    explicit Square(double a) : a(a) {}

    double
    square() const noexcept
    {
        return a * a;
    }
};

using Figure = std::variant<Rectangle, Square>;

int
main()
{
    std::vector<Figure> v;

    v.emplace_back(Rectangle(25, 15));
    v.emplace_back(Square(10));

    for (const auto &x: v) {
        std::visit(
                [](auto &&x) {
                    using T = std::decay_t<decltype(x)>;
                    if constexpr (std::is_same_v<T, Square>) {
                        std::println("Square: {}", x.square());
                    } else {
                        std::println("{}", x.square());
                    }
                },
                x);
    }
}
