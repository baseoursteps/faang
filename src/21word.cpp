#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// if searched item is empty() we have a full solution, print, return

// 1. go through dict and

// if > searched, continue

// if word <= searched return success, remove from dict

// create new string extracting from searched the current element

// push current to solution

// recurse with next index

// pop current from solution
void
search(const vector<string>& dict,
       size_t index,
       const string& searched,
       vector<string>& solution)
{
  if (searched.empty()) {
    cout << "found solution from: ";
    for (auto&& w : solution)
      cout << w << " ";

    cout << "\n";
    return;
  }

  for (size_t i = index; i < dict.size(); ++i) {
    if (dict.at(i).size() > searched.size())
      continue;

    if (dict.at(i).size() <= searched.size()) {
      const auto& curr = dict.at(i);
      auto pos = searched.find(curr);

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

int
main()
{
  vector<string> sol;
  vector<string> dict{
    "horse", "pa", "eagle", "victual", "cicero", "mouse", "d"
  };
  const string s{ "mousepad" };

  search(dict, 0, s, sol);

  return 0;
}
