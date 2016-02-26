#include<iostream>
using namespace std;



void swapnew(int *a,int *b){
	
	int temp = *a;
	*a = *b;
	*b = temp;

	// cout<<"In Swap Function "<<endl;
	// cout<<*a<<endl;
	// cout<<*b<<endl;
}


void BubbleSort( int *arr,int n){

for(int i=0;i<=n-2;i++){

	for(int j=0;j<=n-i-2;j++){
		if(arr[j] > arr[j+1]){
			swapnew(&arr[j],&arr[j+1]);
			}
		}
	}
}

void print(int *arr,int n){
	for(int i=0;i<n;i++){
			cout<<arr[i]<<" 	";
	}
	cout<<endl;
}


int main(){

	int arr[5] ={5,2,1,8,6};
	BubbleSort(arr,5);
	print(arr,5);

	//cout<<(*(arr+500) - *(arr+3))<<endl;

	cout<< *arr+1 <<endl;
	cout<<arr<<endl;
	cout<<&arr<<endl;
	return 0;
}