#include <iostream>
#include "heap.h"

int
main()
{
  using namespace std;
  vector<int> vals{ 3, 1, 2, 4, 5, 2, 5, 7, 4, 2, 5, 8, 10 };
  heapsort(vals);

  for (auto&& i : vals)
    std::cout << i << " ";

  puts("");

  return 0;
}
