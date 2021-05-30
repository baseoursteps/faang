#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool
one_way(const string &a, const string &b)
{
    if (a == b)
        return true;

    ssize_t dif = ssize_t(a.size()) - b.size();
    dif         = abs(dif);

    if (dif > 1)
        return false;

    auto ia = a.begin();
    auto ib = b.begin();

    auto change = 0;

    while (ia != a.end() && ib != b.end()) {
        if (*ia != *ib) {
            if (!change)
                change++;
            else
                return false;

            if (dif) {
                if (a.size() < b.size()) {
                    ib++;
                    continue;
                } else {
                    ia++;
                    continue;
                }
            }
        }

        ia++;
        ib++;
    }

    return true;
}

int
main()
{
    for (auto &&[a, b] : vector<pair<string, string>>({ { "pale", "ple" },
                                                        { "pales", "pale" },
                                                        { "pale", "bale" },
                                                        { "pale", "bake" } })) {
        cout << a << (one_way(a, b) ? " ~= " : " != ") << b << "\n";
    }
}
