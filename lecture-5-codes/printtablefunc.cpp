#include<iostream>
using namespace std;

void printTable(int no_of_rows){

int i=1;
int f = 0;
int c;

while(i<=no_of_rows){

c = 5/9.0*(f - 32);

cout<<f<<" "<<c<<endl;

f = f + 20;
i = i + 1;
}
return;
}




int main(){

int n;
cin>>n;
printTable(n);

return 0;	
}

