#pragma once

#include <algorithm>
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

struct stack
{
  struct list
  {
    int val;
    int min;
    int max;

    list* next{ nullptr };

    list(int val)
      : val(val)
      , min(val)
      , max(val)
    {}

  } * l{ nullptr };

  void push(int v)
  {
    auto n = new list(v);

    if (l) {
      n->max = std::max(n->max, l->max);
      n->min = std::min(n->min, l->min);
      n->next = l;
    }
    l = n;
  }

  bool pop(int& val)
  {
    if (l) {
      val = l->val;
      auto v = l;
      l = l->next;
      delete v;
      return true;
    }
    return false;
  }

  bool top(int& val)
  {
    if (l) {
      val = l->val;
      return true;
    }
    return false;
  }

  bool min(int& val)
  {
    if (l) {
      val = l->min;
      return true;
    }
    return false;
  }

  bool max(int& val)
  {
    if (l) {
      val = l->max;
      return true;
    }
    return false;
  }

  ~stack()
  {
    while (l) {
      auto n = l->next;
      delete l;
      l = n;
    }
  }
};
