#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

int stringSearchBruteForce(char *s,char *t){

	int n = strlen(s);
	int m = strlen(t);
	
	for(int i=0; i <= n-m ; i++){
	int j=0;

	for(;j<m;j++){
		if( s[i+j] != t[j]){
			break;
		}
	}
	if(j==m){
		return i;
		}

	}
return -1;
}


int boyer_moore(char *s,char *t){
	int n = strlen(s);
	int m = strlen(t);
	
	//Preprocess the smaller string.
	unordered_map<char,int> last_indices;
	for(int i=0;i<m;i++){
		last_indices[t[i]] = i;
	}

	//Boyer Moore Starts here.
	int i = m -1;
	int j = 0;
	
	while(i < n){
		j = 0;
		
		for(;j<m;j++){
			int smaller_index = m -1-j;

			if(s[i-j] != t[smaller_index]){
			char badChar = s[i-j];
				
			unordered_map<char,int>::iterator it;
			
			it = last_indices.find(badChar);
			if(it == last_indices.end()){
			//Bad char not found in smaller string
			 i = i + (m-j);	
			}
			else{
			// 2 cases - Left or Right
			int position = it->second;	
			//Right Vala Case
			if(position > smaller_index){
				i++;
			}
			//Left Vala Case 
			else{
				i = i + smaller_index - position;
				}
			}		
			break;
			}

		}
		if(j==m){
			return i - (m-1);
		}
	}
return -1;
}

int main(){


char s[100] = "This is a test string";
char t[10] = "str";

cout<< stringSearchBruteForce(s,t) <<endl;
cout<< boyer_moore(s,t)<<endl;
return 0;
}
