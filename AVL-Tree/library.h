#include <iostream>
using namespace std;

typedef int TYPEINFO;
struct NODE{
	TYPEINFO value;
	NODE* left;
	NODE* right;
	int height;
};
NODE* createNode(TYPEINFO data);
int getHeight(NODE* tree);
int getBalanceFactor(NODE* tree);
NODE* rightRotate(NODE* tree);
NODE* leftRotate(NODE* tree);
NODE* rightLeftRotate(NODE* tree);
NODE* leftRightRotate(NODE* tree);
NODE* insertTree(NODE* tree, TYPEINFO data);
void createTree(NODE* tree);

