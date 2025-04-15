#include <iostream>
using namespace std;

typedef int TYPEINFO;
struct NODE {
  TYPEINFO value;
  NODE *left;
  NODE *right;
  int height;
};
NODE *createNode(TYPEINFO data);
int getHeight(NODE *tree);
NODE *rightRotate(NODE *tree);
NODE *leftRotate(NODE *tree);
NODE *leftRightRotate(NODE *tree);
NODE *rightLeftRotate(NODE *tree);
NODE *insert(NODE *tree, TYPEINFO data);
void createTree(NODE *&tree);
NODE *findLeftMostOnRight(NODE *tree, NODE *pTree);
NODE *deleteNodeInTree(NODE *tree, TYPEINFO data);
void preorder(NODE *tree);