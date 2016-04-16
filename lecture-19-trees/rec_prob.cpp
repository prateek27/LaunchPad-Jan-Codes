#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


void print(char arr[],int start,char output[],int i,vector<string> &v){

	if(arr[start] == '\0'){
		string s(output);
		//cout<<s<<endl;
		v.push_back(s);
		return;
	}

	int firstDigit =  arr[start] - '0';
	


	//Case:1 First Digit 
	char firstChar =  64+firstDigit;
	output[i] = firstChar;
	output[i+1] = '\0';
	print(arr,start+1,output,i+1,v);
	
	//Case 2: First & Second Digit
	if(arr[start+1]!='\0'){
	int secondDigit = arr[start+1] - '0';
	int no = firstDigit*10 + secondDigit;
	if(no <=26&&no>0){
		char ch = 64 + no;
		//cout<<ch ;
		output[i] = ch;
		output[i+1] = '\0';
		print(arr,start+2,output,i+1,v);
		}
	}
	return ;
}	

int main(){

char input[] = "1234";
char output[10] ;
vector<string>  v;
print(input,0,output,0,v);

cout<<"Printing the strings saved in the vector "<<endl;
for(int i=0;i<v.size();i++){
		cout<< v[i] <<endl;
}

return 0;
}
