#include<iostream>
using namespace std;

 bool isSorted(int *a, int n){
	if(n==1||n==0){
		return true;
	}
	
	int chotaArray[100];

	for(int i=1;i<n;i++){
		chotaArray[i-1] = a[i];
	}

	if(a[0] <= a[1] && isSorted(chotaArray,n-1)){
		return true;
	}
	else{
		return false;
	} 	

	

  }


int main(){

int arr[] = { 1,2,3,10,5,6,7,8,9};
int n = sizeof(arr)/sizeof(int);


if(isSorted(arr,n)){
	cout<<" Sorted hai ";
}
else
{
	cout<<"Sorted Nahin hai";
}
cout<<endl;

return 0;
}
