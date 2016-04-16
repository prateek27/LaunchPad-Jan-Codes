#include<iostream>
using namespace std;

void fun(){
//Not Allowed
cout<<"Here"<<endl;
cout<<x<<endl;
}

int main(){

for(int i=0;i<5;i++){
	static int x=0;
	x++;
	cout<<x++<<endl;
	}

//Not ALlowed
cout<<"In main"<<endl;
cout<<x<<endl;


return 0;
}
