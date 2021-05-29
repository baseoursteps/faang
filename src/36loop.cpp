#include "utils.h"
#include <cstdio>
#include <iostream>

using namespace std;

const list *
nextSlow(const list *n)
{
    return n ? n->n : n;
}

const list *
nextFast(const list *n)
{
    return nextSlow(nextSlow(n));
}

size_t
getLoop(const list *head)
{
    if (!head)
        return 0;

    auto slow = head;
    auto fast = nextFast(slow);

    if (!fast)
        return 0;

    while (fast && fast != slow) {
        fast = nextFast(fast);
        slow = nextSlow(slow);
    }

    if (!fast)
        return 0;

    size_t count { 1 };
    for (auto i = slow->n; i != slow; i = i->n, ++count)
        ;

    return count;
}

int
main()
{
    auto head = new list(14);

    for (int i = 13; i >= 0; i--) {
        auto n = new list(i);
        n->n   = head;
        head   = n;
    }

    // create loop between last and fourth
    auto last = head;
    for (; last->n != nullptr; last = last->n) {
    }
    last->n = head->n->n->n;

    auto loop = getLoop(head);
    cout << "loop size:" << loop << "\n";

    // break loop - delete
    last->n = nullptr;
    while (head) {
        auto n = head->n;
        delete head;
        head = n;
    }
}
