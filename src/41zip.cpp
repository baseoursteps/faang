#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string
zip(const string &orig)
{
    stringstream ss;

    for (size_t i = 0; i < orig.size() - 1; ++i) {
        size_t j;
        for (j = i + 1; j < orig.size(); ++j) {
            if (orig.at(i) != orig.at(j)) {
                break;
            }
        }

        ss << orig.at(i) << j - i;
        i = j - 1;
    }

    if (ss.str().size() < orig.size())
        return ss.str();
    else
        return orig;
}

int
main()
{
    string meh { "aabcccccaaa" };
    cout << zip(meh) << "\n";
}
