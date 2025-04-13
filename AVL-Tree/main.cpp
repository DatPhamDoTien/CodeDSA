#include "library.h"



int main(){
	NODE* tree = nullptr;
	TYPEINFO valToDel;

	createTree(tree);
	preOrder(tree); 
	cout<<"Enter value to delete: "; cin >> valToDel;
	deleteNodeInTree(tree,valToDel);
	preOrder(tree);
	return 0;
}
