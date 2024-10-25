#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int maxGap(std::vector<int>& nums) {
    
    if (nums.size() < 2) return 0;
    std::sort(nums.begin(), nums.end());

    std::adjacent_difference(nums.cbegin(), nums.cend(), nums.begin(), std::minus<>());
    return *std::max_element(std::next(nums.cbegin()), nums.cend());
    
}

int main() {
    auto v = std::vector<int>{3, 6, 9, 1};
    auto v2 = std::vector<int>{1, 1, 1, 1};

    std::cout << maxGap(v) << "\n"; // 3
    std::cout << maxGap(v2) << "\n"; // 0
}
