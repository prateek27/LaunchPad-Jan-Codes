#include<iostream>
using namespace std;


void swap(int &a,int &b){

int temp = a;
a = b;
b = temp;

return;
}



int main(){

int x;
x=29;
int &y = x;
y++;
x++;

cout<<x<<endl;
cout<<y<<endl;

int a1=10;
int b1 = 20;

swap(a1,b1);

cout<<a1<<endl;
cout<<b1<<endl;
return 0;
}
