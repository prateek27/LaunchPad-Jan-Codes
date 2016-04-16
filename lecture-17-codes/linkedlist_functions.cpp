#include<iostream>
using namespace std;


class Node{
public:
	int data;
	Node*next;
	Node(int d):data(d),next(NULL){}
};



Node* takeInput(){
Node*head = NULL;
Node*tail = NULL;
int data;
cout<<"Enter the the first element ";
cin>>data;

while(data!=-1){
	if(head==NULL){
		head = new Node(data);
		tail = head;
	}
	else{
	   tail->next = new Node(data);
	   tail = tail->next;
	}
cout<<"Enter the next element : ";
cin>>data;
}

return head;
}

void print(Node*head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<endl;
}

Node* merge(Node*first, Node*second){

Node*result = NULL;

if(first==NULL){
	return second;
}

else if(second==NULL){
	return first;
}

if(first->data < second->data){
	result = first;
	result->next = merge(first->next,second);
}
else{
	result = second;
	result->next = merge(first,second->next);
}

return result;
}

Node*midNode(Node*head){

	Node*slow = head;
	Node*fast = head->next;

	while(fast!=NULL){
		fast = fast->next;
		if(fast!=NULL){
			fast = fast->next;
			slow = slow->next;
		}

	}
	return slow;
}

Node* midNode2(Node*head){
	Node*fast = head->next;
	Node*slow = head;
	
	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
Node* mergeSort(Node*head){

	if(head==NULL||head->next==NULL){
		return head;
	}
	Node*mid = midNode(head);
	//Break into 2 halves
	Node*first = head;
	Node*second = mid->next;
	mid->next = NULL;

	//Recursively Sort two halves
	first = mergeSort(first);
	second = mergeSort(second);
	
	//Merge the two parts	
	Node*result = merge(first,second);
	return result;
}


void reverse(Node*&head){
	Node*prev = NULL;
	Node*current = head;
	Node*nextNode ;
	while(current!=NULL){
		nextNode = current->next;
		current->next = prev;
			
		prev = current;
		current = nextNode;
	}
	head = prev;	
}

Node* ReverseRecursive(Node*head){

	if(head==NULL||head->next==NULL)
		return head;

	Node* smallerPart = ReverseRecursive(head->next);
	Node*temp = smallerPart;
	
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return smallerPart;
}

void printReverse(Node*head){
	if(head==NULL)
			return;

	printReverse(head->next);
	cout<<head->data<<endl;	
	return;
}


int main(){
Node* head = NULL;
head = takeInput();
cout<<"Printing Original "<<endl;
print(head);
cout<<"Printing Reverse"<<endl;
printReverse(head);
/*
Node*head2 = NULL;
head2=takeInput();
print(head2);
*/

//Node*mid = midNode2(head);
//cout<<mid->data<<endl;
/*
Node* outputHead = merge(head,head2);
print(outputHead);
*/

head = mergeSort(head);
print(head);
reverse(head);
print(head);
head = ReverseRecursive(head);
print(head);
return 0;
}
