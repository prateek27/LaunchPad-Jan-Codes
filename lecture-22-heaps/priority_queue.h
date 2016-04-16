#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include<vector>
#include<iostream>
using namespace std;


class PriorityQueue{
	vector<int>  arr;
	int index;
	int currentSize;
	
	void heapify(int i){
	  
	   int leftChild = 2*i;
	   int rightChild = 2*i + 1;
	
	  int maxV = i;
		//If left child exists to uska index  index se kum hoga
	   if(leftChild < index){
		if(arr[leftChild] > arr[maxV]){
			maxV = leftChild;
		}
	   }
	   if(rightChild < index && arr[rightChild] > arr[maxV]){
		maxV = rightChild;
     	    }	
	   
           if(maxV!=i){
		swap(arr[i], arr[maxV]);
		heapify(maxV);		
 	  	return;
	 }
	return;
	}
public:
	PriorityQueue(){
		index=1;
		currentSize=0;
		arr.push_back(-1);	
	}

	void push(int data){

		arr[index] = data;
		index++;
		currentSize++;
		
		int i = index-1;
		while(i>1 ){
			int parent = i/2;
			
			if(arr[i] > arr[parent]){
				swap(arr[i],arr[parent]);
				i = i/2;
			}
			else{
				break;
			}
		}
	}

	 int  getMax();

	 int  removeMax(){
  		
		int ans = arr[1];
		swap(arr[index-1],arr[1]);
		index--;
		currentSize--;
		heapify(1);
		return ans;
  	}
	void print(){
		for(int i=1;i<index;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

};

int PriorityQueue:: getMax(){
	return arr[1];
}

#endif
