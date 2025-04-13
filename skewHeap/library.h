#include <iostream>
using namespace std;
typedef int TYPEINFO;
struct skewHeap {
	TYPEINFO value;
	skewHeap* left;
	skewHeap* right;
};

void init(skewHeap* sh);
void swapp(TYPEINFO* valA, TYPEINFO* valB);
skewHeap* createNode(TYPEINFO data);
skewHeap* merge(skewHeap* h1, skewHeap* h2);
skewHeap* insertTree(skewHeap* tree, TYPEINFO data);
void createTree(skewHeap*& tree);
void preorder(skewHeap* tree);
skewHeap* deleteNode(skewHeap* tree, TYPEINFO valDel);
skewHeap* descreasekey(skewHeap*& tree, TYPEINFO used, TYPEINFO newData);
