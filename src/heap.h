#pragma once

#include <cstdio>
#include <vector>

inline size_t
lchild(size_t i)
{
    return i * 2 + 1;
}

inline size_t
rchild(size_t i)
{
    return i * 2 + 2;
}

template<typename T>
void
heapify(T &vals, size_t n, size_t root, bool max)
{
    auto compare = [vals, max](size_t c, size_t r) {
        if (max)
            return vals.at(r) < vals.at(c);
        else
            return vals.at(r) > vals.at(c);
    };

    auto m = root;
    auto l = lchild(root);
    auto r = rchild(root);

    if (l < n && compare(l, root))
        m = l;

    if (r < n && compare(r, m))
        m = r;

    if (m != root) {
        std::swap(vals.at(m), vals.at(root));
        heapify(vals, n, m, max);
    }
}

template<typename T>
void
heapsort(T &vals, bool max = true)
{
    for (ssize_t i = vals.size() / 2 - 1; i >= 0; --i)
        heapify(vals, vals.size(), i, max);

    for (size_t i = vals.size() - 1; i > 0; --i) {
        std::swap(vals.at(0), vals.at(i));
        heapify(vals, i, 0, max);
    }
}
