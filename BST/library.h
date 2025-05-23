#include <iostream>
#include <queue>
using namespace std;

typedef int TYPEINFO;
struct NODE {
  TYPEINFO value;
  NODE *left;
  NODE *right;
};

NODE *createNode(TYPEINFO data);
NODE *insertTree(NODE *tree, TYPEINFO data);
void createTree(NODE *&tree);
void preOrderTraversal(NODE *&tree);
void deleteValueInTree(NODE *&tree, TYPEINFO valDel);
void printTree(NODE *root);
NODE *findNode(NODE *tree, TYPEINFO data);
int countNumberNode(NODE *tree);
void writeNode(NODE *tree, FILE *file);
int writeFile(NODE *tree, char *fileName);
