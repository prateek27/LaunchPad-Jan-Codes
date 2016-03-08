#include<iostream>
using namespace std;

void readString(char  arr[],int limit){

char ch;
ch = cin.get();
int index = 0;

while(ch != '\n'){
	arr[index] = ch ;
	index++;
	
	if(index==limit-1){break;}	

	ch = cin.get();	
}
arr[index] = '\0';
return ;
}
int getLength( char *ptr){ 
	int len=0;
	int i=0;
	while(ptr[i] != '\0'){
		i++;
		len = len + 1;
	}	
return len;
}

bool isPalindrome(char *arr){
	int start = 0;
	int last = getLength(arr) - 1;
	
	while(start < last) { 
		if(arr[start] == arr[last]){
			start = start + 1;
			last = last -1 ;
		}
		else{
			return false;
		}
	 } 
return true;
}	




int main(){

char arr[20];
cout<<"Enter a String "<<endl;
readString(arr,20);
//cin.getline(arr,20);
cout<<arr<<endl;
cout<<"Length of string is "<<getLength(arr)<<endl;
if( isPalindrome(arr) ) {
	cout<<"String is Palindrome "<<endl;
}
else{
	cout<<" Not a Palindrome "<<endl;
}

return 0;
}
