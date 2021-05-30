#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// a lot of trial and error tbh
// the kind of algorithm you 'invent' on the spot
void
rotate(vector<vector<int>> &mat)
{
    if (mat.size() != mat.front().size())
        return;

    for (size_t l = 0; l < mat.size(); ++l) {
        // // swap preceding
        if (l <= mat.size() / 2) {
            for (auto i = 0; i < l; ++i) {
                swap(mat.at(i).at(l), mat.at(i).at(mat.size() - l - 1));
            }
        }

        // // swap on current
        // // put first elements to the back on the same line
        for (auto i = 0; i <= min(l, mat.size() / 2); ++i) {
            swap(mat.at(l).at(i), mat.at(l).at(mat.size() - i - 1));
        }

        // // swap current line with previous columns
        // // bring elements from previous lines to their new column position
        for (auto i = 0; i < l; ++i) {
            swap(mat.at(i).at(mat.size() - l - 1),
                 mat.at(l).at(mat.size() - i - 1));
        }
    }
}

// line 1
// 5 2 3 4 1  // swap a[0][0] with a[0][n-1]
//...

// line 2
//  5 2 3 4  1
//  5 4 3 2  1   swap a[0][1] a[0][n-2]
//
//  6 9 8 7 10   swap a[1][1] a[1][n-2]
//
//  10 9 8 7 6   swap a[1][0] a[1][n-1]
//
//  5 4 3 6 1    swap a[0][n-2] a[1][n-1]
// 10 9 8 7 2
//
//...

// line 3
//  5 4 3 6 1 swap a[0][2]   a[0][n-3]
//
// 10 9 8 7 2 swap a[1][2]   a[1][n-3]
//
// 15 12 13 14 11  swap a[2][n-1] a[2][0]

// 15 14 13 12 11  swap a[2][n-2] a[2][1]

// 15 14 13 12 11 swap a[2][n-3] a[2][2]

// 5 4 11 6 1  swap a[0][2] a[2][n-1]
// ..
// 15 14 13 12 3

// swap a[1][2] a[2][n-2]
// 10 9 12 7 2
// 15 14 13 8 3

int
main()
{
    // clang-format off
    vector<vector<int>> mat { {  1,  2,  3,  4,  5 },
                              {  6,  7,  8,  9, 10 },
                              { 11, 12, 13, 14, 15 },
                              { 16, 17, 18, 19, 20 },
                              { 21, 22, 23, 24, 25 } };

    // clang-format on
    rotate(mat);

    for (const auto &l : mat) {
        for (const auto &el : l) {
            cout << el << " ";
        }
        cout << "\n";
    }
}
