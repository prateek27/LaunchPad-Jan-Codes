#include<iostream>
using namespace std;

 void print(int n){
 	if(n==0){
		return;
	}

	char a[][100] = {"zero", "one" , "two","three","four",
	"five","six","seven","eight","nine"};

	int last_digit = n%10;
	int chotaNo = n/10;
	
//	cout<< a[last_digit]<<endl;	
	print(chotaNo);
	cout<<a[last_digit]<<" ";
	
 }



int main(){

print(2048);

return 0;
}
