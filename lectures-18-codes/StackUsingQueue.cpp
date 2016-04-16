#include<iostream>
#include "Queue.h"
using namespace std;

class Stack{
	Queue *q1;
	Queue *q2;
public:
	Stack(){
		q1 = new Queue();
		q2 = new Queue();
	}
	Stack(int size){
		q1 = new Queue(size);
		q2 = new Queue(size);
	}

	void push(int data){
		if(q1->isEmpty()&&q2->isEmpty()){
			q1->enQueue(data);
		}
		else if(!q1->isEmpty()){
			q1->enQueue(data);
		}
		else{
			q2->enQueue(data);
		}
	}	
	int pop(){
		if(q1->isEmpty()&&q2->isEmpty()){
			cout<<"Stack is Empty";
			return -1;
		}
		else if(!q1->isEmpty()){
				while(q1->size()>1){
						int temp = q1->deQueue();
						q2->enQueue(temp);
				}
				return q1->deQueue();
		}
		else{

				while(q2->size()>1){
						int temp = q2->deQueue();
						q1->enQueue(temp);
				}
				return q2->deQueue();

		}
	}

};

int main(){
Stack s;
s.push(1);
s.push(2);
s.push(3);

cout<< s.pop();

s.push(4);

cout<<s.pop();

cout<<s.pop();

cout<< s.pop();

cout<<endl;

cout<< s.pop();
return 0;
}


