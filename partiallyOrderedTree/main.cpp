#include "library.h"



int main(){
	priQueue pq;
	init(pq);
	createPriQueue(pq);
	printQueue(pq);
	deleteKey(pq);
	cout<<"\nDelete key: "; printQueue(pq);
	return 0;
}
