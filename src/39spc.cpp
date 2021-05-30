#include <cctype>
#include <iostream>
#include <string>

using namespace std;

void
urlify(string &str, size_t len)
{
    for (auto i = 0; i < len; ++i) {
        if (!isspace(str.at(i)))
            continue;

        // shift to the right
        string chunk(str.begin() + i + 1, str.begin() + len + 1);
        for (auto j = 0; j < chunk.size(); ++j) {
            str.at(i + j + 3) = chunk.at(j);
        }

        // add %20
        str.at(i)     = '%';
        str.at(i + 1) = '2';
        str.at(i + 2) = '0';

        // increment i with 2
        i += 2;

        // increment len with 2
        len += 2;
    }
}

int
main()
{
    string val { "hello world or not...? " };

    const auto sz = val.size();

    val.resize(sz * 2);

    urlify(val, sz);

    cout << val << "\n";
}
