#include<iostream>
using namespace std;
#define PI 3.14

int myVar;

inline float areacircle(int r){
	return PI*r*r; 
}

inline int getMax(int a,int b){
	myVar =200;
	return a>b?a:b;
}
//Default Value
void fun(int a,int b=10)
{
	cout<<"Value of A is"<<a<<endl;
	cout<<"Value of B is"<<b<<endl;
}



int main(){

int a=10;
int b=20;

cout<<"My Var is "<<myVar<<endl;
cout<<getMax(a,b)<<endl;
cout<<"My Var is "<<myVar<<endl;
cout<<areacircle(1)<<endl;
myVar =300;
cout<<"My Var is "<<myVar<<endl;

/*
fun(12);
fun(12,13);
*/
return 0;
}
