#include<iostream>
using namespace std;



int main(){

	int a[] = {1,2,3,4};

	cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
	
	int x=10;
	int y =x;

	int arr[4] ={1,2,3,4};
	
	int b[4] ;
	//Copy elements of arr to b 
	for(int i=0;i<4;i++){
			b[i] = arr[i];
			cout<<b[i]<<endl;
	}



	return 0;
}