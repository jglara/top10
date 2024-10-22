#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

int main() {
  auto v = std::vector<int>{-2,1,-3,4,-1,2,1,-5,4};
  auto v2 = std::vector<int>{1};
  auto v3 = std::vector<int>{5,4,-1,7,8};
  auto v4 = std::vector<int>{1,2};
  

  std::cout << maxSubArray(v4) << "\n" ; // 3
  std::cout << maxSubArray(v) << "\n" ; // 6
  std::cout << maxSubArray(v2) << "\n" ; // 1
  std::cout << maxSubArray(v3) << "\n" ; // 23

  
}
