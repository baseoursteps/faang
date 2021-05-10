#include <iostream>
#include <sys/types.h>
#include <vector>

using namespace std;

ssize_t
findMin(const vector<ssize_t>& v, size_t i, size_t j)
{
  if (i == j)
    return v.at(i);

  auto m = (i + j) / 2;

  if (v.at(j) < v.at(m) && v.at(j) < v.at(i))
    return findMin(v, m + 1, j);

  if (v.at(i) < v.at(m) && v.at(i) < v.at(j))
    return findMin(v, i, m - 1);

  return v.at(m);
}

int
main()
{
  vector<ssize_t> vals{ 4, 5, 6, 7, 0, 1, 2 };
  cout << findMin(vals, 0, vals.size() - 1) << "\n";

  return 0;
}
