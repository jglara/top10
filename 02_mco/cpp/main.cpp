#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>


namespace rng = std::ranges;
namespace vws = std::views;

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    std::vector<int> cum_ones{};
    std::inclusive_scan(nums.cbegin(), nums.cend(), std::back_inserter<>(cum_ones), [] (auto acum, auto x) {

        return (acum+1) * x;

    });

    return *std::max_element(cum_ones.cbegin(), cum_ones.cend());
}


int mco(std::vector<int>& nums) {
    auto cum = nums | vws::transform([cum_ones = 0] (const auto &x) mutable {
        cum_ones = (cum_ones+1) * x;
        return cum_ones;
    });

    return rng::fold_left(cum, 0, [](auto x, auto y) { return std::max(x,y); });
}

int mco2(std::vector<int>& nums) {
    auto grouped = nums | vws::chunk_by(rng::equal_to{}) | vws::transform([] (auto &&rng) {        
        return rng::fold_left(rng, 0, std::plus<>());        
    });
    
    return *rng::max_element(grouped);
}


int main()
{
    auto v = std::vector<int>{1,1,0,1,1,1};
    std::cout << findMaxConsecutiveOnes(v) << "\n";
    std::cout << mco(v) << "\n";    
    std::cout << mco2(v)  << "\n";
}
