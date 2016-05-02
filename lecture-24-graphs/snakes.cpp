#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{

int V;

list<int> *arr;

public:
Graph(int vertices){
	V = vertices;
	arr = new list<int>[V];
	//arr = new vector<vector<int> >(V);
	}
void addEdge(int u,int v){
	arr[u].push_back(v);
	//arr[v].push_back(u);
}

void BFSPrint(int s){	
	bool *visited = new bool[V];
	
	for(int i=0;i<V;i++){
		visited[i] = false;
	}
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while(!q.empty()){
		int front = q.front();
		cout<<front<<" ";
		q.pop();

		list<int>::iterator it;
		for(it = arr[front].begin();it!=arr[front].end();it++)
		{
			if(!visited[*it])
				{ q.push(*it);
				  visited[*it] = true;	
				}
		}
			
	}	
}
int shortestPath(int s,int d){
	
	int *dist = new int[V];
	for(int i=0;i<V;i++){
		dist[i] = -1;
	}
	int *parent = new int[V];
	for(int i=0;i<V;i++)
		{ parent[i] = -1 ; }

	parent[1] = 0;
	
	queue<int> q;
	q.push(s);
	dist[s] = 0;

	while(!q.empty()){
		int f = q.front();
		q.pop();
		
		list<int>::iterator it;
		for(it = arr[f].begin();it!=arr[f].end();it++){
			if(dist[*it]==-1){
				
				dist[*it] = dist[f] + 1;
				parent[*it] = f;
				q.push(*it);	
			}
		}
	}
	//Path Print 
	int current_node = d;
	while(current_node!=0){
		cout<<current_node<<" <-- ";
		current_node = parent[current_node];
	}

return dist[d];
}


	~Graph(){
		delete [] arr;
	}
};



int main(){

int board[50] = {0};
board[2]= 13;
board[5] = 2;
board[9] = 18;
board[18] = 11;
board[17] = -13;
board[20] = -14;
board[24] = -8;
board[25] = 10;
board[32] = -2;
board[34] = -22;

Graph g(50);
for(int i=1;i<36;i++){
	for(int jump = 1;jump<=6;jump++){
		int next_node = i + jump + board[i+jump];
		g.addEdge(i,next_node);
	}
}

int ans = g.shortestPath(1,36);
cout<<endl;
cout<<"Shortest Path is "<<ans;
return 0;
}
