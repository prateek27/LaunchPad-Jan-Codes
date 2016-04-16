#include<iostream>
using namespace std;

int knapsack(int wts[],int value[],int n,int capacity){
	if(capacity==0|| n==0)
		return 0; 
	
	if(wts[n-1] > capacity){
		return knapsack(wts,value,n-1,capacity);
	}
	else{
		int including_item = knapsack(wts,value,n,capacity - wts[n-1]) + value[n-1];
		int excluding_item = knapsack(wts,value,n-1,capacity);
		return max(including_item,excluding_item);
	}
}



int main(){


int n=3,w=10;
int wts[] = { 3,4,5};
int price[] ={3,2,1 };

cout<<knapsack(wts,price,n,w)<<endl;

return 0;
}
