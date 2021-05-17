#include "utils.h"
#include <cstdio>
#include <iostream>

list *
reverse(list *head, const size_t k)
{
    if (!head)
        return head;

    list *new_head = nullptr;

    list *nh = nullptr, *lh = head;

    list *next = head->n;

    list *last = nullptr;

    size_t i = 1;

    while (next) {
        if (i == k) {
            if (nh) {
                lh->n = head;
                lh    = nh;
            }

            if (!new_head)
                new_head = head;

            nh = head = next;
            next      = next->n;
            nh->n     = nullptr;
            i         = 1;
        } else {
            auto nn = next->n;
            next->n = head;
            head    = next;
            next    = nn;
            i++;
        }
    }

    lh->n = head;

    return new_head;
}

int
main()
{
    // 12 13 3 20 55 87 20 77 90
    // for k=3
    // 3 13 12 87 55 20 90 77 20
    struct list *l { nullptr };

    // 12 13 3 20 55 87 20 77
    // for k=2
    // 13 12 20 3 87 55 77 20
    for (auto &&i : { 77, 20, 87, 55, 20, 3, 13, 12 }) {
        auto n = new list(i);
        n->n   = l;
        l      = n;
    }

    l = reverse(l, 2);

    while (l) {
        std::printf("%ld ", l->v);
        l = l->n;
    }

    puts("");
    return 0;
}
