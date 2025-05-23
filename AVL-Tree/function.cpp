#include "library.h"

NODE *createNode(TYPEINFO data) {
  NODE *newNode = new NODE;
  newNode->value = data;
  newNode->left = nullptr;
  newNode->right = nullptr;
  newNode->height = 1;
  return newNode;
}
int getHeight(NODE *tree) { return (tree == nullptr) ? 0 : tree->height; }

int getBlanceFactor(NODE *tree) {
  return (getHeight(tree->left) - getHeight(tree->right));
}

// Left-left case
NODE *rightRotate(NODE *tree) {
  NODE *leftNode = tree->left;
  NODE *leftRightNode = leftNode->right;
  leftNode->right = tree;
  tree->left = leftRightNode;
  tree->height = 1 + max(getHeight(tree->left), getHeight(tree->right));
  leftNode->height =
      1 + max(getHeight(leftNode->left), getHeight(leftNode->right));
  return leftNode;
}

// right-right case
NODE *leftRotate(NODE *tree) {
  NODE *rightNode = tree->right;
  NODE *rightLeftNode = rightNode->left;
  rightNode->left = tree;
  tree->right = rightLeftNode;
  tree->height = 1 + max(getHeight(tree->left), getHeight(tree->right));
  rightNode->height =
      1 + max(getHeight(rightNode->left), getHeight(rightNode->left));
  return rightNode;
}

// left-right case
NODE *leftRightRotate(NODE *tree) {
  tree->left = leftRotate(tree->left);
  return rightRotate(tree);
}

// Right-right case
NODE *rightLeftRotate(NODE *tree) {
  tree->right = rightRotate(tree->right);
  return leftRotate(tree);
}

NODE *insert(NODE *tree, TYPEINFO data) {
  if (tree == nullptr)
    return tree = createNode(data);
  if (tree->value == data) {
    cout << "Duplicate value!\n";
    return tree;
  } else if (tree->value > data) {
    tree->left = insert(tree->left, data);
  } else if (tree->value < data) {
    tree->right = insert(tree->right, data);
  }
  tree->height = 1 + max(getHeight(tree->left), getHeight(tree->right));
  int balance = getBlanceFactor(tree);
  if (balance > 1 && tree->value > data) { // left-left case
    tree = rightRotate(tree);
  } else if (balance < -1 && tree->value < data) { // Right-right case
    tree = leftRotate(tree);
  } else if (balance > 1 && tree->value < data) { // Left-right case
    tree = leftRightRotate(tree);
  } else if (balance < -1 && tree->value > data) { // right-left case
    tree = rightLeftRotate(tree);
  }
  return tree;
}

void createTree(NODE *&tree) {
  int data;
  while (true) {
    cout << "Enter your data (-99 break): ";
    cin >> data;
    if (data == -99)
      break;
    tree = insert(tree, data);
  }
}

// delete node
NODE *findLeftMostOnRight(NODE *tree, NODE *pTree) {
  while (tree->left != nullptr) {
    tree = tree->left;
  }
  NODE *temp = tree;
  pTree->value = tree->value;
  tree = tree->right;
  delete temp;
  return pTree;
}

NODE *deleteNodeInTree(NODE *tree, TYPEINFO data) {
  if (tree == nullptr)
    return tree;
  if (tree->value > data) {
    tree->left = deleteNodeInTree(tree->left, data);
  } else if (tree->value < data) {
    tree->right = deleteNodeInTree(tree->right, data);
  } else {
    if (tree->left == nullptr || tree->right == nullptr) {
      NODE *temp = tree->left == nullptr ? tree->right : tree->left;
      if (temp == tree->left) {
        tree = tree->left;
      } else {
        tree = tree->right;
      }
      delete temp;
    } else {
      findLeftMostOnRight(tree->right, tree);
    }
  }
  return tree;
}

void preorder(NODE *tree) {
  if (tree != nullptr) {
    cout << tree->value << "\t";
    preorder(tree->left);
    preorder(tree->right);
  }
}

