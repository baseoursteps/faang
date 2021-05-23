#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int
sum_intervals(std::vector<std::pair<int, int>> &intervals)
{
    int sum { 0 };
    if (intervals.empty()) {
        return sum;
    }

    // sort them
    std::sort(intervals.begin(), intervals.end(), [](auto &i, auto &j) {
        return std::get<0>(i) < std::get<0>(j);
    });

    // merge them
    for (int i = 0; i < intervals.size() - 1; ++i) {
        auto &&[os, oe] = intervals.at(i);
        for (int j = i + 1; j < intervals.size();) {
            auto &&[s, e] = intervals.at(j);
            if (s >= os && s <= oe) {
                oe = std::max(oe, e);
                intervals.erase(intervals.begin() + j);
                continue;
            } else
                j++;
        }
    }

    // count them
    for (auto &&[s, e] : intervals) {
        sum += (e - s);
    }

    return sum;
}

int
main()
{
    std::vector<std::pair<int, int>> pairs { { 1, 5 },
                                             { 6, 10 },
                                             { 2, 5 },
                                             { 9, 11 } };

    std::cout << sum_intervals(pairs) << "\n";

    return 0;
}
