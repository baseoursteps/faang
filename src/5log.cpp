#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <sys/types.h>
#include <vector>

// Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit
// dig","let3 art zero"]

// Output: ["let1 art can","let3 art zero","let2 own kit
// dig","dig1 8 1 5 1","dig2 3 6"]

bool
is_numeric(const std::string& words)
{

  auto cmp = [](char c) { return std::isspace(c); };

  auto firsts = std::find_if(words.begin(), words.end(), cmp);

  if (firsts == std::end(words))
    throw std::runtime_error("vector is truncated");

  auto lasts = std::find_if(firsts + 1, words.end(), cmp);

  if (lasts == std::end(words))
    throw std::runtime_error("vector is truncated");

  return std::all_of(
    firsts + 1, lasts, [](const auto c) { return std::isdigit(c); });
}

int
main()
{

  using namespace std;
  vector<string> logs{ "dig1 8 1 5 1",
                       "let1 art can",
                       "dig2 3 6",
                       "let2 own kit dig",
                       "let3 art zero" };

  // 1. move all numeric logs to the back
  ssize_t start = logs.size() - 1;

  while (start != 0) {
    ssize_t alphai = -1, numerici = -1;
    for (auto i = start; i >= 0; i--) {
      if (is_numeric(logs.at(i))) {
        if (numerici == -1)
          numerici = i;
      } else {
        if (alphai == -1)
          alphai = i;
      }
    }

    if (alphai != -1 && numerici != -1) {
      swap(logs.at(alphai), logs.at(numerici));
      start--;
    }

    if (alphai == start && numerici == -1)
      break;

    if (alphai == -1 && numerici == start)
      break;
  }

  // 2. sort alphanumeric at the beginning
  // start is now the end index of alpha numerics
  auto sort = [](const auto& s1, const auto& s2) {
    auto cmp = [](char c) { return std::isspace(c); };
    auto f1 = std::find_if(s1.begin(), s1.end(), cmp);
    auto f2 = std::find_if(s2.begin(), s2.end(), cmp);

    auto r1 = std::string(f1, s1.end());
    auto k1 = std::string(s1.begin(), f1);

    auto r2 = std::string(f2, s2.end());
    auto k2 = std::string(s2.begin(), f2);

    if (r1 == r2)
      return k1 < k2;
    else
      return r1 < r2;
  };

  std::sort(logs.begin(), logs.begin() + start + 1, sort);

  for (const auto& c : logs)
    std::cout << c << "\n";

  return 0;
}
