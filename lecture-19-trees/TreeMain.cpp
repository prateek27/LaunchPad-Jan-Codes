#include<iostream>
#include "treenode.h"
#include<queue>
using namespace std;


TreeNode<int>* takeInputLevelByLevel(){
int data;
cout<<"Enter the root data";
cin>>data;

TreeNode<int> *root = new TreeNode<int>(data);

queue<TreeNode<int>* > q;
q.push(root);
	while(!q.empty()){
		TreeNode<int> * node = q.front();
		q.pop();

cout<<"Enter the children_count for Node with data "<<node->data<<" : ";
		int count;
		cin>>count;
		node->children_count = count;
		node->children = new TreeNode<int>*[count];
		
		for(int i=0;i<count;i++){
			int data;
			cout<<"Enter the data for "<<i<<"children of node "<<node->data<<" : ";
			cin>>data;
			node->children[i] = new TreeNode<int>(data);
			q.push(node->children[i]);	
		}
	}
return root;
}

TreeNode<int>* takeInput(){
	
	int  data;
	cout<<"Enter the node data : ";
	cin>>data;	

	TreeNode<int> *node = new TreeNode<int>(data);
	
	int count;
        cout<<"Enter the child count for node "<<data<<" : " ;
	cin>>count;

	node->children_count = count;
	node->children = new TreeNode<int>*[count];

	for(int i=0;i < count;i++){
		node->children[i] = takeInput();
	}

return node;
}

int height(TreeNode<int> * root){
 if(root==NULL){
	return 0;
 }
 
 int maxHeightSoFar = 0;
 
 for(int i=0;i<root->children_count; i++){

	int child_height = height(root->children[i]);
	if(child_height > maxHeightSoFar){
		maxHeightSoFar = child_height;
	} 
  }
return maxHeightSoFar + 1;
}

int maxNodeData(TreeNode<int>* root){
	if(root==NULL){
		return -1;
	}
	int maxData = root->data;
	for(int i=0;i<root->children_count;i++){
		int data  = maxNodeData(root->children[i]);
		if(data>maxData){
			maxData = data;
		}
	}
return maxData;
}

int sumOfNodes(TreeNode<int>* root){
	if(root==NULL){
		return 0;
	}

	int currentSum = root->data;
	for(int i=0;i<root->children_count;i++){
		currentSum = currentSum + sumOfNodes(root->children[i]);
	}
return currentSum;
}


void print(TreeNode<int>*root){
	
	cout<<root->data<<" -> ";
	for(int i=0; i <root->children_count ; i++){
		cout<< root->children[i]->data <<",";
	}	
	
	cout<<endl;
	
	for(int i=0;i <root->children_count ; i++){
		print(root->children[i]);
	}
return;
}

void printK(TreeNode<int>*root,int k){
	 if(root==NULL)
		return;

	 if(k==0){
		cout<<root->data;
     		return; 
	 }
	for(int i=0;i<root->children_count;i++){
		printK(root->children[i], k-1);
	}	
}

int main(){
TreeNode<int> *root = NULL;
root = takeInputLevelByLevel();
print(root);
cout<<"Height of Tree is "<<height(root)<<endl;
cout<<"Sum of all nodes is "<<sumOfNodes(root)<<endl;
cout<<"Max node data is "<<maxNodeData(root)<<endl;
cout<<"Elements at level k is ";
printK(root,2);  

//delete root;
return 0;
}
