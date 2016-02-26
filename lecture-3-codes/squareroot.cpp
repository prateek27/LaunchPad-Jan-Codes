#include<iostream>
using namespace std;

//Program to find square root of a given number.

int main(){

float ans = 0;
float inc = 1;
int n;
int current_precision=0;
int precision;
cout<<"Please enter a number & precision :"<<endl;

cin>>n>>precision;


while(current_precision<=precision){

	
	while(ans*ans <= n){	
	ans = ans + inc;
	}
	ans = ans - inc;
	inc = inc/10;

	current_precision = current_precision + 1;
	
}

cout<<ans<<endl;


return 0;	
}