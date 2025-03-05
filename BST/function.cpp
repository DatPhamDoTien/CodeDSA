#include "library.h"

NODE* createNode(TYPEINFO data)
{
	NODE* newNode = new NODE;
	newNode->value = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

NODE* insertTree(NODE* tree, TYPEINFO data)
{
	if(tree == nullptr){
		tree = createNode(data);
		return tree;
	}
	if(tree->value == data){
		cout<<"Duplicate value!\n";
		return tree;
	} else if(tree->value > data){
		tree->left = insertTree(tree->left, data);
	}else
		 tree->right = insertTree(tree->right, data);
	return tree;
}

void createTree(NODE*& tree)
{
	TYPEINFO data;
	while(true){
		cout<<"Enter data (-99 break): "; cin >> data;
		if(data == -99) break;
		tree = insertTree(tree, data);
	}
}

void preOrderTraversal(NODE*& tree)
{
	if(tree!=nullptr){
		cout<<tree->value<<"\t";
		preOrderTraversal(tree->left);
		preOrderTraversal(tree->right);
	}
}



NODE* findLeftMostOnRight(NODE* tree, NODE*& pTree){
	while(tree->left!=nullptr){
		tree = tree->left;
	}
	pTree->value = tree->value;
	NODE* temp = tree;
	tree = tree->right;
	delete temp;
	return pTree;
}


void printTree(NODE* root) {
    if (!root) return;

    queue<NODE*> q;
    q.push(root);

    while (!q.empty()) {
        NODE* current = q.front();
        q.pop();
        cout << current->value << " ";  // In giá trị node hiện tại

        if (current->left) q.push(current->left);  // Đẩy con trái vào queue
        if (current->right) q.push(current->right); // Đẩy con phải vào queue
    }
}

void deleteValueInTree(NODE*& tree, TYPEINFO valDel)
{
	if(tree == nullptr){
		cout<<"Don't find value!\t"<<valDel<<"\n";
		return;
	}

	if(tree->value > valDel)
		deleteValueInTree(tree->left, valDel);
	else if(tree->value < valDel)
		deleteValueInTree(tree->right, valDel);
	else{
		if(tree->left == nullptr || tree->right == nullptr){
			NODE* temp = (tree-> left == nullptr) ? tree->left : tree->right;
			if(temp == tree->left){
				tree = tree->right;
			} else{
				tree = tree->right;
			}
			delete temp;
		}
		else{
			findLeftMostOnRight(tree->right,tree);
		}
	}
}
