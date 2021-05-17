#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int
main()
{
    const vector<int> elems { 12, 15, 22, 9, 7, 2, 18, 23, 27 };
    vector<int>       out; // 15 22 23 18 18 18 23 27 -1

    // O(n²)
    for (size_t i = 0; i < elems.size(); ++i) {
        auto   el = elems.at(i);
        size_t j;

        for (j = i; j < elems.size(); ++j) {
            if (elems.at(i) < elems.at(j)) {
                out.push_back(elems.at(j));
                break;
            }
        }
        if (j == elems.size())
            out.push_back(-1);
    }

    for (const auto &e : out) {
        cout << e << " ";
    }

    puts("");

    return 0;
}
