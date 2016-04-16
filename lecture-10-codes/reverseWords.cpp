#include<iostream>
using namespace std;

void reverse(char a[],int start,int end){
	while(start<end){
		swap( a[start],a[end]);
		start++;
		end--;
	}
}

void reverseWords(char str[]){

int word_start = 0;
int temp = 0;

//Reverse only the words in the string.
while(str[temp]!='\0'){
	if(str[temp]==' '){
		reverse(str,word_start,temp-1);
		word_start = temp+1;
	}
temp++;
}
//Reverse the last word.
reverse(str,word_start,temp-1);
//Reverse the full string
reverse(str,0,temp-1);
}



int main(){

char a[] = "Welcome to Coding Blocks";
reverseWords(a);
cout<<a<<endl;

return 0;
}
