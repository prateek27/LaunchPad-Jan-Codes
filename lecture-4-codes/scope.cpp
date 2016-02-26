#include<iostream>
using namespace std;

int x;

int main(){

	int i=10;
	x=16;
	int j;
	while(i<15){

		j = 1;
		cout<<j+i<<endl;
		i++;
	}
	cout<<"I am outside while"<<endl;
	cout<<i<<endl;
	cout<<j<<endl;
	x = x + 2;
	cout<<x;
	return 0;
}