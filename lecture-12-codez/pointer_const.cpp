#include<iostream>
using namespace std;


int main(){

const int x = 10;

//Pointer to a constant 
const int*ptr = &x;
//Not Allowed
//(*ptr)++;

int y = 20;
y++;
ptr = &y;
cout<<(*ptr)<<endl;
/*
cout<<(*ptr)++<<endl;
*/

//Case 2 COnstant Pointer
int z = 20, b =20 ;
int *const ptr2 = &z;

//Not allowed
//ptr2 = &b;


//Case 3 
const int a = 10;
const int*const ptra = &a;
cout<<*ptra<<endl;

//Not Allowed
//(*ptra)++;
//a++;

return 0;
}
