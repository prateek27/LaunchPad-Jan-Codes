#include<iostream>
using namespace std;


void readline(char *line,int N){

int index=0;
char ch;

do{
	ch = cin.get();
	line[index] = ch;
	index++;	
}
while(ch!='\n');
line[index] = '\0';
return;
}


int main(){
	
	char arr[100];
	cout<<"Enter no of lines you wish to enter";
	readline(arr,100);
	cout<<arr<<endl;

	return 0;
}
