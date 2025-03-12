#include "library.h"


int main(){
	NODE* tree = nullptr;

	//tree = insert(tree, 100);
	//tree = insert(tree, 50);
	//tree = insert(tree, 200);
	//tree = insert(tree, 40);
	//tree = insert(tree, 60);
	createTree(tree);
	cout<<"Preorder traversal: ";
	preOrder(tree);
	return 0;
}
