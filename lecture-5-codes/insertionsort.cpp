#include<iostream>
using namespace std;


void insertionSort(int a[],int n){

for(int i=1;i<=n-1;i++){

	int current_element = a[i];

	int prev = i-1;

	while(prev>=0 && a[prev]> current_element){
		
		a[prev+1] = a[prev]; 

	 prev = prev -1;
	}

		a[prev+1] = current_element;
	}

}



int main(){
int a[100];

for(int i=0;i<5;i++){
	cin>>a[i];
}

insertionSort(a,5);
for(int i=0;i<5;i++){

	cout<<a[i]<<endl;
}


}