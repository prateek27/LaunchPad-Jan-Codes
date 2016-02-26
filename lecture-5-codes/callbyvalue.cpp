#include<iostream>
using namespace std;


int testFunc(int a){
a=a-5;
return a;
}


int main(){

int a=10;
testFunc(a);
testFunc(a);
cout<<a;

return 0;
}