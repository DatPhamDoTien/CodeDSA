#include "library.h"


NODE* createNode(TYPEINFO data){
	NODE* newNode = new NODE();
	newNode->value = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}
//Zig case.
NODE* rightRotate(NODE* tree) {
	NODE* leftNode = tree->left;
	tree->left = leftNode->right;
	leftNode->right = tree;
	return leftNode;
}

//Zag-case
NODE* leftRotate(NODE* tree) {
	NODE* rightNode = tree->right;
	tree->right = rightNode->left;
	rightNode->left = tree;
	return rightNode;
}

NODE* splay(NODE* tree, TYPEINFO data){
	if(tree == nullptr || tree->value == data) return tree;

	if(tree->value > data){
		if(tree->left == nullptr) return tree;

		if(tree->left->value > data){
			tree->left->left = splay(tree->left->left, data);
			tree = rightRotate(tree);
		} else if(tree->left->value < data){
			tree->left->right = splay(tree->left->right, data);
			if(tree->left->right != nullptr)
				tree->left = leftRotate(tree->left);
		}
		return (tree->left == nullptr) ? tree : rightRotate(tree);
	}
	else{
		if(tree->right == nullptr) return tree;

		if(tree->right->value > data){
			tree->right->left = splay(tree->right->left, data);
			if(tree->right->left != nullptr)
				tree->right = rightRotate(tree->right);
		}
		else if(tree->right->value < data){	
			tree->right->right = splay(tree->right->right, data);
			tree = leftRotate(tree);
		}
		return(tree->right == nullptr) ? tree : leftRotate(tree);
	}
}

NODE* insert(NODE* tree,TYPEINFO data) {
	if(tree == nullptr) return createNode(data);

	tree = splay(tree, data);

	if(tree->value == data){ 
		cout<<"Duplicate value!\n";
		return tree;
	}
	NODE* node = createNode(data);
	if(tree->value > data){
		node->right = tree;
		node->left = tree->left;
		tree->left = nullptr;
	} 
	else{
		node->left = tree;
		node->right = tree->right;
		tree->right = nullptr;
	}
	return node;
}

void createTree(NODE*& tree){
	TYPEINFO data;
	while(true){
		cout<<"Enter data (-99 break): "; cin >> data;
		if(data != -99)
			tree = insert(tree, data);
		else break;
	}
}


void preOrder(NODE* tree) {
	if(tree != nullptr){
		cout<<tree->value<<"\t";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}



