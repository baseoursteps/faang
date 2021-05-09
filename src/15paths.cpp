#include <iostream>
#include <vector>

// 0 1 0
// 0 0 1
// 0 0 0
// 2

// 0 0 0
// 0 1 0
// 0 0 0
// 2

using namespace std;

size_t
navigate(vector<vector<bool>> map, ssize_t x, ssize_t y)
{
  if (x < 0 || x >= map.size() || y < 0 || y >= map.at(0).size())
    return 0;

  if (map[x][y])
    return 0;

  if (x == map.size() - 1 && y == map.at(0).size() - 1)
    return 1;

  size_t count = 0;
  map[x][y] = 1;

  count += navigate(map, x + 1, y);
  count += navigate(map, x - 1, y);
  count += navigate(map, x, y + 1);
  count += navigate(map, x, y - 1);

  map[x][y] = 0;

  return count;
}

int
main()
{

  // 2
  // vector<vector<bool>> map{ { 0, 1, 0 }, { 0, 0, 1 }, { 0, 0, 0 } };

  // 2
  vector<vector<bool>> map{ { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };

  // first check if start and begin are accesible
  if (map.front().front() == 1 || map.back().back() == 1) {
    cout << 0 << "\n";
    return 0;
  }

  // start from a position

  // return 0 if we're blocked

  // return 0 if went over the map

  // if reached destination return 1

  // set it as visited (a)

  // go in all others and increment count

  // unset position (a)

  // return count

  size_t count = navigate(map, 0, 0);

  cout << count << "\n";

  return 0;
}
