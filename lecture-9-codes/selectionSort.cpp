#include<iostream>
using namespace std;


void selectionSortRec(int *a,int start,int n){

if(start==n-1){
	return ;
}

//First Step : Find the minimum element
int min_index=start;
for(int i=start+1;i<n;i++){
	if(a[i] < a[min_index]){
		min_index = i;
	}
}
//Second Step : Bring the smallest element to the starting position
swap(a[start],a[min_index]);

//Third Step : Recursively sort the remaining part.
selectionSortRec(a,start+1,n);
}

int main(){

int arr[] = {9,8,7,6,5,4,3,2,1};

selectionSortRec(arr,0,9);

cout<<"Sorted array is "<<endl;
for(int i=0;i<9;i++)
{
 cout<<arr[i]<<endl;
}

return 0;
}
