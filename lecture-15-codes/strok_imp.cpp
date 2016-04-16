#include<iostream>
using namespace std;


char* mystrtok( char str[], char delim){
static char*input = NULL;
 if(str!=NULL)
	{
	 input = str;
	}
 if(input==NULL){
	return NULL;
  }
	
  int i=0;
  char *output = new char[strlen(input) + 1];

  for(i=0;input[i]!='\0';i++){
	
	if(input[i]==delim){
		//Kuch kaam krna hai 
		output[i] = '\0';
		input = input + i + 1;
		return output;
	}
	else{
	output[i] = input[i];		
	}
   }
   output[i] = '\0';
   input = NULL;
   return output;
}


int main(){

  char a[100];
  cin.getline(a,100);
  char delim = cin.get();  
  
  char*token = mystrtok(a,delim);
  
  while(token!=NULL){
	cout<<token<<endl;
	token = mystrtok(NULL,delim);
	} 

return 0;
}
