#ifndef STACK_H
#define STACK_H

#include "Node.h"

template<typename T>
class Stack{
	Node<T> * head;
public:
	Stack():head(NULL){}
	
	void push(T data){
		Node<T> *n = new Node<T>(data);
		n->next = head;
		head = n;
	}

	T pop(){
			
			Node<T>* temp = head;
			head = head->next;
			
			T data = temp->data;
			delete temp;
			return data;
		

	}
	bool isEmpty(){
		return head==NULL?true:false;
	}

};

#endif