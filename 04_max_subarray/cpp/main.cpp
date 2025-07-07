#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <limits>

namespace rng = std::ranges;
namespace vws = std::ranges::views;

int maxSubArray(std::vector<int>& nums) {
  std::vector<int> k;

  std::inclusive_scan(nums.cbegin(), nums.cend(), std::back_inserter<>(k), [] (auto acum, auto x) {
                                                                             if (x > acum+x) {
                                                                               return x;
                                                                             } else {
                                                                               return acum + x;
                                                                             }
                                                                           });
  
  return *std::max_element(k.cbegin(), k.cend());
}

int maxSubArray2(std::vector<int>& nums) {
  auto cum_view = nums | vws::transform([acum = 0] (auto x) mutable {
    acum = x + acum * (x <= acum+x);
    return acum;
  });

  auto max = rng::fold_left(cum_view, std::numeric_limits<int>::min(), [](auto x, auto y) { return std::max(x,y);});

  return max;
}

int main() {
  auto v = std::vector<int>{-2,1,-3,4,-1,2,1,-5,4};
  auto v2 = std::vector<int>{1};
  auto v3 = std::vector<int>{5,4,-1,7,8};
  auto v4 = std::vector<int>{1,2};
  

  std::cout << maxSubArray2(v4) << "\n" ; // 3
  std::cout << maxSubArray2(v) << "\n" ; // 6
  std::cout << maxSubArray2(v2) << "\n" ; // 1
  std::cout << maxSubArray2(v3) << "\n" ; // 23

  
}
