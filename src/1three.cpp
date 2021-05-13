#include <algorithm>
#include <bits/stdint-intn.h>
#include <cstdint>
#include <cstdio>
#include <map>
#include <set>
#include <vector>

struct tpl
{
  std::vector<int64_t> vals;
  tpl(size_t i, size_t j)
  {
    vals.push_back(i);
    vals.push_back(j);
  }
};

int
main()
{
  using namespace std;

  vector<int64_t> nos;
  for (int i = -1000; i <= 1000; i++)
    nos.push_back(i);

  map<int64_t, tpl> sums;
  set<vector<int64_t>> setty;

  for (size_t i = 0; i < nos.size() - 1; i++)
    for (size_t j = 1; j < nos.size(); j++) {
      if (i == j)
        continue;

      sums.insert({ nos.at(i) + nos.at(j), tpl(i, j) });
    }

  constexpr const int64_t x = 420;
  for (ssize_t i = 0; i < nos.size(); i++) {
    auto&& rez = sums.find(x - nos.at(i));

    if (rez != sums.end()) {
      auto& items = rez->second.vals;
      auto j = items.at(0);
      auto k = items.at(1);

      if (i != j && j != k) {
        items.push_back(i);
        setty.insert(items);
      }
    }
  }

  std::printf("found pairs: \n");
  for (auto&& i : setty) {
    std::printf(
      "\t%ld %ld %ld\n", nos.at(i.at(0)), nos.at(i.at(1)), nos.at(i.at(2)));
  }

  return 0;
}
