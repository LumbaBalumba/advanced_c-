#include <memory>
#include <print>
#include <vector>

class Figure
{
public:
    virtual ~Figure() {}

    virtual double
    square() const noexcept = 0;
};

class Rectangle : public Figure
{
    double a{}, b{};

public:
    Rectangle(double a, double b) : a(a), b(b) {}

    double
    square() const noexcept override
    {
        return a * b;
    }
};

class Square : public Figure
{
    double a;

public:
    Square(double a) : a(a) {}


    double
    square() const noexcept override
    {
        return a * a;
    }
};

int
main()
{
    std::vector<std::unique_ptr<Figure>> v;
    v.emplace_back(std::make_unique<Square>(10));
    v.emplace_back(std::make_unique<Rectangle>(10, 20));
    v.emplace_back(std::make_unique<Square>(30));

    for (const auto &elem: v) {
        std::println("{}", elem->square());
    }
}
