#include<iostream>
#include "Node.h"
using namespace std;


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

int main(){

Stack<char> s;
s.push('a');
s.push('c');

cout<<s.pop();
cout<<s.pop();

Stack<int> si;
si.push(1);
si.push(23);
cout<<endl;
cout<<si.pop()<<endl;
cout<<si.pop()<<endl;

return 0;
}

