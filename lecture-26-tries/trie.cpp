#include<iostream>
#include<unordered_map>
using namespace std;


class TrieNode{
public:
	char data;
	bool isTerminal;
	unordered_map<char,TrieNode* > children;
 
	TrieNode(char d){	
		data = d;
		isTerminal = false;
	}
};

class Trie{

TrieNode* root;
int numWords;

public:
	Trie(){
		root = new TrieNode('\0');
		numWords = 0;
	}
	//Recursive
	void addWordHelper(char *word,TrieNode*node){
		if(word[0]=='\0'){
			node->isTerminal = true;
			return;
		}
		char currentChar = word[0];
		TrieNode* child = NULL;
	if(node->children.find(currentChar)==node->children.end()){
			//Nahin mila 
			child = new TrieNode(currentChar);
			node->children[currentChar] = child;
		}
		else{
			child = node->children.find(currentChar)->second;
		}
		addWordHelper(word+1,child);
	}
	void addWord(char *word){
		addWordHelper(word,root);
		numWords++; 
	}
	//Iterative
	bool searchWord(char *word){
		TrieNode*currentNode = root;

		for(int i=0; word[i]!='\0';i++){
		if(currentNode->children.find(word[i]) == currentNode->children.end()){
			return false;
		}
		else{
			currentNode = currentNode->children.find(word[i])->second;
		}
		}
	return currentNode->isTerminal;
	}

};


int main(){
Trie t;
char words[][100] = { "nest","new","not","news","apple","ape","banana"};

for(int i=0;i<7;i++){
	t.addWord(words[i]);
}

char searchWords[][100] = { "nest","never","new","news","newest","banan","banana"};

for(int i=0;i<7;i++){
	if(t.searchWord(searchWords[i])==true){
		cout<<searchWords[i]<<" is found in Trie "<<endl;
	}
	else{
		cout<<searchWords[i] <<" not found in Trie "<<endl;
	}

}

return 0;
}
