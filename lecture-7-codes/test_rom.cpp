#include<iostream>
using namespace std;



int main(){

char *ptr1 = "abc";

char ptr[] = "abc";

cout<<sizeof(ptr1);
cout<<endl;
cout<<sizeof(ptr);

ptr1[0] = 'x';

ptr[0] = 'x';

}
