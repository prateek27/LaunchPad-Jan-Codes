#include<iostream>
#include "binaryTreeNode.h"
#include<queue>
#include<climits>
using namespace std;

class hdpair{
public:
	int diameter;
	int height;
};


bool isBST( BinaryTreeNode*root, int minV,int maxV){
	if(root==NULL)
		return true;

	if(root->data >=minV && root->data <=maxV){
			
	bool leftOutput = isBST(root->left,minV,root->data);
	bool rightOutput = isBST(root->right,root->data,maxV); 
		
	return leftOutput && rightOutput;
	}
	else{
	  return false;
	}
}


void printRange(BinaryTreeNode*root , int k1, int k2){
	if(root==NULL)
		return;

	if(root->data >=k1 && root->data <= k2){
		//		cout<<root->data <<" ";
		printRange(root->left,k1,k2);
		cout<<root->data<<" ";
		printRange(root->right,k1,k2);
	}
	else if(root->data > k2){
		printRange(root->left,k1,k2);
	}
	else{
		printRange(root->right,k1,k2);
	}
}


BinaryTreeNode* array2Tree(int arr[],int start,int end){
	if(start>end)
		{
			return NULL;
		}
	if(start==end){
		BinaryTreeNode* leafNode = new BinaryTreeNode(arr[start]);
		return leafNode;
	}

	int mid = (start+end)/2;
	BinaryTreeNode* root = new BinaryTreeNode(arr[mid]);
	root->left = array2Tree(arr,start,mid-1);
	root->right = array2Tree(arr,mid+1,end);
	return root;

}

BinaryTreeNode*insertBST( BinaryTreeNode*root,int data ){
	if(root == NULL){
		root = new BinaryTreeNode(data);
		return root;
	}
	
	if(data <= root->data){
		root->left = insertBST(root->left,data);
	}
	else{
		root->right = insertBST(root->right,data);
	}
	return root;
}


//This index for preorder array
int pindex = 0;
//Start and end are for inorder array
BinaryTreeNode* buildTree(int preorder[],int inorder[],int start,int end){
	if(start>end){
		return NULL;
	}

	if(start==end){
	BinaryTreeNode* leafNode = new BinaryTreeNode(preorder[pindex]);
		return leafNode;
	}
	
	
	int data = preorder[pindex];
	int k;
		for(int i=start;i<=end;i++){
			if(inorder[i] == data){
				k=i;
				break;
			}
		}
	BinaryTreeNode* newNode = new BinaryTreeNode( data );
	pindex++;
	newNode->left = buildTree(preorder,inorder,start,k-1);
	pindex++;
	newNode->right = buildTree(preorder,inorder,k+1,end);
	return newNode;
}

hdpair diameter2(BinaryTreeNode*root){
	hdpair p;

	if(root==NULL){
		p.diameter = 0;
		p.height = 0;
		return p;
	}	

	hdpair leftAns = diameter2(root->left);
	hdpair rightAns = diameter2(root->right);

	int option1 = leftAns.diameter;
	int option2 = rightAns.diameter;
	int option3 = leftAns.height + rightAns.height;

	p.height = max(leftAns.height,rightAns.height) + 1;
	p.diameter = max(option1,max(option2,option3));

	return p;
}

void mirror(BinaryTreeNode*root){
	if(root==NULL)
			return;

	mirror(root->left);
	mirror(root->right);

	BinaryTreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;

}

BinaryTreeNode*findNode(BinaryTreeNode*root,int key){
	if(root==NULL)
			return NULL;

	if(root->data == key)
			return root;

	 BinaryTreeNode* leftAns = findNode(root->left,key);
	 if(leftAns!=NULL)
	 		return leftAns;

	 return findNode(root->right,key);
}


BinaryTreeNode* takeInputLevelOrder(){
	BinaryTreeNode*root ;
	int data;
	cout<<"Enter the root data ";
	cin>>data;

	root = new BinaryTreeNode(data);
	
	queue<BinaryTreeNode* > q;
	q.push(root);

	while(!q.empty()){
		BinaryTreeNode* frontNode = q.front();
		q.pop();
		int leftData,rightData;
		cout<<"Enter left child data for Node "<<frontNode->data <<":";
		cin>>leftData;
		cout<<endl;
		if(leftData!= -1){
			frontNode->left = new BinaryTreeNode(leftData);
			q.push(frontNode->left);
		}

		cout<<"Enter right child data for Node "<<frontNode->data<<":";			cout<<endl;
		cin>>rightData;

		if(rightData!=-1){
			frontNode->right = new BinaryTreeNode(rightData);
			q.push(frontNode->right);
		}
	}
	
return root;
}

void printPreorder(BinaryTreeNode*root){
		if(root==NULL)
			return;		

		cout<<root->data<<" ";
		printPreorder(root->left);
		printPreorder(root->right);
}

void printInorder(BinaryTreeNode*root){
	if(root==NULL)
		return;

	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);

}

void printPostorder(BinaryTreeNode*root){
	if(root==NULL){
		return ;
	}
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data <<" ";
}

void printLevelOrder(BinaryTreeNode*root){
	queue<BinaryTreeNode*> q;
	q.push(root);

	while(!q.empty()){
		BinaryTreeNode* temp = q.front();
		q.pop();

		cout<<temp->data <<" ";
		if(temp->left!=NULL){
			q.push(temp->left);
		}
		if(temp->right!=NULL){
			q.push(temp->right);
		}
	}
}

int countNodes(BinaryTreeNode* root){
	if(root==NULL)
		return 0;
	return (countNodes(root->left) + 1 + countNodes(root->right));
}


void printLevelOrder2(BinaryTreeNode*root){
	queue<BinaryTreeNode*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		BinaryTreeNode* temp = q.front();
		q.pop();

		if(temp==NULL){
				cout<<endl;
				if(!q.empty()){
					q.push(NULL);
				}
		}
		else{
			cout<<temp->data <<" ";
			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right!=NULL){
				q.push(temp->right);
			}
		}
	}
}

int height(BinaryTreeNode* root){
	if(root==NULL)
			return 0;

	return max(height(root->left),height(root->right)) + 1;
}

int diameter(BinaryTreeNode* root){
	if(root==NULL)
			return 0;
	int option1 = diameter(root->left);
	int option2 =  diameter(root->right);
	int option3 =  height(root->left) + height(root->right);

	return max(option1,max(option2,option3));
}


int main(){
/*
BinaryTreeNode*root = NULL;
root = takeInputLevelOrder();
printPreorder(root); cout<<"Preorder "<<endl;
printInorder(root);	cout<<"Inorder "<<endl;
printPostorder(root);	cout<<" PostOrder "<<endl;
printLevelOrder2(root);	cout<< "Level Order "<<endl;

cout<<"Number of nodes is :"<<countNodes(root)<<endl;
cout<<"Diameter of Tree is :"<<diameter(root)<<endl;

cout<<"Faster Method : Diameter "<<diameter2(root).diameter<<endl;

mirror(root);
printLevelOrder2(root);

BinaryTreeNode*root = NULL;
int inorder[] =  {4,2,7,5,8,1,6,3};
int preorder[] = {1,2,4,5,7,8,3,6};
root = buildTree(preorder,inorder,0,7);
*/
BinaryTreeNode*root = NULL;
/*
int n;
cout<<"Enter the no of elements you want to enter ";
cin>>n;
int data;
	for(int i=0;i<n;i++){
		cin>>data;	
		root = insertBST(root,data);
	}
printLevelOrder2(root);
*/
int arr[] = {1,2,3,4,5,6,7};
root = array2Tree(arr,0,6);
printLevelOrder2(root);
printRange(root,1,4);
if( isBST(root,INT_MIN,INT_MAX)){
		cout<<"BST Hai ";
		}
else{
	cout<<"BST nahin hai !";
}
return 0;
}
