#include <iostream>
#include <map>

struct node
{
    int   val { -1 };
    node *next { nullptr };
    node *rand { nullptr };

    node(int val) : val(val) {}
};

int
main()
{
    node a(1);
    node b(2);
    node c(3);
    node d(4);
    node e(5);
    node f(6);
    node g(7);

    // a - c - b - d - f - e - g

    a.next = &b;
    a.rand = &c;

    b.next = &c;
    b.rand = &d;

    c.next = &d;
    c.rand = &b;

    d.next = &e;
    d.rand = &f;

    e.next = &f;
    e.rand = &g;

    f.next = &g;
    f.rand = &e;

    puts("Original - normal");
    for (auto i = &a; i; i = i->next)
        std::cout << i->val << " ";

    puts("\nOriginal - random");
    for (auto i = &a; i; i = i->rand)
        std::cout << i->val << " ";

    std::map<node *, node *> rands;

    node *nm = nullptr;

    node **iter = &nm;

    for (auto i = &a; i; i = i->next) {
        auto n = new node(i->val);
        rands.insert({ i, n });

        if (!*iter)
            *iter = n;
        else {
            (*iter)->next = n;
            iter          = &(*iter)->next;
        }
    }

    for (auto i = &a, j = nm; i && nm; i = i->next, j = j->next) {
        if (!i->rand)
            break;

        auto n  = rands.at(i->rand);
        j->rand = n;
    }

    puts("\nCopy - normal");
    for (auto i = nm; i; i = i->next)
        std::cout << i->val << " ";

    puts("\nCopy - random");
    for (auto i = nm; i; i = i->rand)
        std::cout << i->val << " ";

    while (nm) {
        auto n = nm->next;
        delete nm;
        nm = n;
    }

    puts("");

    return 0;
}
