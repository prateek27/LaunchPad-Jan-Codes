#include <iostream>
using namespace std;

class demo {
	public:
	static int i;
	static void increment(){
		i++;
		cout << i << endl;
	}
};

int demo::i = 0;

int main() {
	demo::increment();
	demo::increment();
	demo::increment();
	demo::increment();

	demo d;
	d.increment();

	cout<< d.i;
	cout<< demo::i<<endl;
	
	demo d2;
	d2.i =100;

	cout<<d.i<<endl;
	
return 0;
}

