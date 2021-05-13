#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <map>
#include <vector>

struct tpl
{
  std::map<size_t, std::int64_t> indeces;
  std::vector<int64_t> vals;

  tpl(size_t i, size_t j, size_t k)
  {
    indeces.insert({ 0, i });
    indeces.insert({ 1, j });
    indeces.insert({ 2, k });
  }

  tpl(size_t i, size_t j)
  {
    indeces.insert({ 0, i });
    indeces.insert({ 1, j });
    indeces.insert({ 2, -1 });
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
  map<int64_t, std::map<int64_t, int64_t>> vals;

  for (size_t i = 0; i < nos.size() - 1; i++)
    for (size_t j = 1; j < nos.size(); j++) {
      if (i == j)
        continue;

      sums.insert_or_assign(nos.at(i) + nos.at(j), tpl(i, j));
    }

  constexpr const int64_t x = 420;
  for (ssize_t i = 0; i < nos.size(); i++) {
    auto&& rez = sums.find(x - nos.at(i));

    if (rez != sums.end()) {
      auto j = rez->second.indeces.at(0);
      auto k = rez->second.indeces.at(1);
      if (i != j && i != k) {
        rez->second.indeces.at(2) = i;

        auto&& s = rez->second.vals;
        s = { nos.at(i), nos.at(j), nos.at(k) };

        sort(s.begin(), s.end());
        vals.insert({ s.at(0), {} });
        auto&& v = vals.at(s.at(0));
        v.insert({ s.at(1), s.at(2) });
      }
    }
  }

  for (auto&& i : vals)
    for (auto&& [j, k] : i.second)
      std::printf("found pair %ld %ld %ld \n", i.first, j, k);

  return 0;
}
