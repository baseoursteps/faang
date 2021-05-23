#include <array>
#include <iostream>
#include <string>
#include <unordered_map>

// we need an object representing penalty/upgrade.

// we need an object representing a player.

class SnakesLadders
{
    using Penalty = std::pair<int, int>;

    struct Player
    {
        const int id;
        int       position { 0 };

        const std::string win;

        Player(int id) :
            id(id),
            win("Player " + std::to_string(id) + " Wins!") {};

        std::string
        whence() const
        {
            return "Player " + std::to_string(id) + " is on square " +
                   std::to_string(position);
        }
    };

    std::array<Player, 2>        players { Player(1), Player(2) };
    std::unordered_map<int, int> penalties {
        { 2, 38 },  { 16, 6 },  { 7, 14 },  { 8, 31 },  { 15, 26 }, { 21, 42 },
        { 28, 84 }, { 36, 44 }, { 46, 25 }, { 49, 11 }, { 51, 67 }, { 62, 19 },
        { 64, 60 }, { 71, 91 }, { 74, 53 }, { 78, 98 }, { 87, 94 }, { 89, 68 },
        { 92, 88 }, { 95, 75 }, { 99, 80 }
    };

    int current { 0 };

    Player &
    getCurrent()
    {
        auto &p = players.at(current);

        current = (current + 1) % 2;

        return p;
    }

    bool
    isOver()
    {
        return players.at(0).position == 100 || players.at(1).position == 100;
    }

    std::string
    play(int die1, int die2, Player &p)
    {
        const bool again = die1 == die2;

        p.position += die1 + die2;

        if (p.position > 100)
            p.position = 100 - (p.position % 100);

        auto penalty = penalties.find(p.position);

        if (penalty != penalties.end())
            p.position = penalty->second;

        if (p.position == 100) {
            return p.win;
        } else {
            if (again)
                current = (current + 1) % 2;

            return p.whence();
        }
    }

public:
    SnakesLadders() = default;

    std::string
    play(int die1, int die2)
    {
        if (isOver())
            return "Game over!";

        auto &p = getCurrent();

        return play(die1, die2, p);
    }
};

int
main()
{
    auto game = SnakesLadders();

    std::cout << game.play(1, 1) << "\n";
    std::cout << game.play(1, 5) << "\n";
    std::cout << game.play(6, 2) << "\n";
    std::cout << game.play(1, 1) << "\n";

    return 0;
}
