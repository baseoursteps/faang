#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string>
opts(const string& word, const vector<string>& opts)
{
  vector<string> vars;

  for (auto&& o : opts) {
    bool ok = true;
    if (equal(word.begin(), word.end(), o.begin()))
      vars.push_back(o);

    if (vars.size() == 3)
      break;
  }

  return vars;
}

int
main()
{

  vector<string> sugg{
    { "mobile" }, { "mouse" }, { "moneypot" }, { "monitor" }, { "mousepad" }
  };

  sort(sugg.begin(), sugg.end());

  const string mouse{ "mouse" };

  for (auto i = 1; i <= mouse.size(); ++i) {

    const string search(mouse.begin(), mouse.begin() + i);

    auto rez = opts(search, sugg);

    cout << "for '" << search << "' we have:\n";
    for (auto&& s : rez)
      cout << "\t" << s << "\n";
  }

  return 0;
}
