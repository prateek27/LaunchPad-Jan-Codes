#include<iostream>
using namespace std;

int factorial(int n){

	if(n==0){
		return 1;
	}
	
	int chotaFactorial = factorial(n-1);
	int ans = n*chotaFactorial;

	return ans;

}

int fibonacci(int n){

	if(n==0||n==1){
		return n;
	}
	int x = fibonacci(n-1);
	int y = fibonacci(n-2);
	int ans = x + y;
	return ans;

}


int main(){

//cout<<factorial(5);
	cout<<"   "<<fibonacci(6)<<endl;

return 0;
}
