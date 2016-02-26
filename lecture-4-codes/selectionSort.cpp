#include<iostream>
using namespace std;


int main(){
	
	int a[1000];
	int n;
	
	cout<<"Enter the number of elements u wish to enter:";
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	//Sort ?

	for(int i=0;i<=n-2;i++){

		int min_position=i;

		for(int j=i;j<=n-1;j++){
			if(a[j]< a[min_position]){
					min_position = j;
			}
		}

		int temp = a[i];
		a[i] = a[min_position];
		a[min_position] = temp;
	}

	cout<<"Sorted array is "<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}



	return 0;
}