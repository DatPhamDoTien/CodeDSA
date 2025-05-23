#include "library.h"
#include <cstdio>
#include <stdio.h>

NODE *createNode(TYPEINFO data) {
  NODE *newNode = new NODE;
  newNode->value = data;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

NODE *insertTree(NODE *tree, TYPEINFO data) {
  if (tree == nullptr) {
    tree = createNode(data);
    return tree;
  }
  if (tree->value == data) {
    cout << "Duplicate value!\n";
    return tree;
  } else if (tree->value > data) {
    tree->left = insertTree(tree->left, data);
  } else
    tree->right = insertTree(tree->right, data);
  return tree;
}

void createTree(NODE *&tree) {
  TYPEINFO data;
  while (true) {
    cout << "Enter data (-99 break): ";
    cin >> data;
    if (data == -99)
      break;
    tree = insertTree(tree, data);
  }
}

void preOrderTraversal(NODE *&tree) {
  if (tree != nullptr) {
    cout << tree->value << "\t";
    preOrderTraversal(tree->left);
    preOrderTraversal(tree->right);
  }
}

NODE *findLeftMostOnRight(NODE *tree, NODE *&pTree) {
  while (tree->left != nullptr) {
    tree = tree->left;
  }
  pTree->value = tree->value;
  NODE *temp = tree;
  tree = tree->right;
  delete temp;
  return pTree;
}

void printTree(NODE *root) {
  if (!root)
    return;

  queue<NODE *> q;
  q.push(root);

  while (!q.empty()) {
    NODE *current = q.front();
    q.pop();
    cout << current->value << " "; // In giá trị node hiện tại

    if (current->left)
      q.push(current->left); // Đẩy con trái vào queue
    if (current->right)
      q.push(current->right); // Đẩy con phải vào queue
  }
}

void deleteValueInTree(NODE *&tree, TYPEINFO valDel) {
  if (tree == nullptr) {
    cout << "Don't find value!: " << valDel << "\n";
    return;
  }

  if (tree->value > valDel)
    deleteValueInTree(tree->left, valDel);
  else if (tree->value < valDel)
    deleteValueInTree(tree->right, valDel);
  else {
    if (tree->left == nullptr || tree->right == nullptr) {
      NODE *temp = (tree->left == nullptr) ? tree->left : tree->right;
      if (temp == tree->left) {
        tree = tree->right;
      } else {
        tree = tree->right;
      }
      delete temp;
    } else {
      findLeftMostOnRight(tree->right, tree);
    }
  }
}

// Bài tập tuần 1 cây BST
NODE *findNode(NODE *tree, TYPEINFO data) {
  if (tree == nullptr) {
    cout << "Don't find value " << data << endl;
    return tree;
  }
  if (tree->value == data) {
    cout << "Find " << data << endl;
    return tree;
  } else if (tree->value > data)
    findNode(tree->left, data);
  else
    findNode(tree->right, data);
  return tree;
}

int countNumberNode(NODE *tree) {
  if (tree == nullptr)
    return 0;
  return 1 + countNumberNode(tree->left) + countNumberNode(tree->right);
}

void writeNode(NODE *tree, FILE *file) {
  if (tree != nullptr) {
    fprintf_s(file, "%d\t", tree->value);
    writeNode(tree->left, file);
    writeNode(tree->right, file);
  }
}
// Thao tác với file.
int writeFile(NODE *tree, char *fileName) {
  FILE *fp;
  fopen_s(&fp, fileName, "wt");
  if (fp == nullptr) {
    return 0;
  } else {
    int num = countNumberNode(tree);
    fprintf_s(fp, "%d\n", num);
    writeNode(tree, fp);
    fclose(fp);
    return 1;
  }
}

int readFile(NODE *tree, char *fileName) {
  FILE *f;
  fopen_s(&f, fileName, "rt");
  if (f == nullptr) {
    return 0;
  }
  int num, data;
  fscanf_s(f, "%d", &num);

  for (int i = 0; i < num; i++) {
    fscanf_s(f, "%d", &data);
    insertTree(tree, data);
  }
  return 1;
}
