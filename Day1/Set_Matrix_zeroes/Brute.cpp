void setZeroes(vector<vector<int>>& matrix) {
int m = matrix.size();
int n = matrix[0].size();
vector<vector<int>>tmp(m,vector<int>(n));
for(int i=0;i<m;++i){
    for(int j=0;j<n;++j)
        tmp[i][j] = matrix[i][j];
}
//fill rows with zeroes
for(int i=0;i<m;++i){
    for(int j=0;j<n;++j){
        if(matrix[i][j] == 0){
            for(int col=0;col<n;++col)
                tmp[i][col] = 0;
            break;
        }
    }
}
//fill columns as 0
for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
        if(matrix[j][i] == 0){
            for(int row=0;row<m;++row)
                tmp[row][i] = 0;
            break;
        }
    }
}

//copy elements
for(int i=0;i<m;++i){
    for(int j=0;j<n;++j)
        matrix[i][j] = tmp[i][j];
}
}
