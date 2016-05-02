#include<iostream>
#include "Stack.h"
using namespace std;



int main(){

Stack<char> s;
s.push('a');
s.push('c');

cout<<s.pop();
cout<<s.pop();

Stack<int> si;
si.push(1);
si.push(23);
cout<<endl;
cout<<si.pop()<<endl;
cout<<si.pop()<<endl;

return 0;
}

