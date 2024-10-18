#include <algorithm>
#include <print>
#include <ranges>
#include <vector>

int
main()
{
    std::vector v{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    // static_assert(std::ranges::range<std::vector<int>>);

    // std::sort(v.begin(), v.end());

    // std::ranges::sort(v);
    //

    // std::ranges::sort(v | std::views::reverse);

    std::ranges::sort(v | std::views::drop(2) | std::views::take(4));


    for (auto &elem: v) {
        std::println("{}", elem);
    }
}
