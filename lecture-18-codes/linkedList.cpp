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
Node*tail;

static int searchHelper(Node*start,int key){
	if(start==NULL){
		return -1;
	}
	if(start->data == key){
		return 0;
	}
	int chotaAns = searchHelper(start->next,key);
	if(chotaAns==-1){
		return -1;
	}
	else{
		return chotaAns + 1;
	}


}

public:
	LinkedList():head(NULL),tail(NULL){}
	
	LinkedList( LinkedList const&l ){
		
		Node*temp = l.head;
		tail = NULL;
		head = NULL;
		while(temp!=NULL){
		if(tail==NULL)
			{ Node*n = new Node(temp->data);
			  head = n;
			  tail = n;
			}
		else{
			tail->next = new Node(temp->data);
			tail = tail->next;
		  }
			
		temp = temp->next;
		}
	}
	void addAtFront(int data){
	if(head==NULL)	
		{ Node*n = new Node(data);
		  head = n;
		  tail = n;
		}
	else{
		Node*n = new Node(data);
		n->next = head;
		head = n;
	  }
	
	}
	int size(){
	 Node*temp = head;
	 int count =0;
		while(temp!=NULL){
			count++;
			temp = temp->next;
		}
		return count;
	}
	
	int search(int key){
		Node*temp = head;
		int pos = 0;
		while(temp!=NULL){
			if(temp->data == key){
				return pos;
			}
		temp = temp->next;
		pos++;
		}
		return -1;
	}
	void bubbleSort(){
		int n = size();
		for(int i=0;i<n;i++){
			Node*prev = NULL;
			Node*current = head;

			while(current!=NULL && current->next!=NULL){
			if(current->data > current->next->data){	
			if(prev==NULL){
				Node*nextNode = current->next;
				current->next = nextNode->next;
				nextNode->next = current;
				head = nextNode;
				prev = head;
			}
			else{
			  Node*nextNode = current->next;
			 current->next = nextNode->next;
			prev->next = nextNode;
			nextNode->next = current;
			prev = nextNode;
			}
			
		   }
		else{
			prev = current;
			current = current->next;
			
				}
			}

		}
	}	
	int searchRecursive(int key){
		int ans = searchHelper(head,key);
		return ans;
	}
	void addAtEnd(int data){
		if(head==NULL){
			Node*n = new Node(data);
			head = n;
			tail = n;
		}
		else{
			Node*n = new Node(data);
			tail->next = n;
			tail = tail->next;
		}
	}
	void insertInMiddle(int pos,int data){
		if(pos==0)
		{
			addAtFront(data);
			return;
		}
		else{
		   int count=0;
		   Node*temp = head;
		  while(count<pos-1){
			temp= temp->next;
			count++;
		  }		
			
		 Node* n  = new Node(data);
		 n->next = temp->next;
		 temp->next = n;
		}
	

	}

	void print() const{
		Node*temp = head;
	
		while(temp != NULL){
			cout<<temp->data<<"-->";
			temp = temp->next; 
		}
		cout<<"NULL"<<endl;
	}

	~LinkedList(){
		Node*temp = head;

		while(temp!=NULL)
			{
//			cout<<"Deleting memory for "<<head->data<<endl;	
			temp = head->next;		
			delete head;
			head = temp;
			}
					
	}

};

int main(){
LinkedList l;
l.addAtFront(3);
l.addAtFront(2);
l.addAtFront(1);
l.addAtEnd(4);
l.addAtEnd(5);
l.insertInMiddle(2,34);
//l.addAtFront(0);
l.print();
l.print();
LinkedList l2(l);
cout<<"Printing L2 "<<endl;
l2.print();
l.insertInMiddle(3,45);
l2.print();
cout<<"Printing L1"<<endl;
l.print();
cout<<"Position of key 45 is "<<l.search(45)<<endl;
cout<<"Position of key 58 is "<<l.search(58)<<endl;
cout<<endl;
l.bubbleSort();
cout<<"Sorted Linked List is "<<endl;
l.print();
cout<<"Search Recursive - Position "<<l.searchRecursive(45)<<endl;
return 0;
}
