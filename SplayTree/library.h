#include <iostream>
using namespace std;

//Code splayTree.
typedef int TYPEINFO;
struct NODE{
	TYPEINFO value;
	NODE* left;
	NODE* right;
};


NODE* createNode(TYPEINFO data);
NODE* rightRotate(NODE* tree);
NODE* leftRotate(NODE* tree);
NODE* splay(NODE* tree, TYPEINFO data);
NODE* insert(NODE* tree,TYPEINFO data);
void preOrder(NODE* tree);
void createTree(NODE*& tree);
