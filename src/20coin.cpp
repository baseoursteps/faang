#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <sys/types.h>
#include <vector>

using namespace std;

int
main(int argc, char *argv[])
{
    vector<size_t>      coins { 1, 10, 50, 5, 500, 100 };
    map<size_t, size_t> comb;

    size_t amount = 69;
    if (argc >= 2)
        amount = strtoul(argv[1], nullptr, 10);

    ssize_t current = amount;

    sort(coins.begin(), coins.end(), std::greater<size_t>());

    bool done = false;
    for (size_t i = 0; i < coins.size() && !done;) {
        ssize_t rez = current - coins.at(i);

        if (rez < 0) {
            i++;
            continue;
        } else if (rez == 0)
            done = true;

        current = rez;
        comb[coins.at(i)]++;
    }

    cout << "for amount " << amount << " we need:"
         << "\n";

    for (auto &&[k, v] : comb)
        cout << "\t" << k << ":" << v << "\n";

    return 0;
}
