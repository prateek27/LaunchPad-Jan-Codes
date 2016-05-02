#include<iostream>
#include "Stack.h"
using namespace std;


void insertAtBottom(Stack<int> &s,int data);

void reverse(Stack<int> &s){
	if(s.isEmpty()){
			return;
	}
	else{
		int data = s.pop();
		reverse(s);
		insertAtBottom(s,data);
		return;
	}
}

void insertAtBottom(Stack<int> &s,int data){
	if(s.isEmpty()){
		s.push(data);
		return ;
	}
	else{
		int temp = s.pop();
		insertAtBottom(s,data);
		s.push(temp);
		return;
	}
}

int main(){

Stack<int> s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
s.push(6);

reverse(s);

while(!s.isEmpty()){
	cout<< s.pop()<<endl;
}
cout<<"Ho gya Reverse !";

return 0;
}