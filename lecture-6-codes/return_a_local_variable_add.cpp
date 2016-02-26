#include<iostream>
using namespace std;


int* fun(){

	int a[] ={0,1,2,3,4};
	cout<<"In Fun, having some fun "<<endl;
	cout<<a[1]<<a[2]<<a[3]<<a[4]<<endl;
	
	cout<<a<<endl;

	return a;
}


int main(){

	int *ptr = fun();


	cout<<"In Main "<<endl;
	cout<<ptr<<endl;

	for(int i=1;i<=4;i++){
		cout<< *(ptr + i)<<endl ;
	}	

return 0 ;
}