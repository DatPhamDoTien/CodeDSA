#include "library.h"
int main(){
    NODE* tree = nullptr;
    createTree(tree);
    preorder(tree);
}
