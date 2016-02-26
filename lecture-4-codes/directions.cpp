#include<iostream>
using namespace std;


int main(){

char ch;
ch = cin.get();

int x=0;
int y=0;

while(ch != '\n'){
	
	if(ch=='N')
		y++;
	else if(ch=='S')
		y--;
	else if(ch=='E')
		x++;
	else if(ch=='W')
		x--;

	ch = cin.get();
	}

	if(x>0 && y>0){
		
		for(int i=0;i<x;i++)
				cout<<"E";		
		for(int i=0;i<y;i++)
				cout<<"N";
	}
	if(x<0 && y>0){
				
		for(int i=0;i<y;i++)
				cout<<"N";

		x = -x;
		for(int i=0;i<x;i++)
				cout<<"W";
	}	
	//Write rest 2 cases yourself for third and fourth quadrants.

return 0;
}