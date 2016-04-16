#include<iostream>
using namespace std;

void convertPi(char *a,int start ){

if(a[start]=='\0')
	return;

if(a[start+1]=='\0')
	return;

if(a[start]=='p' && a[start+1]=='i'){
	//Kuch kaam krna ? Btao kya krna hai
	//Shift the remaining elements after replacing pi with 3.14
	int i=0;
	while(a[i]!='\0')
	{ i++; }
	
	while(i>=start+2)
	{ a[i+2] = a[i] ;
	i--;
	}
	
	a[start] = '3';
	a[start+1] = '.';
	a[start+2] = '1';
	a[start+3] ='4';
	
	return convertPi(a,start+4);

}
else{
	return convertPi(a,start+1);
	}
}


int main(){

char str[100];
cin.getline(str,100);
convertPi(str,0);
cout<<str;
return 0;
}
