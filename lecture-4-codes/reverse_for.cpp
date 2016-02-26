#include<iostream>
using namespace std;


int main(){

	int n;
	cin>>n;

	int rev =0;
	int no;
	
	for(no = n; no > 0 ; no = no/10 ){
		int last = no%10;
		rev = 10*rev + last;	

	}
	cout<<" "<<rev<<endl;

	return 0;
}