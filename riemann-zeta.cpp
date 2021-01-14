#include <iostream>
#include <functional>
#include <cmath>
#include <numbers>

int main()
{
    std::function<long double(int, int)> riemann_zeta = [](int n, int s) constexpr
    {
        long double d = (1 / std::pow(n, s));
        return d;
    };
    int i = 1, n = 10000;
    long double sum = 0;
    int s = 4;
    while (i < n)
    {
        sum += riemann_zeta(i, s);
        i++;
    }
    long double pi;
    if (s == 2)
        pi = std::sqrt(sum * 6);
    else if (s == 4)
    {
        pi = std::pow(sum * 90, 0.25);
    }

    std::cout.precision(17);
    std::cout << std::fixed << pi << std::endl;
    std::cout << std::numbers::pi << std::endl;
    std::cout << std::numbers::pi - pi << std::endl;
}