#include<iostream>
using namespace std;

bool compare(char str1[],char str2[]){
	
	int i=0;
	while(str1[i]!='\0' && str2[i]!='\0'){
		if(str1[i]!=str2[i]){
			return false;
		}
		
	i++;
	}
		
if(str1[i]=='\0' && str2[i]=='\0')
	return true;

else 
	return false;

}



bool search( char arr[][100],int rows,char key[]){
		
	for(int i=0;i<rows;i++){
		if(compare(arr[i],key)==true){
				return true;
			}
	}
	
return false;
}


int main(){

	char myArray[20][100];
	char key[100];

	int n;
	cin>>n;
	
	cin.get();
	
	for(int i=0;i<n;i++){
		cin.getline( myArray[i], 100 );
	}
	
	cin.getline(key, 100);
	if(search(myArray,n,key)){
		cout<<"Mil gya "<<endl;
	}
	else{
		cout<<"Nahin mila"<<endl;
	}
	

	cout<<"Yeh ho gye print --> "<<endl;

	for(int i=0;i<n;i++){
		cout<<myArray[i]<<endl;
	}
	

	return 0;
}
