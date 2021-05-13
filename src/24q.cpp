#include <iostream>
#include <vector>

using namespace std;

struct queue
{
    vector<int> reversed;
    vector<int> normal;

    void
    push_back(int val)
    {
        vector<int> tmp; // the new normal
        tmp.push_back(val);

        for (auto i = reversed.rbegin(); i != reversed.rend(); ++i)
            tmp.push_back(*i);

        reversed.clear();

        for (auto i = normal.rbegin(); i != normal.rend(); ++i)
            reversed.push_back(*i);

        reversed.push_back(val);

        normal = std::move(tmp);
    }

    bool
    front(int &val)
    {
        if (reversed.empty())
            return false;

        val = reversed.back();
        return true;
    }

    bool
    pop_front(int &val)
    {
        if (reversed.empty())
            return false;

        val = reversed.back();

        reversed.pop_back();

        vector<int> tmp; // the new normal

        for (auto i = reversed.rbegin(); i != reversed.rend(); ++i)
            tmp.push_back(*i);

        swap(tmp, normal);

        reversed.clear();

        for (auto i = tmp.rbegin(); i != tmp.rend(); ++i)
            reversed.push_back(*i);

        reversed.pop_back();

        return true;
    }
};

int
main()
{
    queue q;

    for (int i = 0; i < 10; i++) {
        q.push_back(i);
        int v;
        if (!q.front(v) || v != i) {
            cout << "not ok:" << v << "!=" << i << "\n";
        }
    }

    for (int i = 9; i >= 0; i--) {
        int v;

        if (!q.pop_front(v) || v != i) {
            cout << "not ok:" << v << "!=" << i << "\n";
        }
    }

    return 0;
}
