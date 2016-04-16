#include<iostream>
using namespace std;



void fun(){

cout<<"Fun with no argument"<<endl;

}

void fun(int a){

cout<<"Fun with one argument "<<a<<endl;

}

void fun(int a,int b){

cout<<"Fun with two arguments "<<a <<"and "<<b<<endl;
}

void fun(int a,bool b){
cout<<"Bool vala fun"<<endl;
}


int fun(int a,int b,int c){
return a+b+c;
}

int main(){

fun();
fun(1);
fun(1,2);
cout<<fun(1,2,3)<<endl;
fun(1,false);
return 0;
}
