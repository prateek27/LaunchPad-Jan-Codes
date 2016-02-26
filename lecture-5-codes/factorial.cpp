#include<iostream>
using namespace std;


unsigned long long factorial(int n){

	unsigned long long ans =1;

	for(int i=2;i<=n;i++){
		ans = ans*i;
	}

return ans;
}



int main(){

unsigned long long ans;
int n,r;
cin>>n>>r;

ans = factorial(n)/ factorial(n-r)*factorial(r);
cout<<ans;

return 0;
}