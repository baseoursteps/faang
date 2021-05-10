#include "heap.h"
#include <cstdio>
#include <deque>
#include <iostream>

// keep a min heap

// while there's at least one element

// pop front

// heapify

// add popped to current front

// sum costs

// heapify
int
main()
{
  using namespace std;

  deque<size_t> ropes{ 8, 4, 6, 12 };
  size_t cost{ 0 };

  for (ssize_t i = ropes.size() / 2 - 1; i >= 0; --i)
    heapify(ropes, ropes.size(), i, false);

  while (ropes.size() > 1) {

    auto sum = ropes.front();

    ropes.pop_front();

    heapify(ropes, ropes.size(), 0, false);

    cost += ropes.front() += sum;

    heapify(ropes, ropes.size(), 0, false);
  }

  cout << cost << "\n";

  return 0;
}
