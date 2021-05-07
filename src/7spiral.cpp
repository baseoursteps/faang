#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

int
main(int argc, char* argv[])
{
  size_t N;
  if (argc < 2)
    N = 4;
  else
    N = strtoul(argv[1], nullptr, 10);

  std::vector<std::vector<int>> vals(N);

  for (auto&& c : vals)
    c.resize(N, 0);

  int no = 0;

  int T/*op*/, R/*ight*/, B/*ottom*/, L/*eft*/;

  T = 0; //top
  R = N - 1; //right
  B = N - 1; //bottom
  L = 0; //left

  while (T != N) {

    for (int i = L; i <= R; i++)
      vals[T][i] = ++no;

    T++;

    for (int i = T; i <= B; i++)
      vals[i][R] = ++no;

    R--;

    for (int i = R; i >= L; i--)
      vals[B][i] = ++no;

    B--;

    for (int i = B; i >= T; i--)
      vals[i][L] = ++no;

    L++;
  }

  for (auto&& line : vals) {
    for (auto&& col : line)
      std::cout << std::to_string(col) << "  ";

    std::cout << "\n";
  }

  return 0;
}
