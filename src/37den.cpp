#include <cmath>
#include <iostream>
#include <numeric>

// this solution is beyond my comprehension...the obvious way would be to go
// from 1 to den and check if gcd(i,den)==1
long
proper(long den)
{
    if (den < 2)
        return 0;

    auto count = den;

    for (auto i = 2; i <= std::sqrt(den); ++i) {
        if (den % i == 0) {
            // count = count / i * (i - 1);
            count -= count / i;

            while (den % i == 0) {
                den /= i;
            }
        }
    }

    if (den > 1) {
        // count = count / den * (den - 1);
        count -= count / den;
    }

    return count;
}

long
plebProper(long den)
{
    if (den < 2)
        return 0;

    size_t count { 1 };
    for (auto i = 2; i < den; ++i) {
        if (den % i == 0)
            continue;

        if (std::gcd(i, den) == 1) {
            ++count;
        }
    }

    return count;
}

int
main()
{
    for (auto &&i : { 99, 999, 999'999, 9'999'999 }) {
        std::cout << "smart: " << proper(i) << "\n";
        std::cout << "pleb : " << plebProper(i) << "\n";
    }

    return 0;
}
