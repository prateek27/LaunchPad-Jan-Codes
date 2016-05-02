#ifndef HASH_NODE_H
#define HASH_NODE_H

#include<cstring>

template<typename V>
class hashNode{
public:	
	V data;
	hashNode<V> *next;
	char *key;

	hashNode(char *key,V data){
		this->data = data;
		this->key = new char[strlen(key)+1];
		strcpy(this->key,key);
		next = NULL;	
	}
	~hashNode(){
		if(next!=NULL)
			delete next;
		delete [] key;
	}
};
#endif




