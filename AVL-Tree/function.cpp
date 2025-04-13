#include "library.h"

NODE* createNode(TYPEINFO data) {
	NODE* newNode = new NODE;
	newNode->value = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->height = 1;
	return newNode;
}

int getHeight(NODE* tree) {
	return (tree == nullptr) ? 0 : tree->height;
}

int getBalanceFactor(NODE* tree) {
	return (getHeight(tree->left) - getHeight(tree->right));
}

//left-left

NODE* rightRotate(NODE* tree) {
	NODE* leftNode = tree->left;
	NODE* leftRightNode = leftNode->right;
	//
	leftNode->right = tree;
	tree->left = leftRightNode;
	//
	tree->height = 1 + max(getHeight(tree->left), getHeight(tree->right));
	leftNode->height = 1 + max(getHeight(leftNode->left), getHeight(leftNode->right));
	return leftNode;
}
//right-right
NODE* leftRotate(NODE* tree) {
	NODE* rightNode = tree->right;
	NODE* rightLeftNode = rightNode->left;
	//
	rightNode->left = tree;
	tree->right = rightLeftNode;
	//
	tree->height = 1 + max(getHeight(tree->left), getHeight(tree->right));
	rightNode->height = 1 + max(getHeight(rightNode->left), getHeight(rightNode->right));
	return rightNode;
}

//left-right

NODE* leftRightRotete(NODE* tree) {
	leftRotate(tree->left);
	return rightRotate(tree);
}
//right-left

NODE* rightLeftRotate(NODE* tree){
	leftRotate(tree->right);
	return leftRotate(tree);
}


NODE* insertTree(NODE* tree, TYPEINFO data) {
	if (tree == nullptr) {
		return tree = createNode(data);
	}

	if (tree->value == data) {
		cout << "Duplicate value!\n"; 
		return tree;
	}
	else if (tree->value > data) {
		tree->left = insertTree(tree->left, data);
	}
	else {
		tree->right = insertTree(tree->right, data);
	}

	tree->height = 1 + max(getHeight(tree->left), getHeight(tree->right));
	int balance = getBalanceFactor(tree);

	if (balance > 1 && tree->left->value > data) { //left-left
		tree = rightRotate(tree);
	}
	else if (balance < -1 && tree->right->value < data) { //right-right
		tree = leftRotate(tree);
	}
	else if (balance > 1 && tree->left->value < data) { //left-right
		tree = leftRightRotete(tree);
	}
	else if (balance < -1 && tree->right->value > data) {
		tree = rightLeftRotate(tree);
	}
	return tree;
}



void createTree(NODE*& tree) {
	TYPEINFO data;
	while (true){
		cout << "Enter your data (-99 break): "; cin >> data;
		if (data == -99) break;
		tree = insertTree(tree, data);
	}
}

void preOrder(NODE* tree) {
	if (tree != nullptr) {
		cout << tree->value << "\t";	
		preOrder(tree->left);
	
		preOrder(tree->right);
	}
}


//Write function to delete value (NODE)
void findLeftMostOnRight(NODE* tree, NODE* pTree){
	while(tree->left != nullptr){
		tree = tree->left;
	}
	NODE* temp = tree;
	pTree->value = tree->value;
	tree = tree->right;
	delete temp;
}

NODE* deleteNodeInTree(NODE*& tree, TYPEINFO data){
	if(tree == nullptr){
		return tree;
	}
	if(tree->value > data){
		tree =  deleteNodeInTree(tree->left, data);
	}
	else if(tree->value < data){
		tree = deleteNodeInTree(tree->right, data);
	}
	else{
		if(tree->left == nullptr || tree->right == nullptr){
			NODE* temp = (tree->left == nullptr) ? tree->right : tree->left;
			if(temp == tree->left){
				tree = tree->left;
			}else if (temp == tree->right){
				tree = tree->right;
			}
			delete temp;
		} else {
			findLeftMostOnRight(tree->right, tree);
		}
	}
	return tree;
}

