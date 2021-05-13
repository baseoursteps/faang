#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int
main()
{
    using namespace std;

    string par, word;

    {
        ifstream in("./paragraph");

        if (!in.is_open()) {
            std::cerr << "paragraph file does not exist!\n";
            return 1;
        }
        in.seekg(0, std::ios::end);
        par.reserve(in.tellg());
        in.seekg(0, std::ios::beg);

        par.assign(istreambuf_iterator<char>(in), {});
    }

    stringstream   ss(par);
    vector<string> words;
    while (ss >> word)
        words.push_back(word);

    set<string> exclude({
        "some",
        "a",
        "with",
        "in",
        "at",
        "by",
        "why",
        "for",
        "of",
        "the",
        "and",
        "to",
    });

    map<string, size_t> count;

    auto max = count.begin();

    for (auto &&w : words) {
        if (exclude.find(w) == exclude.end()) {
            count[w]++;
            if (max != count.end()) {
                if (max->second < count.at(w))
                    max = count.find(w);
            } else
                max = count.find(w);
        }
    }

    if (max != count.end())
        std::cout << "max: '" << max->first << "':" << max->second << "\n";

    return 0;
}
