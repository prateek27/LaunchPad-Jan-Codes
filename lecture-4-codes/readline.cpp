#include<iostream>
using namespace std;


int main(){

char ch;
int count=0;

ch = cin.get();

while(ch != '$'){
	cout<<ch;
	count++;
	ch = cin.get();
	}

	cout<<"Total No of characters entered "<<count<<endl;

return 0;
}