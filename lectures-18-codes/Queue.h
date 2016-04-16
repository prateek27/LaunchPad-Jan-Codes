#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

class Queue{
	int *arr;
	int current_size;
	int max_size;

	int front;
	int rear;

public:
	Queue(){
		arr = new int[5];
		current_size = 0;
		max_size = 5;
		front = 0;
		rear = 4;
	}
	Queue(int size){
		arr = new int[size];
		current_size = 0;
		max_size = size;
		front = 0;
		rear = max_size-1;
	}

	bool isFull(){
		return current_size==max_size?true:false;
	}
	bool isEmpty(){
		return current_size==0?true:false;

	}

	void enQueue(int data){
		if(!isFull()){
			rear = (rear+1)%max_size;
			arr[rear] = data;
			current_size++;
		}
		else{
			cout<<"Queue is Full !"<<endl;
		}
	}
	int size(){
		return current_size;
	}
	
	

	int deQueue(){
		if(!isEmpty()){
			int temp = arr[front];
			front = (front+1)%max_size;
			current_size--;
			return temp;	
		}
		else{
			cout<<"Cant Dequeue from empty queue !"<<endl;
			return -1;
		}

	}
	int getFront(){
			if(!isEmpty())
				return arr[front];
			else{
				cout<<"Empty Queue";
				return -1;
			}
	}	

	~Queue(){
		delete [] arr;
		arr = NULL;
	}

};

#endif