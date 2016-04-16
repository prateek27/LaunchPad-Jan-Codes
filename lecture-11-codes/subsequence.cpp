#include<iostream>
using namespace std;


int findSubseq(char input[],int start,char output[][20]){

if( input[start]=='\0'){
	output[0][0] = '\0';
	return 1;
}

int smallerOutputSize = findSubseq(input,start+1,output);

	for(int i=0;i<smallerOutputSize;i++){
		output[i+smallerOutputSize][0] = input[start];
		
		for(int j=0;output[i][j]!='\0';j++){
			output[i+smallerOutputSize][j+1]= output[i][j];
		}
	}
	return 2*smallerOutputSize;

}



int main(){

char input[10];
cin>>input;

char output[100][20];

int ans = findSubseq(input,0,output);

for(int i=0;i<ans;i++)
	cout<<output[i]<<endl;

return 0;
}
