#include <iostream>

#include "utils.h"

list *
merge(list *i, list *j)
{
    if (i == j)
        j = nullptr;

    list *h = nullptr, *it = nullptr;
    while (i != nullptr && j != nullptr) {
        if (i->v < j->v) {
            if (!h) {
                h  = i;
                it = h;
            } else {
                it->n = i;
                it    = it->n;
            }
            i = i->n;
        } else {
            if (!h) {
                h  = j;
                it = h;
            } else {
                it->n = j;
                it    = it->n;
            }
            j = j->n;
        }
    }

    while (i != nullptr) {
        if (!h) {
            h  = i;
            it = h;
        } else {
            it->n = i;
            it    = it->n;
        }
        i = i->n;
    }

    while (j != nullptr) {
        if (!h) {
            h  = j;
            it = h;
        } else {
            it->n = j;
            it    = it->n;
        }
        j = j->n;
    }

    return h;
}

int
main()
{
    list a(0);
    list b(3);
    a.n = &b;
    list c(5);
    b.n = &c;

    list d(2);
    list e(3);
    d.n = &e;
    list f(6);
    e.n = &f;

    auto h = merge(&a, &d);

    for (auto it = h; it != nullptr; it = it->n)
        printf("%ld ", it->v);

    puts("");
    return 0;
}
