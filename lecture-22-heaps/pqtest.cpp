#include<iostream>
#include "priority_queue.h"
using namespace std;



int main(){

PriorityQueue pq ;
/*
pq.push(1);
pq.push(3);
pq.push(5);
pq.push(0);
// pq.print();
cout<< pq.removeMax();
pq.push(7);
*/

int arr[] = {1,9,7,4,5,6};

for(int i=0;i<6;i++){
	pq.push(arr[i]);
}
for(int i=0;i<6;i++){
	arr[5-i] = pq.removeMax();
}

for(int i=0;i<6;i++){
	cout<< arr[i]<<endl;
}
cout<< endl;


return 0;
}
