#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct coord
{
    double x { 0 }, y { 0 };
    double from { 0 };
    coord(double a, double b) : x(a), y(b), from(edist(0, 0)) {}

    double
    edist(double xx, double yy) const
    {
        return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
    }

    double
    edist(const coord &o) const
    {
        return edist(o.x, o.y);
    }

    bool
    operator<(const coord &o) const
    {
        return from < o.from;
    }
};

int
main()
{
    using namespace std;

    const size_t  K = 3;
    vector<coord> coords { { 1, -2 },
                           { -2, 2 },
                           { 0, 10 },
                           { 4, -5 },
                           { 0, -2 } };

    sort(coords.begin(), coords.end());

    for (size_t i = 0; i < K && i < coords.size(); i++)
        cout << "x:" << coords.at(i).x << " ,y:" << coords.at(i).y << "\n";

    return 0;
}
