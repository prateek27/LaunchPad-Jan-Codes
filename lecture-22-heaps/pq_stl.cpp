#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;


class compare{
public:
	bool compare(const int&a,const int&b){
		return a>b;
	}		

}


int main(){

priority_queue<int,vector<int>,compare > pq;

for(int i=0;i<5;i++)
	pq.push(i);

while(!pq.empty()){
	cout<< pq.top();
	pq.pop();
}


return 0;
}
