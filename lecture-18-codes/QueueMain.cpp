#include<iostream>
#include "Queue.h"
using namespace std;


int main(){

s.push(1);

Queue q(100);
q.enQueue(5);
q.enQueue(6);
q.enQueue(7);
cout<<q.getFront();
q.deQueue();
cout<<q.getFront();
q.deQueue();

q.enQueue(8);
q.enQueue(9);
q.enQueue(10);
cout<<q.getFront();
q.deQueue();
q.deQueue();
q.enQueue(1);
q.enQueue(2);
q.enQueue(3);
q.deQueue();

cout<< q.getFront();


return 0;
}