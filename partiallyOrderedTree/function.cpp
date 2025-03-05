#include "library.h"

void init(priQueue& pq){
	pq.count = 0;
}

bool isEmpty(priQueue pq){
	return pq.count == 0;
}

bool isFull(priQueue pq){
	return pq.count == MAX;
}

int getFirst(priQueue pq){
	if(isEmpty(pq)){
		cout<<"Don't value!\n";
		return 0;
	} 
	return pq.list[0];
}

int getParent(int i){
	return (i - 1) / 2;
}
int getLeftChild(int i){
	return (2 * i + 1);
}
int getRightChild(int i){
	return (2 * i + 2);
}

void swapp(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void shiftDown(priQueue& pq, int i){
	int leftChild = getLeftChild(i);
	int rightChild = getRightChild(i);
	int smallest = i;

	if(leftChild < pq.count && pq.list[leftChild] < pq.list[smallest]){
		smallest = leftChild;
	}
	if(rightChild < pq.count && pq.list[rightChild] < pq.list[smallest]){
		smallest = rightChild;
	}
	if(smallest != i){
		swapp(&pq.list[i], &pq.list[smallest]);	
		shiftDown(pq, smallest);
	}
}

void shiftUp(priQueue& pq, int index){
	if(pq.list[index] < pq.list[getParent(index)]){
		swapp(&pq.list[index],&pq.list[getParent(index)]);
		shiftUp(pq, getParent(index));
	}
}

void insertKey(priQueue& pq, int key){
	if(isFull(pq)){
		cout<<"Queue is full, don't insert!\n";
		return;
	}
	pq.count ++;
	int index = pq.count -1;
	pq.list[index] = key;
	//while(pq.list[index]< pq.list[getParent(index)]){
	//	swapp(&pq.list[index], &pq.list[getParent(index)]);
	//	index = getParent(index);
	//}
	shiftUp(pq, index);
}

void createPriQueue(priQueue& pq){
	int key;
	while(true){
		cout<<"Enter data (-99 break): "; cin >> key;
		if(key == -99) break;
		insertKey(pq, key);
	}
}

void printQueue(priQueue pq){
	for(int i = 0; i < pq.count;i++){
		cout<<pq.list[i]<<"\t";
	}
}


void deleteKey(priQueue& pq){ //Xoá phần tử có độ ưu tiên cao nhất.
	 swapp(&pq.list[0], &pq.list[pq.count - 1]);
	 pq.count--;
	 int index = 0;
	 shiftDown(pq, index);
}

