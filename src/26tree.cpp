#include <algorithm>
#include <deque>
#include <exception>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct node
{
  int val{ -1 };
  node *left{ nullptr }, *right{ nullptr };

  explicit node(int a)
    : val(a)
  {}
};

vector<node*>
maxChild(node* n)
{
  if (!n)
    return {};

  auto ml = maxChild(n->left);
  auto mr = maxChild(n->right);
  vector<node*> current{ n };

  if (ml.size() >= mr.size()) {
    move(ml.begin(), ml.end(), back_inserter(current));
  } else {
    move(mr.begin(), mr.end(), back_inserter(current));
  }

  return current;
}

void
print(node* n, bool bf = true)
{
  if (!n)
    return;

  deque<node*> nodes;
  nodes.push_back(n);

  while (!nodes.empty()) {

    node* c{ nullptr };

    if (bf) {
      c = nodes.front();
      nodes.pop_front();
    } else {
      c = nodes.back();
      nodes.pop_back();
    }

    if (c->left) {
      nodes.push_back(c->left);
    }

    if (c->right) {
      nodes.push_back(c->right);
    }

    cout << c->val << " ";
  }

  cout << "\n";
}

int
main()
{
  node root(0);
  node a(1);
  node b(2);

  root.left = &a;
  root.right = &b;

  node c(3);
  a.left = &c;

  node d(4);
  b.left = &d;

  node e(5);
  b.right = &e;

  node f(6);
  c.right = &f;

  node g(7);
  d.left = &g;

  //print(&root, false);

  auto path = maxChild(&root);

  cout << "longest path: ";
  for (auto&& n : path)
    cout << n->val << " ";

  cout << "\n";

  return 0;
}
