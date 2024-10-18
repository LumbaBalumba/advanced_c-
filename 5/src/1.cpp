#include <algorithm>
#include <vector>

class A
{
    int *p;

    int &
    operator[](size_t idx) noexcept
    {
        return *p;
    }

    int &
    operator[](size_t i, size_t j) noexcept
    {
        return *p;
    }
};


int
main()
{
    std::vector v{3, 4, 2, 4, 3};

    std::sort(v.begin(), v.end());
}
