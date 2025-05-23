#include "library.h"

void initPQ(priQueue& pq){
	pq.count = 0;
}
int isEmpty(priQueue pq){
	return (pq.count == 0) ? 1 : 0;
}
int isFull(priQueue pq){
	return (pq.count == MAX) ? 1 : 0;
}
int getFirst(priQueue& pq){
	if(isEmpty(pq)){
		cout << "Khong co phan tu!\n";
		return 0;
	}	
	return pq.list[0];
}
int getLeft(int index){
	return ((2 * index) + 1);
}
int getRight(int index){
	return ((2* index) + 2);
}
int getParent(int index){
	return ((index - 1) / 2);
}
void swapp(int* x, int* y)
{
	int* temp = x;
	*x = *y;
	y = temp;
}

void shiftDown(priQueue& pq, int index){
	int left = getLeft(index);
	int right = getRight(index);
	int smallest = index;
	
	if(left < pq.count && pq.list[left] < pq.list[smallest]){
		smallest = left;
	}
	if(right < pq.count && pq.list[right] < pq.list[smallest]){
		smallest = right;
	}

	if(smallest != index){
		swapp(&pq.list[index], &pq.list[smallest]);
		shiftDown(pq, smallest);
	}
}
void shiftUp(priQueue pq, int index)
{
	int parent = getParent(index);
	if(pq.list[index] < pq.list[parent]){
		swapp(&pq.list[parent], &pq.list[index]);
		shiftUp(pq, parent);
	}
}



