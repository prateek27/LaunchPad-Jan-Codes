#include<iostream>
using namespace std;

int a[] = {1,2,3,4,5};

int changeValue(int i){
return a[i];
}


int main(){

changeValue(1) = 100;
changeValue(4) = 400;

for(int i=0;i<5;i++)
{
	cout<<a[i]<<endl;
}

return 0;
}
