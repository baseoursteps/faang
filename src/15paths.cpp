#include <iostream>
#include <sys/types.h>
#include <vector>

// 0 1 0
// 0 0 1
// 0 0 0
// 2

// 0 0 0
// 0 1 0
// 0 0 0
// 2

// 0 0 0
// 0 0 0
// 0 0 0
// 12/6

using namespace std;

// start from a position

// return 0 if we're blocked

// return 0 if went over the map

// if reached destination return 1

// set it as visited (a)

// go in all others and increment count

// unset position (a)
size_t
navigate(vector<vector<bool>> map, ssize_t x, ssize_t y)
{
    if (x < 0 || x >= map.size() || y < 0 || y >= map.at(x).size())
        return 0;

    if (map.at(x).at(y))
        return 0;

    if (x == map.size() - 1 && y == map.at(x).size() - 1)
        return 1;

    size_t count    = 0;
    map.at(x).at(y) = 1;

    count += navigate(map, x + 1, y);
    count += navigate(map, x - 1, y);
    count += navigate(map, x, y + 1);
    count += navigate(map, x, y - 1);

    map.at(x).at(y) = 0;

    return count;
}

// THIS SOLUTION ASSUMES THAT WE CAN NAVIGATE ONLY DOWN AND TO THE RIGHT

// keep a same-sized matrix in which we count possible paths based on the fact
// that the destination is marked with one and each of its neighbors are the sum
// of itself and the other possible direction

// thus a cell (x,y) is the sum of the possible paths its right and down
// neighbors have towards the destination. (x,y) = (x,y+1) + (x+1, y)

// the downmost and rightmost margins are effectively 1

// then we continue towards the origin point adding on the way the possible
// paths

// the result shall be in the origin

// TODO Could this be modified to account for all directions?
size_t
navigateDp(const vector<vector<bool>> &map)
{
    vector<vector<size_t>> counts(map.size(),
                                  vector<size_t>(map.back().size(), 0));

    // the destination is 1
    counts.back().back() = 1;

    for (ssize_t i = map.size() - 1; i >= 0; --i)
        for (ssize_t j = map.at(i).size() - 1; j >= 0; --j) {
            size_t count = 0;

            // down
            if (i + 1 >= map.size() || map.at(i + 1).at(j))
                count += 0;
            else
                count += counts.at(i + 1).at(j);

            // right
            if (j + 1 >= map.at(i).size() || map.at(i).at(j + 1))
                count += 0;
            else
                count += counts.at(i).at(j + 1);

            // this is in order not to overwrite the destination
            if (!counts.at(i).at(j))
                counts.at(i).at(j) = count;
        }

    return counts.front().front();
}

int
main()
{
    // 2
    // vector<vector<bool>> map{ { 0, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 } };

    // 2
    vector<vector<bool>> map { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };

    // 12/6
    // vector<vector<bool>> map(3, vector<bool>(3, false));

    // first check if start and begin are accesible
    if (map.front().front() == 1 || map.back().back() == 1) {
        cout << 0 << "\n";
        return 0;
    }

    // return count

    // size_t count = navigate(map, 0, 0)

    size_t count = navigateDp(map);

    cout << count << "\n";

    return 0;
}
