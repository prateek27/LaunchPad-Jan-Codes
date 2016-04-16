#include<iostream>
using namespace std;


int* fun(int n){
	int bstatic[] = {1,2,3,4,5};
	
	int *bdynamic = new int[n];
	for(int i=0;i<n;i++)
		bdynamic[i]=i+1;


return bdynamic;
}



int main(){

int *ptr ;
int n;

cin>>n;
/*
ptr = new int[n];

for(int i=0;i<n;i++){
	cin>>ptr[i];
}

for(int i=n-1;i>=0;i--){
	cout<<ptr[i]<<endl;
}
*/

int *ans = fun(n);
for(int i=0;i<n;i++)
	cout<<ans[i]<<endl;

delete[] ans;
return 0;
}
