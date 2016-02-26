#include<iostream>
using namespace std;


void increment( int number,int kitna){

	cout<<"Inside funtion "<<endl;
	number = number + kitna;
	cout<<number<<endl;

	cout<<"Returning from function "<<endl;

return ;
}

void increment_new(int *number,int kitna){

	*number = *number + kitna;

	cout<<number<<endl;

	return;
}

int main(){

	int number = 5;
	cout<<number<<endl;

	//increment(number,10);
	cout<<&number<<endl;
	increment_new(&number,10);

	cout<<number<<endl;


	return 0;
}