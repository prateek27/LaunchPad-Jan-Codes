#include<iostream>
using namespace std ;


int *func(){

	cout<<"In Func "<<endl;
	int arr[] = {1,2,3};

	cout<<arr<<endl;
	cout<<*(arr)<<endl;
	return arr;
}

int main(){

int *ptr = func();

cout<<"In Main "<<endl;
cout<<ptr<<endl;

cout<< *(ptr+0) <<endl;
cout<< *(ptr) <<endl;

return 0;
}