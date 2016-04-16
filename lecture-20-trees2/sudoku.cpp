#include<iostream>
using namespace std;

bool canPlace(int no,int x,int y,int a[][9]){
	
	//Check the row for that no
	for(int i=0;i<9;i++){
		if( a[x][i] == no){
			return false;
		}
	}
	//Check the column for that no
	for(int j=0;j<9;j++){
		if( a[j][y] == no){
			return false;
		}
	}
	//Check the subgrid for that no
	int xstart = (x/3)*3;
	int ystart = (y/3)*3;

	for(int i=xstart;i<xstart+3;i++){
		for(int j=ystart;j<ystart+3;j++){
			if(a[i][j] == no){
				return false;
			}
		}
	}
return true;
}

bool solveMySudoku(int mat[][9],int row,int col,bool marked[][9]){
	if(row==9){
		return true;
	}
	if(col==9){
		return solveMySudoku(mat,row+1,0,marked);
	}
	if(marked[row][col]==false){
		//Fill the numbers
		for(int possible_no=1;possible_no<=9;possible_no++){
			if(canPlace(possible_no,row,col,mat))
				{ 
					mat[row][col] = possible_no; 
				
					bool aageKaAns = solveMySudoku(mat,row,col+1,marked);
					if(aageKaAns==true){
							return true;
					}
					mat[row][col] =0;
				}
		}
		return false;
	}
	else{
		return solveMySudoku(mat,row,col+1,marked);
	}

}



int main(){
bool marked[9][9] = {0};

int mat[9][9] = {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

for(int i=0;i<9;i++){
	for(int j=0;j<9;j++){
			if(mat[i][j]!=0){
				marked[i][j] = true;
			}
	}
}
bool ans = solveMySudoku(mat,0,0,marked);
if(ans==false){
	cout<<"No Solution Exists !"<<endl;

}
else{
for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

return 0;
}
