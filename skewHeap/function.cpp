#include "library.h"


void swapp(TYPEINFO* valA, TYPEINFO* valB) {
	TYPEINFO temp = *valA;
	*valA = *valB;
	*valB = temp;
}
skewHeap* createNode(TYPEINFO data) {
	skewHeap* newNode = new skewHeap;
	newNode->value = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

skewHeap* merge(skewHeap* h1, skewHeap* h2) {
	skewHeap* temp = new skewHeap;
	if (h1 == nullptr) {
		return h2;
	}
	else if (h2 == nullptr) {
		return h1;
	}
	else {
		if (h1->value > h2->value) {
			temp = h1;
			h1 = h2;
			h2 = temp;
		}	
		temp = h1->left;
		h1->left = h1->right;
		h1->right = temp;
		h1->left = merge(h1->left, h2);
	}
	return h1;
}

skewHeap* insertTree(skewHeap* tree, TYPEINFO data) {
	skewHeap* temp = createNode(data);
	tree = merge(tree, temp);
	return tree;
}
skewHeap* deleteMin(skewHeap* tree) {
	if (tree == nullptr) return nullptr;
	skewHeap* leftNode = tree->left;
	skewHeap* rightNode = tree->right;
	delete tree;
	return merge(leftNode, rightNode);
}


void createTree(skewHeap*& tree) {
	TYPEINFO data;
	while (true) {
		cout << "Enter your data(-99 break): "; cin >> data;
		if (data == -99) break;
		tree = insertTree(tree, data);
	}
}


void preorder(skewHeap* tree) {
	if (tree != nullptr) {
		cout << tree->value<<"\t";
		preorder(tree->left);
		preorder(tree->right);
	}
}


//Decreasekey(S, p, k)
skewHeap* deleteNode(skewHeap* tree, TYPEINFO valDel, bool& deleted) {
	if (!tree) return nullptr;
	if(!tree || deleted) return tree;
	if(tree->value == valDel && !deleted){
		deleted = true;
		skewHeap* merged = merge(tree->left, tree->right);
		delete tree;
		return merged;
	} 
	tree->left = deleteNode(tree->left, valDel, deleted);
	tree->right = deleteNode(tree->right, valDel, deleted);

	return tree;
}

skewHeap* decreaseKey(skewHeap*& tree, TYPEINFO used, TYPEINFO newData) {
	if (newData >= used) {
		cout << "Gia tri moi phai nho hon gia tri cu\n";
		return tree;
	}
	bool deleted = false;
	tree = deleteNode(tree, used, deleted);
	if(!deleted){
		cout<<"Không tìm thấy giá trị giảm khoá!";
		return tree;
	}
	tree = insertTree(tree, newData);
	return tree;
}






