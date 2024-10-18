#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    std::vector<int> cum_ones{};
    std::inclusive_scan(nums.cbegin(), nums.cend(), std::back_inserter<>(cum_ones), [] (auto acum, auto x) {

        return (acum+1) * x;

    });

    return *std::max_element(cum_ones.cbegin(), cum_ones.cend());
}


int main()
{
    auto v = std::vector<int>{1,1,0,1,1,1};
    std::cout << findMaxConsecutiveOnes(v) << "\n";
}