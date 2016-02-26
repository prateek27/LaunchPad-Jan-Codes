#include<iostream>
using namespace std;


int main(){

char ch;
ch = cin.get();
int words=0;
char prev =0;
int lines=1;

while(ch != '$'){
	
	if((ch==' '||ch=='\n')&&( (prev>='a'&&prev<='z')||(prev>='A'&&prev<='Z'))){
		words++;
	}
	if(ch=='\n'){
		lines++;
	}

	prev = ch;
	ch = cin.get();
	}

	if((prev>='a'&&prev<='z')||(prev>='A'&&prev<='Z')){
		words++;
	}

	cout<<"Total No of words entered "<<words<<endl;

	cout<<"Total No of lines entered "<<lines<<endl;

return 0;
}