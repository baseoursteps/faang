#include <algorithm>
#include <array>
#include <cstddef>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Image
{
    vector<unsigned> pixels;
    size_t           width;
    size_t           height;

public:
    Image(const vector<unsigned> &p, size_t w, size_t h) :
        pixels(p),
        width(w),
        height(h)
    {
    }

    const array<int, 4> xs { 0, 0, -1, 1 };
    const array<int, 4> ys { -1, 1, 0, 0 };

    struct node
    {
        size_t current;
        int    cost;

        bool
        operator<(const node &o) const
        {
            return current < o.current;
        }

        node(size_t current, int cost) : current(current), cost(cost) {}
    };

    // we need dfs
    int
    minBorder(size_t pos, unsigned color) const
    {
        set<node>   visited;
        deque<node> queue;
        queue.emplace_back(pos, 0);

        auto min = -1;
        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop_front();

            int x = current.current / width;
            int y = current.current % width;

            if (visited.count(current) != 0)
                continue;

            visited.insert(current);
            for (auto it = 0; it < xs.size(); ++it) {
                int i = x + xs.at(it);
                int j = y + ys.at(it);

                if (i < 0 || i >= height || j < 0 || j >= width ||
                    pixels.at(i * width + j) != color) {
                    if (min == -1 || min > current.cost + 1)
                        min = current.cost + 1;

                    continue;
                }

                auto next = node(i * width + j, current.cost + 1);
                if (visited.count(next) != 0)
                    continue;

                queue.push_back(next);
            }
        }

        return min;
    }

    // if pixel matches color
    // go in all directions and find min of steps until boundary
    // do this for all pixels of same color and get max of mins

    // again iterate and find mins saving indeces where min==max
    vector<unsigned>
    central_pixels(unsigned color) const
    {
        vector<unsigned> px;

        // i * width + j // where i<height and j<width
        map<size_t, int> costs;
        auto             max = -1;
        for (auto i = 0; i < height; ++i) {
            for (auto j = 0; j < width; ++j) {
                if (pixels.at(i * width + j) != color)
                    continue;

                auto nm = minBorder(i * width + j, color);
                if (nm != -1)
                    costs.insert({ size_t(i * width + j), nm });

                if (max < nm)
                    max = nm;
            }
        }

        // now that he have min we go again and save nodes with that len
        if (max == -1)
            return px;

        for (auto i = 0; i < height; ++i) {
            for (auto j = 0; j < width; ++j) {
                if (pixels.at(i * width + j) != color)
                    continue;

                auto f = costs.find(i * width + j);
                if (f != costs.end() && f->second == max)
                    //                if (minBorder(i * width + j, color) ==
                    //                max)
                    px.push_back(i * width + j);
            }
        }

        sort(px.begin(), px.end());
        return px;
    }
};

int
main()
{
    // clang-format off
  Image image( { 1,1,4,4,4,4,2,2,2,2,
                 1,1,1,1,2,2,2,2,2,2,
                 1,1,1,1,2,2,2,2,2,2,
                 1,1,1,1,1,3,2,2,2,2,
                 1,1,1,1,1,3,3,3,2,2,
                 1,1,1,1,1,1,3,3,3,3 }, 10, 6 );

    // clang-format on

    for (auto &&i : { 1, 2, 3, 4, 5 }) {
        cout << "i: " << i << " : ";
        for (auto &&n : image.central_pixels(i)) {
            cout << n << " ";
        }
        cout << "\n";
    }
}
