#include "library.h"



NODE* createNode(TYPEINFO data)
{
	NODE* newNode = new NODE;
	newNode->value = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->height = 1;
	return newNode;
}
int getHeight(NODE* tree)
{
	return (tree == nullptr) ? 0 : tree->height;
}

int getBalanceFactor(NODE* tree)
{
	return (tree == nullptr) ? 0 : getHeight(tree->left) - getHeight(tree->right);	
}

//left-left case.
NODE* rightRotate(NODE* tree)
{
	NODE* leftNode = tree->left;
	NODE* leftRightNode = leftNode->right;
	//Rotate.
	leftNode->right = tree;
	tree->left = leftRightNode;
	//Up date height.
	tree->height = 1 + max(getHeight(tree->left), getHeight(tree->right));
	leftNode->height = 1 + max (getHeight(leftNode->left), getHeight(leftNode->right));
	return leftNode;
}

//Right-Right Case.
NODE* leftRotate(NODE* tree)
{
	NODE* rightNode = tree->right;
	NODE* rightLeftNode = rightNode->left;
	//Rotate.
	rightNode->left = tree;
	tree->right = rightLeftNode;
	//Update height.
	tree->height = 1 + max(getHeight(tree->left), getHeight(tree->right));
	rightNode->height = 1 + max(getHeight(rightNode->left), getHeight(rightNode->right));
	return rightNode;
}

//Left-right case.
NODE* rightLeftRotate(NODE* tree)
{
	rightRotate(tree->left);
	return leftRotate(tree);
}
//Right-left case.
NODE* leftRightRotate(NODE* tree)
{
	leftRotate(tree->right);
	return rightRotate(tree);
}


NODE* insertTree(NODE* tree, TYPEINFO data)
{
	if(tree == nullptr){
		tree = createNode(data);
		return tree;
	}

	if(tree->value == data){
		cout<<"Duplicate value\n"; return tree;
	} else if(tree->value > data){
		tree->left = insertTree(tree->left, data);
	} else {
		tree->right = insertTree(tree->right, data);
	}

	tree->height = 1 + max(getHeight(tree->left), getHeight(tree->right));
	int balance = getBalanceFactor(tree);
	
	if(balance > 1 && tree->left->value > data){ // left-left case.
		rightRotate(tree);
		rightRotate(tree);
	} else if(balance < -1 && tree->right->value < data ){ // right-right case.
		leftRotate(tree);
		leftRotate(tree);
	} else if(balance > 1 && tree->left->value < data){
		rightLeftRotate(tree);	
	} else if(balance < -1 && tree->right->value > data){
		rightLeftRotate(tree);
	}
	return tree;
}

void createTree(NODE* tree)
{
	TYPEINFO data;
	while(true){
		cout<<"Enter data (-99 break): "; cin >> data;
		if(data == -99) break;
		tree = insertTree(tree, data);
	}
	return;
}


