#include <bits/stdc++.h> 
void rotate(int n_r,int n_c,int r,int c,vector<vector<int>>&mat){
    //r represents the starting index of the first row while column indicates
    //the starting index of the first column.n_r represents the no of rows starting from 
    //r while n_c indicates the no of columns starting from c.
    
	int row,col;
	int tmp = mat[r][c];
	//moving up
	for(row = r+1,col=c;row<r+n_r;row++)
		mat[row-1][col] = mat[row][col];
	row--;
	col++;
	//moving left
	for(;col<c+n_c;col++)
		mat[row][col-1] = mat[row][col];
	row--;
	col--;
	//moving down
	for(;row>=r;row--)
		mat[row+1][col] = mat[row][col];
	row++;
	col--;
	//moving right
	for(;col>c;col--)
		mat[row][col+1] = mat[row][col];
	
	mat[r][c+1] = tmp;
}

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
	int itr = min(n,m)/2;
	for(int i=0,r=0,c=0,n_r=n,n_c=m;i<itr;++i){
		rotate(n_r,n_c,r,c,mat);
		n_r -= 2;
		n_c -= 2;
		r++;
		c++;
	}
}

//TC - O(N*M)
//SC - O(1)
