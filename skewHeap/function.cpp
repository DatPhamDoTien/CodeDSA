#include "library.h"

void init(skewHeap* sh) {
	sh->value = 0;
	sh->left = nullptr;
	sh->right = nullptr;
}

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
	skewHeap* temp = tree;
	tree = tree->left;
	skewHeap* rightNode = tree->right;
	delete temp;
	tree->left = merge(tree, rightNode);
	return tree;
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
skewHeap* deleteNode(skewHeap* tree, TYPEINFO valDel) {
	if (!tree) return nullptr;

	if (tree->value == valDel) {
		skewHeap* merged = merge(tree->left, tree->right);
		delete tree;
		return merged;
	}
	tree->left = deleteNode(tree->left, valDel);
	tree->right = deleteNode(tree->right, valDel);
	return tree;
}

skewHeap* descreasekey(skewHeap*& tree, TYPEINFO used, TYPEINFO newData) {
	if (used < newData) {
		cout << "Gia tri moi phai lon hon gia tri cu";
		return tree;
	}
	deleteNode(tree, used);
	insertTree(tree, newData);
	return tree;
}






