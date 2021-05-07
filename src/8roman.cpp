#include <exception>
#include <iostream>
#include <map>
#include <sstream>

size_t
arabic(const std::string& rome);

std::string
roman(size_t arab);

int
main(int argc, char* argv[])
{

  if (argc < 2) {
    std::cerr << "Please feed me input!\n";
    return 1;
  }

  // assume roman
  try {

    auto arab = arabic(argv[1]);
    std::cout << argv[1] << ":" << arab << "\n";
    return 0;

  } catch (...) {
  }

  // try arab
  std::size_t arab = 0;
  char* err = nullptr;

  if (argc >= 2)
    arab = std::strtoul(argv[1], &err, 0);

  if (err == argv[1])
    return 1;

  try {

    auto rome = roman(arab);
    std::cout << arab << ":" << rome << "\n";
    return 0;

  } catch (...) {
  }

  return 1;
}

// 1 5 10  50 100 500  1000
// I V  X  L  C   D    M

// 1, 10, 100 can appear up to three times
// 5, 50, 500 can appear only once

// XV
// xiv
// xx
// CL

// start from the right
// smaller elements can appear only once
// equal elements can appear up to three times
// one bigger element must come

size_t
arabic(const std::string& rome)
{
  const std::map<char, int> nums{ { 'I', 1 },   { 'V', 5 },   { 'X', 10 },
                                  { 'L', 50 },  { 'C', 100 }, { 'D', 500 },
                                  { 'M', 1000 } };

  size_t no = 0;
  bool smaller = false;
  int equal = 0;

  int last = -1;
  for (auto&& i = rome.rbegin(); i != rome.rend(); ++i) {
    int current = nums.at(std::toupper(*i));

    if (!no) {

    } else if (current > last) {

      equal = 0;
      smaller = false;

    } else if (current == last && current != 1000) {
      if (equal < 2 && (last != 5 && last != 50 && last != 500)) {
        equal++;
      } else {
        throw std::runtime_error(rome + " is not a valid roman number!\n");
      }
    } else if (current < last) {
      if (smaller) {
        throw std::runtime_error(rome + " is not a valid roman number!\n");
      } else {
        smaller = true;
      }
    }

    no += smaller ? -current : current;
    last = current;
  }

  return no;
}

// start from the left - keep in a variable the order i.e number of zeros
// check if number is bigger than 1000 and append Ms - continue
// check if specific char exists => if yes concat it
// find smallest char
// if current == smallest - number of zeros -> concat smallest - current then
// smallest
// if current < smallest - number of zeros -> concat previous then (current -
// previous) * zeros
std::string
roman(size_t arab)
{
  std::stringstream ss;
  const std::map<size_t, char> nums{ { 1, 'I' },   { 5, 'V' },   { 10, 'X' },
                                     { 50, 'L' },  { 100, 'C' }, { 500, 'D' },
                                     { 1000, 'M' } };

  size_t rev = 0;
  size_t zeros = 1;
  while (arab) {
    rev += arab % 10;
    rev *= 10;
    arab /= 10;
    zeros *= 10;
  }

  zeros /= 10;

  for (size_t i = rev; i != 0; i /= 10) {

    size_t current = (i % 10) * zeros;

    if (current == 0)
      continue;

    if (current > 1000) {
      while (current % 1000 == 0 && current != 0) {
        ss << 'M';
        current -= 1000;
      }
      continue;
    }

    auto c = nums.find(current);

    if (c != nums.end()) {

      ss << c->second;

    } else {

      auto smallest = nums.begin();
      for (; smallest != nums.end(); ++smallest) {
        if (current < smallest->first)
          break;
      }

      // 9 == 10 - 1 or 90 = 100 - 10
      // concat 1(I) then 10(X) or 10(X) then 100(C)
      if (current == smallest->first - zeros) {

        ss << nums.at(smallest->first - current);
        ss << smallest->second;

        // 7 == 5 + (7-5) * 1 or 70 == 50 + (70-50) * 10
        // concat 5 then 1 (7-5)/1 times  or 50 then 10 (70-50)/10 times
      } else {

        --smallest;
        ss << smallest->second;
        for (int rem = 0; rem < current - smallest->first; rem += zeros) {
          ss << nums.at(zeros);
        }
      }
    }

    // don't forget that we're going in reverse
    zeros /= 10;
  }

  return ss.str();
}
