#include<iostream>
using namespace std;


class pairs{

public:
int x;
int y;

public:
	pairs():x(0),y(0){}
	
	pairs(int x){
		this->x = x;
		y = 0;
	}
	pairs(int x,int y){
		this->x = x;
		this->y = y;
	}
	
	bool operator< (pairs const &p){
		if( x == p.x) {
			return y < p.y;
		}
		else{
			return x < p.x;
		}
	}
	/*void operator+(pairs const &p2){
		x = x + p2.x;
		y = y + p2.y;
		return;
	}*/
	pairs operator+(pairs const&p2){
		pairs p3;
		 p3.x = x + p2.x;
		 p3.y = y + p2.y;

		return p3; 
	}
	void operator!(){
		x = -x;
		y = -y;

	}
	void operator=(pairs const&p){
			x= p.x;
			y = p.y;
	}

	void print(){
		cout<<"( "<<x<<","<<y<<" )"<<endl;
	}

};

int main(){

pairs p1(5,3);
pairs p2(5,6);

if( p1<p2 ){

	cout<<"P1 chota hai ";
}
else{

	cout<<" P2 chota hai";
}
//p1.lessthan(p2);
//p1+p2;
pairs p4(1,1);
pairs p3 = p1+p2+p4;
p1.print();
p2.print();
p3.print();

!p3;
p3.print();

pairs p5 ;
p5=p3;
p5.print();
return 0;
}
