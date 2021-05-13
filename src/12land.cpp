#include <cstdio>
#include <iostream>
#include <vector>

void
resetNeighbors(std::vector<std::vector<bool>> &vals, ssize_t i, ssize_t j)
{
    if (i >= vals.size() || i < 0 || j >= vals.at(0).size() || j < 0)
        return;

    if (!vals[i][j])
        return;

    vals[i][j] = 0;
    resetNeighbors(vals, i, j - 1);
    resetNeighbors(vals, i, j + 1);
    resetNeighbors(vals, i - 1, j);
    resetNeighbors(vals, i + 1, j);
}

int
main()
{
    // // 7
    // std::vector<std::vector<bool>> map{ { 1, 0, 0, 0, 1 },
    //                                     { 0, 0, 1, 1, 0 },
    //                                     { 1, 1, 1, 0, 1 },
    //                                     { 0, 0, 0, 1, 0 },
    //                                     { 1, 1, 0, 0, 1 } };

    // 5
    std::vector<std::vector<bool>> map { { 1, 0, 0, 0, 1 },
                                         { 0, 0, 1, 1, 1 },
                                         { 1, 1, 1, 0, 1 },
                                         { 0, 0, 0, 1, 0 },
                                         { 1, 1, 0, 0, 1 } };

    // // 8
    // std::vector<std::vector<bool>> map{ { 1, 0, 0, 0, 1 },
    //                                     { 0, 0, 1, 1, 0 },
    //                                     { 1, 1, 0, 0, 1 },
    //                                     { 0, 0, 0, 1, 0 },
    //                                     { 1, 1, 0, 0, 1 } };

    size_t count = 0;
    for (ssize_t i = 0; i < map.size(); i++) {
        for (ssize_t j = 0; j < map.at(0).size(); j++) {
            if (map[i][j]) {
                resetNeighbors(map, i, j);
                count++;
            }
        }
    }

    std::cout << count << "\n";

    return 0;
}
