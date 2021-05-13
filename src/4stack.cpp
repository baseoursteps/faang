#include "utils.h"
#include <iostream>

int
main()
{
    stack s;

    for (int i = -10; i < 10; i++)
        s.push(i);

    s.push(-200);
    s.push(-300);

    int v { 0 }, m { 0 };

    while (s.pop(v)) {
        std::cout << "popped " << v;
        if (s.min(m))
            std::cout << ", min " << m;

        std::cout << "\n";
    }

    return 0;
}
