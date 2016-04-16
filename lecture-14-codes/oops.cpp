#include<iostream>
#include<cstring>

using namespace std;

class Student{

	const int roll_no;
	char *name;
	int height;
public:
	Student():roll_no(0){
		cout<<"Default constructor called"<<endl;
		name = NULL;
	}
	Student(int roll):roll_no(roll){
	//	roll_no = roll;
		name = NULL;
	}
	Student(int r,char *n):roll_no(r),height(10){
		//roll_no = r;
		name = new char[strlen(n) + 1];
		strcpy(name,n);
	}
	//Copy Constructor
	Student(Student &s):roll_no(s.roll_no){
		//roll_no = s.roll_no;
		name = new char[strlen(s.name) + 1];
		strcpy(name,s.name);
	}



	void setRollNo(int r){
		if(r>=0&&r < 1000){
	//	roll_no = r;
		}
	}
	int getRollNo(){
		return roll_no;
	}
	char* getName(){
		return name;
	}

	~Student(){
		cout<<"Destroying the object with roll no"<<roll_no<<endl;
	      if(name!=NULL)	
         	     delete [] name;
	}
};

int main(){

char a[] = "prateek";

Student s;
s.setRollNo(100);
cout<<s.getRollNo()<<endl;

Student s2(20);
cout<<s2.getRollNo()<<endl;

Student s3(30,a);
cout<<s3.getRollNo()<<endl;
cout<<s3.getName()<<endl;

a[0] = 'A';
a[1] = 'p';
a[2] = 'u';
a[3] = '\0';

Student s4(40,a);
cout<<s3.getName()<<endl;
cout<<s4.getName()<<endl;

Student s5(s4);
cout<<"Student 5"<<endl;
cout<<s5.getName()<<endl;
cout<<s5.getRollNo()<<endl;

Student s6;
//s6 = s5;
//Dyanmic Student Object
Student *s11 = new Student(489);
Student *s12 = new Student(59);
delete s12;
//DYNAMIC OBJECTS
cout<< "Dynamic Student Created "<<endl;
cout<< (*s11).getRollNo() <<endl;

cout<< s11->getRollNo() <<endl;
delete s11;

return  0;
}
