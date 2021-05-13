// Type your code here, or load an example.
#include <algorithm>
#include <iostream>
#include <vector>

int
main()
{
    int value = 1;
    int n     = 10;
    int i = 0, j = 0;
    int x[n][n] = { 0 };
    int last_i  = 0;
    int last_j  = 0;

    std::vector<int> i_vect;
    std::vector<int> j_vect;

    for (i = 0; i < n; i++) {
        if (i == 0)
            j_vect.push_back(i);
        else {
            i_vect.push_back(i);
            j_vect.push_back(i);
        }
    }

    i = 0;
    while (i < n) {
        for (auto const &el : j_vect) {
            x[last_i][el] = value++;
        }
        last_j = j_vect.back();

        for (auto const &el : i_vect) {
            x[el][last_j] = value++;
        }
        last_i = i_vect.back();

        j_vect.pop_back();
        i_vect.pop_back();
        std::reverse(j_vect.begin(), j_vect.end());
        std::reverse(i_vect.begin(), i_vect.end());

        i++;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            std::cout << x[i][j] << " ";
        std::cout << std::endl;
    }
}