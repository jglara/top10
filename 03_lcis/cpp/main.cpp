#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>



int findLengthOfLCIS(std::vector<int>& nums) {
    std::vector<int> d;

    if (nums.size() < 2) return nums.size();
    

    std::adjacent_difference(nums.cbegin(), nums.cend(), std::back_inserter<>(d), [] (auto x, auto y) {
        return y<x?1:0;
    });

    std::inclusive_scan(std::next(d.cbegin()), d.cend(), d.begin(), [] (auto acum, auto x) {
        return (acum+1)*x;
    });

    return *std::max_element(d.cbegin(), std::prev(d.cend()))+1;
        
}


int main() {

    auto v3 = std::vector<int>{1};

    auto v = std::vector<int>{1,3,5,4,7};
    auto v2 = std::vector<int>{2,2,2,2};

   std::cout << findLengthOfLCIS(v3) << "\n";
    std::cout << findLengthOfLCIS(v) << "\n";
    std::cout << findLengthOfLCIS(v2) << "\n";
}
