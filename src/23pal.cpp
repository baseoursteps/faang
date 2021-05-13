#include <iostream>

using namespace std;

// find middle

// set counter to 0

// if middle falls on element increment counter

// start comparing elements to from the left and right of the middle
// incrementing counter by 2

// stop if we reach the ends or if any two elements differ

// if middle falls between two elements

// start comparing elements from middle and middle-1

// recurse to the left and to the right of middle

// return max(counter, left_recursion, right_recursion)
size_t
maxPal(const string &v, ssize_t start, ssize_t end)
{
    if (start == end)
        return 1;

    if (start > end)
        return 0;

    ssize_t mid = (start + end) / 2;

    // if middle falls on element check from middle+-1
    size_t count = 0;
    if ((start + end) % 2) {
        count = 1;
        for (int i = 1; i <= mid; i++) {
            if (mid - i < start || mid + i >= end)
                break;
            if (v.at(mid - i) == v.at(mid + i))
                count += 2;
            else
                break;
        }
    } else {
        for (int i = 0; i <= mid; i++) {
            if (mid - i - 1 < start || mid + i >= end)
                break;
            if (v.at(mid - i - 1) == v.at(mid + i))
                count += 2;
            else
                break;
        }
    }

    if (count >= mid)
        return count;

    auto nm = std::max(maxPal(v, start, mid), maxPal(v, mid + 1, end));

    return std::max(nm, count);
}

int
main()
{
    ////18
    // string meh("abcdefghiihgfedcba");
    ////3
    // string meh("aba");
    ////3
    // string meh("nababul");
    ////5
    // string meh("nababal");
    ////1
    // string meh("abc");
    //// 4
    // string meh("abaabbaall");
    ////0
    // string meh("");
    ////1
    // string meh(" ");
    //// 3
    string meh("abcevaba");

    cout << maxPal(meh, 0, meh.size()) << "\n";

    return 0;
}
