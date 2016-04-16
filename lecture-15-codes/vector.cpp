#include<iostream>
using namespace std;


class Vector{

int *arr;
int current_size;
int max_size;

public:
	Vector():current_size(0),max_size(4){
		arr = new int[4];
	}
	Vector(int user_size):current_size(0),max_size(user_size){
		arr = new int[max_size];
	}
	int size() const{
		return current_size;
	}
	int getElement(int index) const{
		return arr[index];		
	}
		
	//Copy Constructor
	Vector(Vector const &v){
		arr = new int[2*v.size()];
		current_size = v.size();
		max_size = 2*v.size();
		
		for(int i=0;i<v.size();i++)
			arr[i] =  v.getElement(i);
			
	}
	
	
	void push_back(int no){
		if(current_size<max_size){
			arr[current_size] = no;
			current_size++;
		}
		else{
		  cout<<"Doubling the size of array "<<endl;
		  int *temp = new int[2*max_size];
		  for(int i=0;i<current_size;i++){
			temp[i] = arr[i];
		  }
		  temp[current_size] = no;
		  current_size++;

		  delete [] arr;
  		  arr = temp;
	    	  max_size = max_size*2;
		}		
	}

	int  pop_back(){
	
		if(current_size>0){
			current_size--;
			return arr[current_size];
		}
		else{
			return -1;
		}
	}
	void print() const{
		for(int i=0;i<current_size;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	~Vector(){
		delete [] arr;
	}

};

int main(){
Vector v;

v.push_back(1);
v.push_back(2);
v.push_back(3);
v.print();
cout<<"Popping element "<<v.pop_back();
v.print();
v.pop_back();
v.push_back(4);
v.print(); 

Vector v2(v);
cout<<"Copied Vector is ";
v2.print();
v2.push_back(8);
v2.print();

return 0;
}
