#include <algorithm>
#include <cstddef>
#include <iostream>
#include <print>
#include <ranges>
#include <string_view>

struct Splitter {
    std::string_view sv_;

    using value_type = std::string_view;
    using difference_type = ptrdiff_t;
    using size_type = size_t;

    Splitter(std::string_view sv) : sv_(sv) {}

    struct SplitIterator {
        std::string_view sv_;
        size_t beg_;
        size_t end_;

        using value_type = std::string_view;
        using difference_type = ptrdiff_t;
        using size_type = size_t;

        friend auto
        operator<=>(const SplitIterator &a, const SplitIterator &b) = default;

        value_type
        operator*() const noexcept
        {
            return std::string_view(sv_ | std::views::drop(beg_) | std::views::take(end_ - beg_));
        }

        SplitIterator &
        operator++() noexcept
        {
            auto r = sv_ | std::views::drop(end_) | std::views::enumerate | std::views::drop_while([](auto p) {
                         return std::get<1>(p) == ' ';
                     }) |
                     std::ranges::views::take_while([](auto p) {
                         return std::get<1>(p) != ' ';
                     }) |
                     std::views::transform([](auto p) {
                         return std::get<0>(p);
                     });

            if (!r.empty()) {
                auto [m1, m2] = std::ranges::minmax(r);
                beg_ = end_ + m1;
                end_ = end_ + m2;
            } else {
                beg_ = sv_.size();
                end_ = sv_.size();
            }
            return *this;
        }

        SplitIterator &
        operator++(int) noexcept
        {
            auto *tmp = this;
            ++(*this);
            return *tmp;
        }
    };

    SplitIterator
    begin() const noexcept
    {
        auto r = sv_ | std::views::enumerate | std::views::drop_while([](auto p) {
                     return std::get<1>(p) == ' ';
                 }) |
                 std::ranges::views::take_while([](auto p) {
                     return std::get<1>(p) != ' ';
                 }) |
                 std::views::transform([](auto p) {
                     return std::get<0>(p);
                 });

        if (!r.empty()) {
            auto [m1, m2] = std::ranges::minmax(r);
            return {sv_, static_cast<size_t>(m1), static_cast<size_t>(m2 + 1)};
        } else {
            return end();
        }
    }

    SplitIterator
    end() const noexcept
    {
        return {sv_, sv_.size(), sv_.size()};
    }
};


static_assert(std::ranges::range<Splitter>);


int
main()
{
    std::string s;
    std::getline(std::cin, s);

    for (auto sv: Splitter(s)) {
        std::println("{}", sv);
    }
}
