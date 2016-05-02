#include<iostream>
#include<cstring>
#include "hashtable.h"
#include "hashnode.h"
using namespace std;

class Person{
public:
	int age;
	int weight;
	char *name;

	/* Default Constructor - MANDATORY */
	
	Person(){
		age = -1;
		weight = -1;
		name = new char[1];
		name[0] = '\0';
	
	}
	
	/*  Copy Constructor */ 
	Person( Person const  &p){
		this->age = p.age;
		this->weight = p.weight;
		this->name = new char[strlen(p.name)];
		 strcpy(this->name,p.name);
	}
	// Copy Assignment Operator 
	Person& operator=( const Person & p){
		this->age = p.age;
		this->weight = p.weight;
		this->name = new char[strlen(p.name)];
		strcpy(this->name,p.name);
	return *this;
	}

	Person(char *name,int age,int weight){
		this->name = new char[strlen(name)];
		strcpy(this->name,name);
		this->age = age;
		this->weight = weight;
	}
};


int main(){

HashTable<int> h;

char a[] = "John";
h.insert(a,50);


//h.insert("CodingBlocks",100);

char b[] = "Rohan";
char c[] = "Coding";
h.insert(b,80);
h.insert(c,40);
cout<< h.find(a)<<endl;
cout<< h.find(b) <<endl;
//h.print();
//cout<< h.find(c) <<endl;

char d[]= "somekey";

//if(h.find(d)==0)

	//{ cout<< "Random key  Not found " ; }	

char names[10][100] = {"modi", "aakarshak", "garima" , "rahul"};

Person *p1= new Person(names[0],6,65);
Person *p2= new Person(names[1],5,50);
Person *p3= new Person(names[2],20,45);
Person *p4= new Person(names[3],25,87);


HashTable<Person> h2;
h2.insert(names[0], *p1);
h2.insert(names[1], *p2);
h2.insert(names[2], *p3);
h2.insert(names[3], *p4);

cout<<"Garima ki Age " <<h2.find((*p3).name).age<<endl;
cout<<"Modi ka Weight "<< h2.find(names[0]).weight<<endl;
//Try to search for key that is not inserted
if( h2.find("RandomPerson").name == '\0' || h2.find("RandomPerson").age == -1 )
	cout<<"Random Person Not Found "<<endl;

delete p2;
cout<<"Aakarshak ka full Name " <<h2.find(names[1]).name <<endl;
h2.print();


return 0;
}
