#include <algorithm>
#include <iostream>
#include <iterator>
#include <print>
#include <ranges>
#include <vector>

int
main()
{
    auto vi = std::views::istream<int>(std::cin) | std::ranges::to<std::vector<int>>();

    std::ranges::copy(vi, std::ostream_iterator<int>(std::cout, "\n"));
}
