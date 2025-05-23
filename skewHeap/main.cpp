#include "library.h"

int main() {
	skewHeap* tree = nullptr;
	TYPEINFO used, newData;
	createTree(tree);
	preorder(tree);
	cout << endl;
	cout << "Nhap gia tri can giam khoa: "; cin >> used;
	cout << "Nhap gia tri moi: "; cin >> newData;
	descreasekey(tree, used, newData);
	preorder(tree);
	return 0;
}