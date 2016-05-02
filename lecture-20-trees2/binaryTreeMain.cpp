#include<iostream>
#include "binaryTreeNode.h"
#include<queue>
#include<cmath>
using namespace std;

class hdpair{
public:
	int diameter;
	int height;
};

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

class bhpair{
public:
	bool isBalanced;
	int height;

	bhpair(){}

	bhpair(int h,bool b){
		isBalanced = b;
		height = h;
	}
};

bhpair isBalancedTree(BinaryTreeNode * root){
	if(root==NULL){
		bhpair ans;
		ans.height = 0;	
		ans.isBalanced = true;
		return ans;
	}
	bhpair left = isBalancedTree(root->left);
	bhpair right = isBalancedTree(root->right);

	if(abs(left.height - right.height <=1)&&left.isBalanced && right.isBalanced){
		return bhpair(max(left.height,right.height)+1,true);
	}
	else{
		return bhpair(max(left.height,right.height)+1,false);
	}
		

}


int main(){
BinaryTreeNode*root = NULL;
root = takeInputLevelOrder();
/*
printPreorder(root); cout<<"Preorder "<<endl;
printInorder(root);	cout<<"Inorder "<<endl;
printPostorder(root);	cout<<" PostOrder "<<endl;
printLevelOrder2(root);	cout<< "Level Order "<<endl;

cout<<"Number of nodes is :"<<countNodes(root)<<endl;
cout<<"Diameter of Tree is :"<<diameter(root)<<endl;

cout<<"Faster Method : Diameter "<<diameter2(root).diameter<<endl;

mirror(root); */
printLevelOrder2(root);

bhpair output = isBalancedTree(root);

if(output.isBalanced==true){
	cout<<"Balanced hai !"<<endl;
}
else{
	cout<<"Balanced nahin hai !"<<endl;
}

return 0;
}
