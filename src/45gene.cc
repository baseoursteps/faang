#include <cassert>
#include <cstddef>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

int
minMutation(const std::string              &startGene,
            const std::string              &endGene,
            const std::vector<std::string> &banc)
{
    const std::unordered_set<std::string>            bank(banc.begin(), banc.end());
    std::queue<std::pair<std::string, size_t>> mutation;
    std::unordered_set<std::string>            visited {};

    if (bank.count(endGene) == 0) {
        return -1;
    }

    mutation.push({ startGene, 0 });

    while (mutation.size()) {
        auto [current, distance] = mutation.front();
        mutation.pop();

        if (current == endGene) {
            return distance;
        }

        for (size_t i = 0; i < startGene.size(); ++i) {
            auto origChar = current.at(i);
            for (auto c : std::string { "ACGT" }) {
                if (c == origChar) {
                    continue;
                }

                current.at(i) = c;

                if (bank.count(current) && !visited.count(current)) {
                    visited.insert(current);
                    mutation.push({ current, distance + 1 });
                }
            }
            current.at(i) = origChar;
        }
    }
    return -1;
}

int
main()
{
    auto                     startGene = "AACCGGTT";
    auto                     endGene   = "AAACGGTA";
    std::vector<std::string> bank      = { "AACCGGTA", "AACCGCTA", "AAACGGTA" };

    assert(2 == minMutation(startGene, endGene, bank));

    startGene = "AACCGGTT";
    endGene   = "AACCGGTA";
    bank      = { "AACCGGTA" };

    assert(1 == minMutation(startGene, endGene, bank));
}
