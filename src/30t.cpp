#include <iostream>

using namespace std;

struct node
{
    int   val { -1 };
    node *left { nullptr }, *right { nullptr };

    explicit node(int a) : val(a) {}
};

// i cannot wrap my head around this...
int
print(node *n, size_t k)
{
    if (!n)
        return -1;

    int l = print(n->left, k);
    int r = print(n->right, k);

    bool leaf = l == r && r == -1;

    cout << "l:" << l << " r:" << r << " n:" << n->val << " k:" << k << "\n";

    if (l == 0 || r == 0 || (leaf && k == 0))
        cout << n->val << "\n";

    if (leaf && k > 0)
        return k - 1;

    if (l > 0 && l < k)
        return l - 1;

    if (r > 0 && r < k)
        return r - 1;

    return -2;
}

int
main()
{
    node a(1);

    node b(2);
    a.left = &b;
    node c(3);
    a.right = &c;

    node d(4);
    b.left = &d;

    node e(5);
    b.right = &e;

    node f(6);
    c.left = &f;

    node g(7);
    c.right = &g;

    node h(8);
    f.right = &h;

    size_t k = 2;

    print(&a, k);

    return 0;
}
