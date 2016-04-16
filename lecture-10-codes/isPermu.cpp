#include<iostream>
using namespace std;


bool isPermutation(char a[],char b[]){

int freq1[26] = {0};
int freq2[26] ={0};

for(int i=0;a[i]!='\0';i++){
	freq1[ a[i] - 'a']++;
}

for(int i=0;b[i]!='\0';i++) {
	freq2[b[i] - 'a']++;
}

for(int i=0;i<26;i++){
	if(freq1[i] != freq2[i]){
		return false;
	}
}
return true;
}

int main(){

char a[100];
char b[100];

cin>>a;
cin>>b;

if(isPermutation(a,b)){
	cout<<"Yes It is a Permutation"<<endl;
} 
else{
	cout<<"Not a permutation"<<endl;
}



}
