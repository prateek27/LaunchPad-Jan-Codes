#include<iostream>
using namespace std;


int main(){

int n;
cin>>n;

int count = 0;

for(int no = n; no>0; no = no>>1 ){
	
	if(no&1>0){
		count++;
	}

}
cout<<count<<endl;

return 0;
}