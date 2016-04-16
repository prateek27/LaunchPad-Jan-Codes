#include<iostream>
using namespace std;


int findLast7(int *a,int n){

if(n==0){
	return -1;
}

int chotaArray[100];
for(int i=1;i<n;i++){
	chotaArray[i-1] = a[i];
}

int ans = findLast7(chotaArray,n-1);

if(ans == -1){
//Nahin mila to Kya krein ?
	if(a[0]==7)
		return 0;
	else
	     return -1;
}
else{
	return ans+1;
    }
}

int all7(int a[],int n,int output[]){
if(n==0){
	return 0;	
}

int chotaArray[100];
for(int i=1;i<n;i++){
	chotaArray[i-1] = a[i];
}

// Store the 7 for the smaller array
int ans = all7(chotaArray,n-1,output);

//Bigger Array will have positions as i+1, if 7 exists at i in small
//Update the positions in output array
int i=0;
while(i<ans){
	output[i]++;
	i++;
}

//Check if 7 exists at the zeroth position
if(a[0]==7){
	output[ans] = 0;
	return ans+1;
}
else{
    return ans;
  }
}


int main(){

int a[] = {1,7,5,6,7,7,7,8,7};
int n = sizeof(a)/sizeof(int);
cout<<findLast7(a,n);

int output[100];

int ans = all7(a,n,output);
for(int i=0;i<ans;i++){
	cout<<"Seven found at Position "<<output[i]<<endl;
}

return 0;
}
