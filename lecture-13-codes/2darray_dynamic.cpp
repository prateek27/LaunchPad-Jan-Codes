#include<iostream>
using namespace std;


int** initialise_and_allocate(int r,int c){

int **arr = new int*[r];

for(int i=0;i<r;i++){
	arr[i] = new int[c];
}

int count=0;

for(int i=0;i<r;i++){
	for(int j=0;j<c;j++){
		arr[i][j] = count;
		count++;
	}	
}

return arr;
}



int main(){

int r,c;
cin>>r>>c;
int **arr = initialise_and_allocate(r,c);

for(int i=0;i<r;i++){
	for(int j=0;j<c;j++){
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;
}


return 0;
}
