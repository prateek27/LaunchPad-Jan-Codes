#include<iostream>
using namespace std;


int main(){


	char key;


	do{

	cout<<"Enter a Key";
	cin>>key;

	switch(key){
		case 'A': cout<<"You Pressed Left";
				   break;
		case 'D': cout<<"You Pressed Right";
					break;
		case 'W': cout<<"You pressed up ";
					break;
		case 'X': cout<<"You pressed down";
					break;
		default: cout<<"Press a Valid Key";	
		}	
		cout<<endl;
	} while(key!='$');


return 0;
}