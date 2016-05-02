#include<iostream>
using namespace std;


int editDistance(char *a,char *b,int m,int n){
if(m==0)
	return n;
else if(n==0)
	return m;

else if(a[m-1] == b[n-1])
	return editDistance(a,b,m-1,n-1);

else{
   int insert = editDistance(a,b,m,n-1) + 1;
   int del   = editDistance(a,b,m-1,n) +  1;
   int replace = editDistance(a,b,m-1,n-1) + 1;
   return min(insert,min(del,replace));	
 }
}

int lcs(char *a,char *b,int m,int n){
	if(m==0||n==0)
		return 0;

	if(a[m-1]==b[n-1])
		return lcs(a,b,m-1,n-1) + 1;

	else{
		return max(lcs(a,b,m,n-1), lcs(a,b,m-1,n));
	}
}


int main(){
char a[] = "saturday"; //  "apple";
char b[] =  "sunday"; // "aqpe";
cout<< editDistance(a,b,8,6)<<endl;
cout<<"LCS is "<<lcs(a,b,8,6);

}
