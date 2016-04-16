


#include<iostream>
using namespace std;


void towerOfHanoi(int n,char source,char dest,char helper){

if(n==0)
	return;

towerOfHanoi(n-1,source,helper,dest);

cout<<"Shifting "<<n<<"th disk from "<<source<<" to "<<dest<<endl;

towerOfHanoi(n-1,helper,dest,source);

}

int main(){

int n;
cin>>n;
towerOfHanoi(n,'A','C','B');

return 0;
}
