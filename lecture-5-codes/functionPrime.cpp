#include<iostream>
using namespace std;


bool checkPrime(int n){

	for(int i=2;i<n;i++)
	{
		if(n%i==0){
			return false;
		}

	}

	return true ;
}

void generatePrime(int range){

	for(int no=2;no<=range;no++)
	{
		bool ans=checkPrime(no);

		if(ans ==true){
			cout<<no<<" is prime";
		}
		else{
			cout<<no <<" is not prime !";	
		}
	}	
return 0;
}

int main(){
	int range;
	cin>>range;
	generatePrime(range);

return 0;
}