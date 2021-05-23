#include <algorithm>
#include <iostream>

std::string
add(const std::string &a, const std::string &b)
{
    if (a.empty()) {
        return b;
    }

    if (b.empty()) {
        return a;
    }

    const auto sz = a.size() > b.size() ? b.size() : a.size();

    bool carry = false;

    std::string rez;
    for (unsigned long i = 1; i <= sz; i++) {
        auto deca = a.at(a.size() - i) - '0';
        auto decb = b.at(b.size() - i) - '0';

        auto decr = deca + decb;
        decr += carry ? 1 : 0;

        carry = decr >= 10;
        decr %= 10;
        rez.append(std::to_string(decr));
    }

    for (auto i = sz + 1; i <= a.size(); i++) {
        auto deca = a.at(a.size() - i) - '0';

        deca += carry ? 1 : 0;
        carry = deca >= 10;

        deca %= 10;

        rez.append(std::to_string(deca));
    }

    for (auto i = sz + 1; i <= b.size(); i++) {
        auto decb = b.at(b.size() - i) - '0';

        decb += carry ? 1 : 0;
        carry = decb >= 10;

        decb %= 10;

        rez.append(std::to_string(decb));
    }

    if (carry) {
        rez += std::to_string(1);
    }

    std::reverse(rez.begin(), rez.end());
    return rez;
}

int
main()
{
    std::cout << add("123", "456") << "\n";

    return 0;
}
