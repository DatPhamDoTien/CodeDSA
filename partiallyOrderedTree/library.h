#include <iostream>
using namespace std;


const int MAX = 100;
struct priQueue{
	int list[MAX];
	int count;
};

void init(priQueue& pq);
bool isEmpty(priQueue pq);
bool isFull(priQueue pq);
int getFirst(priQueue pq);
int getParent(int i);
int getLeftChild(int i);
int getRightChild(int i);
void swapp(int* x, int* y);
void shiftDown(priQueue& pq, int i);
void shiftUp(priQueue& pq, int index);
void insertKey(priQueue& pq, int key);
void createPriQueue(priQueue& pq);
void printQueue(priQueue pq);
void deleteKey(priQueue& pq);


