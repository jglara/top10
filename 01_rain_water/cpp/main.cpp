#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>

int trap(std::vector<int> &height)
{
    std::vector<int> left_cum_sum{};
    std::deque<int> right_cum_sum{};
    std::vector<int> water_level{};

    auto funmax = [] (int x, int y) { return std::max(x,y); };
    std::partial_sum(height.cbegin(), height.cend(), std::back_inserter(left_cum_sum), funmax);
    std::partial_sum(height.crbegin(), height.crend(), std::front_inserter(right_cum_sum), funmax);

    std::transform(left_cum_sum.cbegin(), left_cum_sum.cend(), right_cum_sum.cbegin(), std::back_inserter(water_level), [] (int x, int y) {
        return std::min(x,y);
    });

    auto ret = std::transform_reduce(water_level.cbegin(), water_level.cend(), height.cbegin(), 0, std::plus<>(), std::minus<>());

    return ret;
}

int main()
{
    auto v = std::vector<int>{0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << trap(v) << "\n";
}