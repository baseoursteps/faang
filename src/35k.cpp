#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <set>
#include <vector>

namespace knights
{
class Move
{
    int x, y;
    int cost;

public:
    Move(int x, int y, int cost) : x(x), y(y), cost(cost) {}

    bool
    isValid() const
    {
        return x >= 0 && x < 8 && y >= 0 && y < 8;
    }

    std::vector<Move>
    possible() const
    {
        const std::array<int, 8> X { 2, 2, -2, -2, 1, 1, -1, -1 };
        const std::array<int, 8> Y { -1, 1, 1, -1, 2, -2, 2, -2 };

        std::vector<Move> next;

        for (size_t i = 0; i < X.size(); ++i) {
            Move n(x + X.at(i), y + Y.at(i), cost + 1);
            if (n.isValid())
                next.push_back(std::move(n));
        }

        return next;
    }

    int
    getCost() const
    {
        return cost;
    }

    bool
    operator==(const Move &o) const
    {
        return x == o.x && y == o.y;
    }

    bool
    operator<(const Move &o) const
    {
        return x < o.x || (x == o.x && y < o.y);
    }
};

int
BFS(const Move &start, const Move &end)
{
    using namespace std;

    deque<Move> nodes;

    set<Move> visited;

    nodes.push_back(start);

    while (!nodes.empty()) {
        auto c = nodes.front();
        nodes.pop_front();

        if (c == end)
            return c.getCost();

        if (!visited.count(c)) {
            visited.insert(c);
            auto next = c.possible();
            std::move(next.begin(), next.end(), std::back_inserter(nodes));
        }
    }

    return -1;
}

};

int
knight(std::string start, std::string end)
{
    if (start.size() != 2 || end.size() != 2)
        return 0;

    int sl = start.at(0) - 'a';
    int sc = start.at(1) - '1';

    int el = end.at(0) - 'a';
    int ec = end.at(1) - '1';

    using namespace knights;
    return BFS(Move(sl, sc, 0), Move(el, ec, 0));
}

int
main()
{
    std::cout << knight("a1", "c1") << "\n";
    std::cout << knight("a1", "f1") << "\n";
    std::cout << knight("a1", "f3") << "\n";
    std::cout << knight("a1", "f4") << "\n";
    std::cout << knight("a1", "f7") << "\n";
    return 0;
}
