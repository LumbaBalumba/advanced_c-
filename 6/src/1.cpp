#include <iostream>

class Pressure
{
    long double val_;

    constexpr Pressure(long double val) : val_(val) {}

    friend std::ostream &
    operator<<(std::ostream &out, const Pressure &p)
    {
        return out << p.val_;
    }

    friend constexpr Pressure
    operator"" _psi(long double val);

    friend constexpr Pressure
    operator"" _mmhg(unsigned long long val);
};

constexpr Pressure
operator"" _psi(long double val)
{
    return {val * 6894.75729};
}

constexpr Pressure
operator"" _mmhg(unsigned long long val)
{
    return {val * 133.322};
}
int
main()
{
    auto p1 = 14.696_psi;
    std::cout << p1 << std::endl;

    auto p2 = 760_mmhg;
    std::cout << p1 << std::endl;
}
