#include <bitset>
#include <ios>
#include <iostream>

using namespace std;

template<size_t sz>
bitset<sz>
bates(std::bitset<sz> cells, size_t days)
{
  bitset<8> next(0);
  while (days-- != 0) {
    for (size_t i = 1; i < cells.size() - 1; ++i) {
      if (cells.test(i - 1) == cells.test(i + 1))
        next.set(i);
      else
        next.reset(i);
    }
    cells = next;
  }

  return cells;
}

int
main()
{
  size_t days = 7;

  bitset<8> cells{ "01011001" };

  auto val = bates(cells, days);

  cout << cells.to_string() << " -> " << val << "\n";

  return 0;
}
