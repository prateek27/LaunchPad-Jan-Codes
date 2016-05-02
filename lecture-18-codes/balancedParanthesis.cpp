#include<iostream>
#include "Stack.h"
using namespace std;

bool isBalanced(char input[]){
	Stack<char> s;

	for(int i=0;input[i]!='\0';i++){
			char ch = input[i];

			switch(ch){
				case '(' : s.push(ch);
							break;
				case '[' : s.push(ch);
							break;
				case '{' : s.push(ch);
							break;

				case ')' : if(!s.isEmpty()&& s.pop()=='(')
						    { }
						    else 
						    {
						    	return false;
						    }
						    break;
        		case ']' : if(!s.isEmpty()&& s.pop()=='['){}
        					else{
        						return false;
        					}
        					break;
        		case '}': if(!s.isEmpty()&& s.pop()=='{'){}
        					else{
        						return false;
        					}
        					break;
        		default: continue;			
			}
	}
	if(s.isEmpty())
		return true;
	else
		return false;
}




int main(){
	char input[] = "{ a + (b+c) + ([d+e]*f)) } + k";

	if(isBalanced(input)){
		cout<<"Balanced hai !"<<endl;
	}
	else{
		cout<<"Balanced Nahin hai "<<endl;

	}
return 0;
}