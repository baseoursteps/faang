#include <iostream>

struct stack
{
  struct list
  {
    int val;
    int min;

    list* next{ nullptr };

    list(int val)
      : val(val)
      , min(val)
    {}

  } * l{ nullptr };

  void push(int v)
  {
    auto n = new list(v);

    if (l) {
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

  ~stack()
  {
    while (l) {
      auto n = l->next;
      delete l;
      l = n;
    }
  }
};

int
main()
{
  stack s;

  for (int i = -10; i < 10; i++)
    s.push(i);

  s.push(-200);
  s.push(-300);

  int v{ 0 }, m{ 0 };

  while (s.pop(v)) {
    std::cout << "popped " << v;
    if (s.min(m))
      std::cout << ", min " << m;

    std::cout << "\n";
  }

  return 0;
}
