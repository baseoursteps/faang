#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

namespace i2p
{
const std::unordered_map<char, int> ops { { '+', 5 },  { '-', 5 },  { '*', 10 },
                                          { '/', 10 }, { '^', 15 }, { '(', 20 },
                                          { ')', 20 } };

bool
isL2r(char c)
{
    return c != '^' && c != '(' && c != ')';
}

bool
isR2l(char c)
{
    return c == '^';
}

bool
isOpen(char c)
{
    return c == '(';
}

bool
isClose(char c)
{
    return c == ')';
}

bool
isOperator(char c)
{
    return ops.find(c) != ops.end();
}

std::string
i2p(std::string &infix)
{
    std::stringstream ss;
    std::vector<char> stacky;

    for (auto &&c : infix) {
        if (std::isspace(c))
            continue;

        if (std::isdigit(c)) {
            ss << c;
            continue;
        }

        if (isOpen(c)) {
            stacky.push_back(c);
            continue;
        }

        if (isClose(c)) {
            for (;;) {
                auto top = stacky.back();
                stacky.pop_back();
                if (isOpen(top))
                    break;
                else
                    ss << top;
            }
            continue;
        }

        if (isOperator(c)) {
            auto cop = ops.at(c);

            for (;;)
                if (stacky.empty()) {
                    stacky.push_back(c);
                    break;
                } else {
                    auto lop = ops.at(stacky.back());
                    if (isOpen(stacky.back())) {
                        stacky.push_back(c);
                        break;
                    } else if (cop > lop) {
                        stacky.push_back(c);
                        break;
                    } else if (cop == lop) {
                        if (isR2l(c)) {
                            stacky.push_back(c);
                            break;
                        } else {
                            ss << stacky.back();
                            stacky.pop_back();
                        }
                    } else {
                        ss << stacky.back();
                        stacky.pop_back();
                    }
                }
        }
    }

    while (!stacky.empty()) {
        ss << stacky.back();
        stacky.pop_back();
    }

    return ss.str();
}

};

std::string
to_postfix(std::string infix)
{
    return i2p::i2p(infix);
}

int
main()
{
    std::cout << to_postfix("2+4*5") << "\n";
    std::cout << to_postfix("3*3/(7+1)") << "\n";
    std::cout << to_postfix("3*3/(7+1*(5+5/(9-4))-2)") << "\n";
    return 0;
}
