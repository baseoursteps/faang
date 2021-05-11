#include <iostream>

using namespace std;

struct node
{
  int val{ -1 };
  node *left{ nullptr }, *right{ nullptr };

  node(int a)
    : val(a)
  {}

  node(int a, node* l, node* r)
    : val(a)
    , left(l)
    , right(r)
  {}
};

void
checkEm(node* tree, node* sub, node* tnext, node* snext)
{
  if (!(tnext && tree && sub))
    return;

  if (!snext) {
    cout << "found solution\n";
    return;
  }

  if (tree->left) {
    if (tnext->val == snext->val)
      checkEm(tree, sub, tnext->left, snext->left);
    else
      checkEm(tree, sub, tnext->left, sub);
  }
  if (tree->right) {
    if (tnext->val == snext->val)
      checkEm(tree, sub, tnext->right, snext->right);
    else
      checkEm(tree, sub, tnext->right, sub);
  }

  return;
}

void
print(node* n)
{

  if (!n)
    return;

  cout << n->val << " ";
  print(n->left);
  print(n->right);
}

int
main()
{
  node root(1);

  node a(2);
  node c(3);
  root.left = &a;
  root.right = &c;

  node d(4);
  a.left = &d;

  node e(5);
  d.right = &e;

  node f(6);
  e.right = &f;

  node root2(4);

  node a2(5);
  root2.left = &a2;

  node b2(6);
  a2.left = &b2;

  print(&root);
  cout << "\n";

  print(&root2);
  cout << "\n";

  node root3(4);
  node a3(5);
  root3.right = &a3;
  node b3(6);
  a3.right = &b3;

  print(&root3);
  cout << "\n";

  checkEm(&root, &root2, &root, &root2);
  checkEm(&root, &root3, &root, &root3);

  return 0;
}
