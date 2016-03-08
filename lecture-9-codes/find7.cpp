#include<iostream>
using namespace std;

 int firstSevenOcc(int a[],int n){
  if(n==0){
  	return -1;
  }
  if(a[0]==7){
	return 0;
  }
  int chotaArray[100];
	for(int i=1;i<n;i++){
		chotaArray[i-1]= a[i];
	}

  int chotaIndex = firstSevenOcc(chotaArray,n-1);
  
    if(chotaIndex==-1)
	return -1;
   else
  	 return chotaIndex + 1;
  
}

bool is7present(int a[],int n){

	 if(n==0){
		return false;
	 }
	 int chotaArray[100];
 	for(int i=1;i<n;i++){
		chotaArray[i-1] = a[i];
	 }	

 	if(a[0] ==7 || is7present(chotaArray,n-1)){
		return true;
	 }
	 else{
		return false;
 	}

 }


int main(){
int a[100];
int n;
cin>>n;
for(int i=0;i<n;i++){ cin>> a[i] ; } 


if(is7present(a,n)){
	cout<<"Seven Found !"<<endl;
}
else{
	cout<<"Couldnt find Seven!"<<endl;
}

cout<<"First Occurence of Seven is"<<firstSevenOcc(a,n)<<endl;

return 0;
}
