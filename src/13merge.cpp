#include <algorithm>
#include <iostream>
#include <vector>

struct interval
{
    int start { -1 }, end { -1 };
    interval(int a, int b) : start(a), end(b) {}
    bool
    operator<(const interval &o) const
    {
        return start < o.start;
    }
};

int
main()
{
    using namespace std;

    vector<interval> vals { { 11, 15 }, { 1, 3 },  { 0, 2 },  { 3, 5 },
                            { 6, 8 },   { 9, 10 }, { 16, 20 } };

    for (auto &&i : vals)
        cout << i.start << "->" << i.end << "\n";

    sort(vals.begin(), vals.end());

    for (int i = 0; i < vals.size() - 1;) {
        if (vals[i].end >= vals[i + 1].start) {
            vals[i].end = vals[i + 1].end;
            vals.erase(vals.begin() + i + 1);
        } else
            ++i;
    }

    cout << "\nMerged:\n";
    for (auto &&i : vals)
        cout << i.start << "->" << i.end << "\n";

    return 0;
}
