#include <functional>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

int sushi(std::vector<int> &nums) {
  std::vector<int> s;

  auto prev = nums.cbegin();
  auto ptr = std::adjacent_find(nums.cbegin(), nums.cend(), std::not_equal_to<>());
  for (;ptr != nums.cend();) {
    ptr = std::next(ptr);
    s.push_back( std::distance(prev,ptr) );
    prev = ptr;
    ptr = std::adjacent_find(ptr, nums.cend(), std::not_equal_to<>());
    
  }
  s.push_back( std::distance(prev,ptr) );

  std::adjacent_difference(s.cbegin(), s.cend(), s.begin(), [] (auto x, auto y) { return std::min(x,y);});

  return 2 * *std::max_element(std::next(s.cbegin()), s.cend());
                            
  
}

int main() {
  auto v = std::vector<int>{2, 2, 2, 1, 1, 2, 2};
  auto v2 = std::vector<int>{1, 2, 1, 2, 1, 2};
  auto v3 = std::vector<int>{2, 2, 1, 1, 1, 2, 2, 2, 2};

  std::cout << sushi(v3) << "\n"; // 6
  std::cout << sushi(v) << "\n"; // 4
  std::cout << sushi(v2) << "\n"; // 2

}
