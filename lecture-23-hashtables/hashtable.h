#ifndef HASH_TABLE
#define HASH_TABLE
#include<iostream>
#include<cstring>
#include "hashnode.h"
using namespace std;


template<typename V>
class HashTable{
	int currentSize;
	hashNode<V> **buckets;
	int tableSize;

	void rehash(){
		
		int oldTableSize = tableSize;
		tableSize = tableSize*2;
		currentSize = 0;
		
		hashNode<V>** oldBuckets = buckets;
		buckets = new hashNode<V>*[tableSize];

		for(int i=0;i<tableSize;i++)
			buckets[i] = NULL;
		
		for(int i=0;i<oldTableSize;i++){
			hashNode<V>*temp = oldBuckets[i];
			while(temp!=NULL){
				insert(temp->key,temp->data);
				temp = temp->next;
			}
			if(oldBuckets[i]!=NULL){}
				delete oldBuckets[i];
		}
		delete [] oldBuckets;
		cout<<"Rehash Completed Successfully "<<endl;
	}

	
public:
	HashTable(){
		currentSize = 0;
		tableSize = 3;
		buckets = new hashNode<V>*[tableSize];
		
		for(int i=0;i<tableSize;i++)
			buckets[i] = NULL;
	}
	long long getIndex(char *key){
		
		long long currentPower = 1;
		long long ans = 0;	
		int L = strlen(key);
		for(int i=0;i<L;i++){
			ans = ans + key[L-1-i]*currentPower;
			currentPower = (currentPower*37)%tableSize;
			ans = ans%tableSize;
		}
	return (ans+tableSize)%tableSize;
	}
	

	void insert(char *key, V value){
		int index = getIndex(key);
			hashNode<V> * newNode = new hashNode<V>(key,value);
			hashNode<V> * head = buckets[index];
			newNode->next = head;
			buckets[index] = newNode;
			currentSize++;

		if(currentSize*1.0/tableSize > 0.7){
			rehash();
		}
		
	}
	V find(char *key){
		int index = getIndex(key);
		
		hashNode<V> *temp = buckets[index];
		while(temp!=NULL){
			if(strcmp(key,temp->key) == 0){
				break;
			 }
			temp = temp->next;
		}
		if(temp!=NULL)
			return temp->data;	
		else {
			V  nullobject;
			return nullobject;
		} 
	}
	void print(){
		for(int i=0;i<tableSize;i++){
			cout<<"Bucket "<<i<<":"; 
			if(buckets[i]!=NULL){
				hashNode<V>* temp = buckets[i];
				while(temp!=NULL){
					cout<< temp->key<<" ->";
					temp = temp->next;
				}
			}
			cout<<endl;	
		}

	}
	
	~HashTable(){
		for(int i=0;i<tableSize;i++)
		{
			if(buckets[i]!= NULL)
				delete  buckets[i];
		}
		delete [] buckets;
	}
};
#endif	
