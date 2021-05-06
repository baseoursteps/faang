#include "heap.h"
#include "utils.h"
#include <cstdlib>
#include <iostream>
#include <vector>

int
main()
{

  std::vector<int> vals;

  std::srand(time(0));
  constexpr const auto kth{ 34 };

  for (int i = -100; i < 100; i++) {
    auto repeat = std::abs(rand()) % 5;
    for (int r = 0; r < 1; r++) {
      if (vals.size() < kth - 1)
        vals.push_back(i);
      else if (vals.size() == kth - 1) {

        vals.push_back(i);

        // build heap from last leaf
        for (int i = vals.size() / 2 - 1; i >= 0; i--)
          heapify(vals, vals.size(), i, false);

        std::cout << kth << " max is: " << vals.front() << "\n";
      } else {
        // if the newest element is bigger than the root (kth largest) replace
        // and heapify
        if (i > vals.front()) {
          vals.at(0) = i;
          heapify(vals, vals.size(), 0, false);
        }
        std::cout << kth << " max is: " << vals.front() << "\n";
      }
    }
  }

  return 0;
}
