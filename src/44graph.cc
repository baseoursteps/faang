#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

long
cost(int              N,
     std::vector<int> from,
     std::vector<int> to,
     std::vector<int> weight,
     std::vector<int> energy_cost,
     int              A,
     int              B)
{
    using adjacency_list = std::vector<std::vector<std::tuple<int, long>>>;
    adjacency_list graph(N + 1);

    for (size_t i = 0; i < from.size(); ++i) {
        auto u = from.at(i), v = to.at(i), w = weight.at(i);
        graph.at(u).emplace_back(v, w);
        graph.at(v).emplace_back(u, w);
    }

    std::vector<long> costs(N + 1, LONG_MAX);

    using prio = std::priority_queue<std::tuple<long, int>,
                                     std::vector<std::tuple<long, int>>,
                                     std::greater<std::tuple<long, int>>>;

    prio pq;
    pq.emplace(A, 0);

    long minimum_energy_cost = energy_cost.at(A - 1);

    while (pq.size()) {
        auto [cost, node] = pq.top();
        pq.pop();
        minimum_energy_cost =
            std::min(minimum_energy_cost, long(energy_cost.at(node - 1)));

        for (auto [v, w] : graph.at(node)) {
            auto actual_cost = w * minimum_energy_cost;
            auto new_cost    = cost + actual_cost;

            if (new_cost < costs.at(v)) {
                costs.at(v) = new_cost;
                pq.emplace(v, new_cost);
            }
        }
    }

    if (costs.at(B) == LONG_MAX) {
        return -1;
    } else {
        return costs.at(B);
    }
}

int
main()
{
}
