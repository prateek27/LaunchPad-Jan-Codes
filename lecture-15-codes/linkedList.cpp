#include<iostream>
using namespace std;

class LinkedList;

class Node{
	int data;
	Node *next;
	
public:
	Node():data(0),next(NULL){}
	Node(int d):data(d),next(NULL){}

friend class LinkedList;

};

class LinkedList{
Node*head;

public:
	LinkedList():head(NULL){}
	
	void addAtFront(int data){
	if(head==NULL)	
		{ Node*n = new Node(data);
		  head = n;
		}
	else{
		Node*n = new Node(data);
		n->next = head;
		head = n;
	  }
	
	}
	void print() const{
		Node*temp = head;
		while(temp != NULL){
			cout<<temp->data<<"-->";
			temp = temp->next; 
		}

	}

};

int main(){
LinkedList l;
l.addAtFront(3);
l.addAtFront(2);
l.addAtFront(1);
l.print();
return 0;
}
