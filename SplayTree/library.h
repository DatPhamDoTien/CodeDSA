#include <iostream>
using namespace std;
typedef int TYPEINFO;
struct NODE {
  TYPEINFO value;
  NODE *left;
  NODE *right;
};

NODE *createNode(TYPEINFO data);
NODE *leftRotate(NODE *tree);
NODE *rightRotate(NODE *tree);
// NODE *splay(NODE *tree, TYPEINFO data);
NODE *insert(NODE *tree, TYPEINFO data);
NODE *insertAndSplay(NODE *tree, TYPEINFO data);
void createTree(NODE *&tree);
void preorder(NODE* tree);
NODE *splay(NODE *&r, NODE *nodeX) ;