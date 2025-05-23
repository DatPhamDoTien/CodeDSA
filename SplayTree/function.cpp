#include "library.h"

NODE *createNode(TYPEINFO data) {
  NODE *newNode = new NODE;
  newNode->value = data;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

// zig case
NODE *rightRotate(NODE *tree) {
  NODE *leftNode = tree->left;
  NODE *leftRightNode = leftNode->right;
  leftNode->right = tree;
  tree->left = leftRightNode;
  return leftNode;
}

// zag case
NODE *leftRotate(NODE *tree) {
  NODE *rightNode = tree->right;
  NODE *rightLeftNode = rightNode->left;
  rightNode->left = tree;
  tree->right = rightLeftNode;
  return rightNode;
}

NODE *splay(NODE *tree, TYPEINFO data) {
  if (tree == nullptr || tree->value == data)
    return tree;

  if (data < tree->value) {
    if (tree->left == nullptr)
      return tree;

    if (data < tree->left->value) {
      tree->left->left = splay(tree->left->left, data);
      tree = rightRotate(tree);
    } else if (data > tree->left->value) {
      tree->left->right = splay(tree->left->right, data);
      if (tree->left->right != nullptr)
        tree->left = leftRotate(tree->left);
    }
    return (tree->left == nullptr) ? tree : rightRotate(tree);
  } else {
    if (tree->right == nullptr)
      return tree;

    if (data > tree->right->value) {
      tree->right->right = splay(tree->right->right, data);
      tree = leftRotate(tree);
    } else if (data < tree->right->value) {
      tree->right->left = splay(tree->right->left, data);
      if (tree->right->left != nullptr)
        tree->right = rightRotate(tree->right); // SỬA Ở ĐÂY
    }
    return (tree->right == nullptr) ? tree : leftRotate(tree);
  }
}


NODE *insert(NODE *tree, TYPEINFO data) {
  if (tree == nullptr)
    return createNode(data);
  if (data < tree->value) {
    tree->left = insert(tree->left, data);
  } else {
    tree->right = insert(tree->right, data);
  }
  return tree;
}

NODE *insertAndSplay(NODE *tree, TYPEINFO data) {
  if (tree == nullptr)
    return createNode(data);
  if (tree->value == data) {
    return splay(tree, data);
  }
  if (tree->value > data) {
    tree->left = splay(tree->left, data);
  } else {
    tree->right = splay(tree->right, data);
  }
  return splay(tree, data);
}

void createTree(NODE *&tree) {
  TYPEINFO data;
  while (true) {
    cout << "Enter your data (-99 break): ";
    cin >> data;
    if (data == -99)
      break;
    tree = insertAndSplay(tree, data);
  }
}

void preorder(NODE *tree) {
  if (tree != nullptr) {
    cout << tree->value << "\t";
    preorder(tree->left);
    preorder(tree->right);
  }
}
