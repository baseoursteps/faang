#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int
main()
{

  const vector<string> words{ "eat", "tea", "tan", "ate", "nat", "bat" };

  // for each word split into a vector of chars and sort

  // keep a map of sorted word chars -> vector of words

  map<vector<char>, vector<string>> grouped;

  for (auto&& w : words) {
    vector<char> chars(w.begin(), w.end());
    sort(chars.begin(), chars.end());

    auto&& f = grouped.find(chars);

    if (f != grouped.end()) {
      f->second.push_back(w);
    } else {
      grouped.insert({ chars, { w } });
    }
  }

  for (auto&& [k, v] : grouped) {
    for (auto&& w : v) {
      cout << "'" << w << "' ";
    }
    cout << "\n";
  }

  return 0;
}
