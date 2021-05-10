#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sys/types.h>
#include <vector>

using namespace std;

void
genComb(vector<map<size_t, size_t>>& all,
        map<size_t, size_t>& comb,
        const vector<size_t>& coins,
        size_t ci,
        ssize_t amount)
{

  if (amount < 0)
    return;

  if (amount == 0)
    all.push_back(comb);

  while (ci < coins.size() && coins.at(ci) > amount)
    ci++;

  for (size_t i = ci; i < coins.size(); i++) {
    auto& ccoin = comb[coins.at(i)];
    ccoin++;
    genComb(all, comb, coins, i, amount - coins.at(i));
    ccoin--;
  }
}

int
main(int argc, char* argv[])
{

  vector<size_t> coins{ 1, 10, 50, 5, 500, 100 };

  size_t amount = 17;
  if (argc >= 2)
    amount = strtoul(argv[1], nullptr, 10);

  sort(coins.begin(), coins.end(), std::greater<size_t>());

  map<size_t, size_t> current;

  vector<map<size_t, size_t>> all;

  size_t index = 0;
  genComb(all, current, coins, index, amount);

  cout << "for amount " << amount << " we need:"
       << "\n";

  for (auto&& c : all) {
    for (auto&& [k, v] : c)
      cout << "\t" << k << ":" << v << "\n";
    cout << "\n";
  }

  return 0;
}
