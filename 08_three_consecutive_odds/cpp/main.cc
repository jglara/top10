#include <iostream>
#include <vector>
#include <ranges>


namespace rng = std::ranges;
namespace vws = std::ranges::views;


bool threeConsecutiveOdds(std::vector<int>& arr) {
    auto v = arr | vws::transform([]( auto x){ return x&1;}) | vws::adjacent_transform<3>([] (auto x, auto y, auto z) {
        return x+y+z;
    });

    return rng::find(v, 3) != v.end();
        
}

int main()
{
    std::vector v{2,6,4,1}; // true
    std::vector v2{1,2,34,3,4,5,7,23,12}; // false

    std::cout << threeConsecutiveOdds(v) << "\n"; // false
    std::cout << threeConsecutiveOdds(v2) << "\n"; // true

}