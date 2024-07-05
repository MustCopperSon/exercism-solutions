#include <iostream>
#include <ranges>
#include <algorithm>
using namespace std;

constexpr inline uint32_t year_start = 1582;
constexpr inline uint32_t year_end = 2300;

inline constexpr bool is_leap_year(int year) {
    return ((year % 4) == 0) ? ((year % 100) != 0)  || ((year % 400) == 0) : false;
}

int main()
{
    auto leaps = views::iota(year_start, year_end) | views::filter(is_leap_year);
    std::vector<int> ivec {leaps.begin(), leaps.end()};
    for(auto s : ivec)
      std::cout <<"leap year: " << s << "\n";

    return 0;
}
