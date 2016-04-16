#include<iostream>
using namespace std;


void mergesort(int a[],int start,int end){
	if(start>=end)
	{
	 	return;
	}

	//Divide into two havles.
	int x[100];
	int y[100];

	int mid = (start+end)/2;

	for(int i=start;i<=mid;i++)
	{ x[i] = a[i] ; }
	
	for(int i=mid+1;i<=end;i++){
	 y[i] = a[i];
	}
	//Recursively sort x and y
	mergesort(x,start,mid);
	mergesort(y,mid+1,end);
	
	//Merge the two halves.
	int i= start;
	int j = mid+1;
	int k = start;

	while(i<=mid && j<=end){
		if(x[i] < y[j]){
			a[k] = x[i];
			i++;
			k++;	
		}
		else{
			a[k] = y[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
	{	
		a[k] = x[i];
		i++;
		k++;	
	}
	while(j<=end){
		a[k] = y[j];
		j++;
		k++;
	}

}



void print(int *a,int n){
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
return;
}

int main(){
int n;
int a[100];
cout<<"Enter the the size of Array";
cin>>n;

for(int i=0;i<n;i++){
  a[i] = n-i;
}

cout<<"Array before Sorting";
print(a,n);

mergesort(a,0,n-1);

cout<<"Array after Sorting";
print(a,n);

return 0;
}
