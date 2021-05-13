#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

// the idea here is take each dictionary word and check if it's a substring of
// our searched word

// if it is we create a new search string by cutting the dictionary word and
// recursing to the next

// if searched item is empty() we have a full solution, print, return

// 1. go through dict and

// if > searched, continue

// if word <= searched return success, remove from dict

// create new string extracting from searched the current element

// push current to solution

// recurse with next index

// pop current from solution
void
search(const vector<string> &dict,
       size_t                index,
       const string &        searched,
       vector<string> &      solution)
{
    if (searched.empty()) {
        cout << "found solution from: ";
        for (auto &&w : solution)
            cout << w << " ";

        cout << "\n";
        return;
    }

    for (size_t i = index; i < dict.size(); ++i) {
        if (dict.at(i).size() > searched.size())
            continue;

        if (dict.at(i).size() <= searched.size()) {
            const auto &curr = dict.at(i);
            auto        pos  = searched.find(curr);

            if (pos != searched.npos) {
                string sub(searched.begin(), searched.begin() + pos);
                sub += { searched.begin() + pos + curr.size(), searched.end() };
                solution.push_back(curr);
                search(dict, i, sub, solution);
                solution.pop_back();
            }
        }
    }
}

// this works in a slightly different approch

// we start with substrings of searched word from index I 0 to size
// incrementally

// if the index I is cached as true it means the solution is possible and
// start another subtring search from I+1

// the new substring shall be from J= I + 1 up to size

// we repeat this second substring search while index J is smaller than
// size and the dictionary contains it

// if J reaches size it means we have a solution

// otherwise continue first substring search using I

// the trick is that an incremented I could very well match the cache because of
// the J search

// magic
void
searchDp(const vector<string> &dict, const string &searched)
{
    if (searched.empty())
        return;

    vector<string> solution;

    map<size_t, bool> indeces;

    set<string> nd(dict.begin(), dict.end());

    for (size_t i = 1; i <= searched.size(); ++i) {
        string curr(searched.begin(), searched.begin() + i);

        if (!indeces[i]) {
            if (nd.find(curr) != nd.end()) {
                indeces[i] = true;
                solution.push_back(curr);
            }
        }

        if (indeces[i]) {
            if (i == searched.size()) {
                cout << "found solution:";
                for (auto &&w : solution)
                    cout << w << " ";
                cout << "\n";
                return;
            }

            for (size_t j = i + 1; j <= searched.size(); ++j) {
                if (!indeces[j]) {
                    string next(searched.begin() + i, searched.begin() + j);

                    if (nd.find(next) != nd.end()) {
                        indeces[j] = true;
                        solution.push_back(next);
                    }

                    if (j == searched.size() && indeces[j]) {
                        cout << "found solution:";
                        for (auto &&w : solution)
                            cout << w << " ";
                        cout << "\n";

                        return;
                    }
                }
            }
        }
    }

    return;
}

int
main()
{
    vector<string> sol;
    vector<string> dict { "horse",  "pa",    "eagle", "victual",
                          "cicero", "mouse", "d" };
    const string   s { "mousepad" };

    search(dict, 0, s, sol);

    searchDp(dict, s);

    return 0;
}
