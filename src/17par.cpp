#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// start with open bracket

// if closed brackets are more than opened return 0

// if total number is equal to pairs *2

// if opened are not equal to closed return 0

// print and return 1

// append open

// recurse

// pop open

// append close

// recurse

// pop close

// return count
size_t
cpar(vector<char> &p, size_t open, size_t close, size_t pairs)
{
    if (p.empty()) {
        p.push_back('(');
        auto total = cpar(p, open + 1, close, pairs);
        p.pop_back();
        return total;
    }

    if (close > open)
        return 0;

    if (p.size() == pairs * 2) {
        if (open != close)
            return 0;

        for (auto &&par : p)
            cout << par << " ";

        cout << "\n";

        return 1;
    }

    p.push_back('(');
    auto count = cpar(p, open + 1, close, pairs);
    p.pop_back();

    p.push_back(')');
    count += cpar(p, open, close + 1, pairs);
    p.pop_back();

    return count;
}

int
main(int argc, char *argv[])
{
    size_t pairs = 4;
    if (argc >= 2)
        pairs = strtoul(argv[1], nullptr, 10);

    vector<char> pars;

    cout << cpar(pars, 0, 0, pairs) << "\n";

    return 0;
}
