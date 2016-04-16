#include<iostream>
#include<time.h>
using namespace std;

void selectionSort(int a[],int n){


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


return ;
}

	int x[1000000];
	int y[1000000];


void mergesort(int a[],int start,int end){
	if(start>=end)
	{
	 	return;
	}

	//Divide into two havles.

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




int main(){
int n;
int a[1000000];

clock_t t;

cout<<"Enter the the size of Array";
cin>>n;

for(int i=0;i<n;i++){
  a[i] = n-i;
}


t = clock();
mergesort(a,0,n-1);
t = clock() - t;

cout<<"For "<<n<<" elements Merge sort took :"<<t<<" milliseconds."<<endl;

for(int i=0;i<n;i++){
  a[i] = n-i;
}

t = clock();
selectionSort(a,n);
t = clock() - t;

cout<<"Time "<<n <<"elements Selection Sort took: "<<t<<" milliseconds."<<endl;

return 0;
}
