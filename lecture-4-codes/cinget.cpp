#include<iostream>
using namespace std;


int main(){

char ch;
int i=1;

while(i<=5){
	ch = cin.get();
	if(ch ==32){
		cout<<"You entered a Space "<<endl;

	}else if(ch =='\n'){

		cout<<"You pressed enter !"<<endl;
	}
	else{
		cout<<"You entered "<<ch<<endl;

	}
	i++;
}


}