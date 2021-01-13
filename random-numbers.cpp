#include <iostream>
#include <random>
#include <utility>
#include <vector>
#include <thread>
#include <numeric>
#include <future>

typedef std::pair<double, double> position;

double getRandom()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(gen);
}

const double euclidean(const std::pair<const double, const double> &p)
{
    return (p.first * p.first) + (p.second * p.second);
}

const double get_pi(const int &n)
{
    double circle = 0;
    double square = 0;
    for (size_t i = 0; i < n; i++)
    {
        const double distance = euclidean(std::make_pair(getRandom(), getRandom()));
        if (distance <= 1)
        {
            circle += 1;
        }
        square += 1;
    }
    std::cout << (4 * circle) / square << "\n";
    return (4 * circle) / square;
}

int main()
{
    int t = 10;     // Number of instances
    int n = 100000; // Number of points

    std::vector<double> pi;

    for (size_t i = 0; i < t; i++)
    {
        std::future<double> f = std::async(get_pi, n);
        pi.push_back(f.get());
    }
    std::cout << std::fixed << std::accumulate(pi.begin(), pi.end(), decltype(pi)::value_type(0)) / 100;
    std::endl(std::cout);
}
