#include<iostream>
using namespace std;


int main(){

char ch;
int count=0;

ch = cin.get();

int digits=0;
int alphabets =0;
int spaces=0;

while(ch != '$'){
	if(ch>='0'&&ch<='9'){
		digits++;
	}
	else if((ch>='a'&&ch<='z') || (ch>='A' && ch<='Z')){	
		alphabets++;
	}
	else if(ch==' '||ch=='\n'||ch=='\t'){
		spaces++;
	}

	ch = cin.get();
	}

	cout<<"Total No of characters entered "<<alphabets<<endl;

	cout<<"Total No of digits entered "<<digits<<endl;

	cout<<"Total No of spaces entered "<<spaces<<endl;

return 0;
}