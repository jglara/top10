#include <iostream>
#include <vector>

#include <algorithm>
#include <numeric>
#include <unordered_map>

int maxGapCount(std::vector<int>& nums) {
    
    if (nums.size() < 2) return 0;
    std::sort(nums.begin(), nums.end());

    std::adjacent_difference(nums.cbegin(), nums.cend(), nums.begin(), std::minus<>());

    std::unordered_map<int, int> counts;
    std::for_each(nums.cbegin(), nums.cend(), [&counts] (auto x) {
        counts[x]++;
    });
    
    auto [max_gap, max_gap_count] = *std::max_element(counts.cbegin(), counts.cend(), [](auto x, auto y) { return x.first < y.first; });

    return max_gap_count;
    
}





int main() {
    auto v = std::vector<int>{2, 5, 8, 1};
    auto v2 = std::vector<int>{3};

    std::cout << maxGapCount(v) << "\n"; // 2
    std::cout << maxGapCount(v2) << "\n"; // 0
}
