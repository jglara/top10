#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <list>
#include <ranges>
#include <string_view>

namespace rng = std::ranges;
namespace vws = std::views;

int trap(std::vector<int> &height)
{
    std::vector<int> left_cum_sum{};
    std::deque<int> right_cum_sum{};
    std::vector<int> water_level{};

    auto funmax = [](int x, int y)
    { return std::max(x, y); };
    std::partial_sum(height.cbegin(), height.cend(), std::back_inserter(left_cum_sum), funmax);
    std::partial_sum(height.crbegin(), height.crend(), std::front_inserter(right_cum_sum), funmax);

    std::transform(left_cum_sum.cbegin(), left_cum_sum.cend(), right_cum_sum.cbegin(), std::back_inserter(water_level), [](int x, int y)
                   { return std::min(x, y); });

    auto ret = std::transform_reduce(water_level.cbegin(), water_level.cend(), height.cbegin(), 0, std::plus<>(), std::minus<>());

    return ret;
}

// Better solution using ranges.

// Helper function to calculate trap water if last column is the higher
template <typename Range>
int trap_water_left(Range &&rng)
{
    int cummax{0};

    auto h = rng | vws::transform([&cummax](auto &&x)
                                  { cummax= std::max(cummax, x); return cummax; });

    return rng::fold_left(h, 0, std::plus<>()) - rng::fold_left(rng, 0, std::plus<>());
}

// Split the sequence in two, using the max element; 
// and then calculate water trap in each portion: in the right part reverse the sequence to use
// the same algo 
int trap_2(std::vector<int> &height)
{

    auto mid = rng::max_element(height);
    auto h_l = rng::subrange(height.begin(), mid);
    auto h_r = rng::subrange(mid, height.end()) | vws::reverse;

    return trap_water_left(h_l) + trap_water_left(h_r);
}

int main()
{
    auto v = std::vector<int>{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << trap_2(v) << "\n";

    auto v2 = std::vector<int>{4, 2, 0, 3, 2, 5};
    std::cout << trap_2(v2) << "\n";
}