#include <cstddef>
#include <iostream>

long
ops(long number)
{
    long count {};

    while (number > 0) {
        if (number & 1) {
            if ((number & 0b11) == 0b11) {
                number++;
            } else {
                number--;
            }
            count++;
        } else {
            number >>= 1;
        }
    }

    return count;
}

int
main()
{
    for (size_t i = 0; i < 100; ++i) {
        std::cout << i << ":" << ops(i) << "\n";
    }
}
