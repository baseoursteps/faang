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

  int I, J, K, L;
  I = 0;
  J = N - 1;
  K = N - 1;
  L = 0;

  while (I != N) {
    for (int i = I; i <= J; i++)
      vals[I][i] = ++no;

    I++;

    for (int i = I; i <= K; i++)
      vals[i][J] = ++no;

    J--;

    for (int i = J; i >= L; i--)
      vals[K][i] = ++no;

    K--;

    for (int i = K; i >= I; i--)
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
