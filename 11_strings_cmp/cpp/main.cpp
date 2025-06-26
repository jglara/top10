#include <iostream>
#include <vector>
#include <ranges>
#include <string_view>

namespace rng = std::ranges;
namespace vws = std::views;

bool cmp(std::string_view s1, std::string_view s2)
{

    constexpr auto filter_spaces = [](char x) { return !std::isspace(x); };

    return rng::equal(s1 | vws::filter(filter_spaces),
                      s2 | vws::filter(filter_spaces));
}

int main()
{
    using test_case = std::tuple<std::string_view, std::string_view, bool>;

    test_case tests[] = {
        {"one two three", "o n e t w o t h re e   ", true},
        {"one two three     5", "o n e t w o t h re e   ", false},
    };

    for (const auto &[s1, s2, ret] : tests)
    {
        std::cout << cmp(s1, s2) << " expecting " << ret << "\n";
    }
}