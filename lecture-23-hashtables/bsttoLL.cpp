#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node*left;
	Node*right;
	Node(int d):left(NULL),right(NULL),data(d){}	
};

class LinkedList{
public:
	Node*head;
	Node*tail;
};

LinkedList bstToLL(Node*root){
	LinkedList output;
	
	if(root==NULL){
		output.head = NULL;
		output.tail = NULL;
		return output;
	}
	LinkedList leftLL = bstToLL(root->left);
	LinkedList rightLL = bstToLL(root->right);

	if(leftLL.head!=NULL){
		output.head = leftLL.head;
		leftLL.tail->right = root;
	}
	else{
		output.head = root;
	}
	if(rightLL.head!=NULL){
		root->right = rightLL.head;
		output.tail = rightLL.tail;
	}
	else{
		output.tail = root;
	}
	return output;
}

void print(LinkedList l){
	while(l.head!=NULL){
		cout<<l.head->data<<"---> ";
		l.head = l.head->right;
	}
}

int main(){

Node*root = new Node(10);
root->left = new Node(8);
root->right = new Node(12);
root->left->left = new Node(6);
root->left->right = new Node(9);
root->right->left = new Node(11);
root->right->right = new Node(13);
root->right->right->right = new Node(15);

LinkedList l = bstToLL(root);
print(l);

return 0;
}
