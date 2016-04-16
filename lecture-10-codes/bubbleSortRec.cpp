#include<iostream>
using namespace std;

void bubbleSortRec(int a[],int n){

if(n==0){
	return;
}
for(int i=0;i<n-1;i++){
	if(a[i] > a[i+1]){
		swap(a[i],a[i+1]);
	}
}
bubbleSortRec(a,n-1);
}


int main(){

int a[] = {6,5,4,3,2,1};
bubbleSortRec(a,6);

for(int i=0;i<6;i++)
{ cout<<a[i]<<" "<<endl; }
return 0;
}



