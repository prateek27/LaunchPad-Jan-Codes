#include<iostream>
#include<map>
#include<cstring>
using namespace std;


int main(){
	map<string,int>  m;
	m["Isha"] = 40;
	m["Rohan"] =100;

	cout<< m["Isha"];
	
	cout<< sizeof(m.count(""));
	if( m.count("Prateek") ==0){
		cout<<"Not found "<<endl;
	}
				
	
return 0;
}
