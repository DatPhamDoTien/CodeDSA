#include "library.h"

int main() {
  NODE *tree = nullptr;
  TYPEINFO valDel;
  createTree(tree);
  cout << "Preorder: ";
  // preOrderTraversal(tree);
  printTree(tree);
  cout << "\nEnter value to delete: ";
  cin >> valDel;
  deleteValueInTree(tree, valDel);
  // preOrderTraversal(tree);
  printTree(tree);
  return 0;
}
