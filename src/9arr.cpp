#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template<typename T>
std::vector<T>
kadane(const std::vector<T> &vals)
{
    size_t  best_start = 0, start = 0, end = 0, best_end = 0;
    ssize_t sum = vals.at(0), best = vals.at(0);

    for (size_t i = 1; i < vals.size(); ++i) {
        if (sum <= 0) {
            start = i;
            sum   = vals.at(i);
        } else
            sum += vals.at(i);

        if (sum > best) {
            best       = sum;
            best_start = start;
            best_end   = i;
        }
    }

    vector<int> maxv { vals.begin() + best_start, vals.begin() + best_end + 1 };

    return maxv;
}

template<typename T>
std::vector<T>
maxSubArr(const std::vector<T> &vals)
{
    auto        max = vals.at(0);
    vector<int> maxv { vals.at(0) };

    for (int i = 0; i < vals.size(); ++i)
        for (int j = i + 1; j <= vals.size(); ++j) {
            auto nmax = accumulate(vals.begin() + i, vals.begin() + j, 0);
            if (nmax > max) {
                max = nmax;
                maxv.assign(vals.begin() + i, vals.begin() + j);
            }
        }

    return maxv;
}

int
main()
{
    vector<int> vals { -1, 2, 3, 0, -20, 10, 4, -1, 0, 1, 11, 20, 0, 4 };

    auto maxv = maxSubArr(vals);

    for (auto &&c : maxv)
        cout << c << "  ";
    puts(" ");

    auto maxk = kadane(vals);

    for (auto &&c : maxk)
        cout << c << "  ";
    puts(" ");

    return 0;
}
