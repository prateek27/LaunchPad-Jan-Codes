#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

class BinaryTreeNode{
public:
	int data;
	BinaryTreeNode* left;
	BinaryTreeNode*right;

	BinaryTreeNode():data(0),left(NULL),right(NULL){}
	
	BinaryTreeNode(int d):data(d),left(NULL),right(NULL){}

	~BinaryTreeNode(){
		if(left!=NULL)
			delete left;
		if(right!=NULL)
			delete right;
	}

};

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

int minKey = 100;
int maxKey = -100;

void verticalPrint(BinaryTreeNode*root,int col,unordered_map<int,vector<int> > &mymap){
	if(root==NULL){
		return;
	}
	minKey = min(minKey,col);
	maxKey = max(maxKey,col);

	mymap[col].push_back(root->data);
	verticalPrint(root->left,col-1,mymap);	
	verticalPrint(root->right,col+1,mymap);

}

int main(){

BinaryTreeNode* root = NULL;
unordered_map<int,vector<int>  > mymap ;

root = takeInputLevelOrder();


verticalPrint(root,0,mymap);

for(int i=minKey;i<=maxKey;i++){
	for(int j=0;j<mymap[i].size();j++){
		cout<< mymap[i][j];
	}
	cout<<endl;		
}



return 0;
}
