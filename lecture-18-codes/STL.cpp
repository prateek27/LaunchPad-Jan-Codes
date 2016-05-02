#include<iostream>
#include<stack>
#include<queue>
using namespace std;



int main(){

stack<int> s;
queue<int> q;

for(int i=0;i<5;i++)
		q.push(i);

//Empty the queue into stack
while(!q.empty()){
	int temp = q.front();
	q.pop();
	s.push(temp);
}

//Empty the stack into queue
while( !s.empty()){
	int top = s.top();
	s.pop();
	q.push(top);
}

while(!q.empty()){
	cout<<q.front()<<" ";
	q.pop();
}


return 0;
}