#pragma once

#include <cstdint>

struct list
{
  int64_t v;
  list* n;

  list(int64_t v, list* n)
    : v(v)
    , n(n)
  {}

  list(int64_t v)
    : v(v)
    , n(nullptr)
  {}
};
