//Used a queue data structre.

void setZeroes(vector<vector<int>>& matrix) {
int m = matrix.size();
int n = matrix[0].size();
queue<int>pos_row;
queue<int>pos_col;
for(int i=0;i<m;++i){
    for(int j=0;j<n;++j){
        if(matrix[i][j] == 0){
            pos_row.push(i);
            break;
        }
    }
}
for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
        if(matrix[j][i] == 0){
            pos_col.push(i);
            break;
        }
    }
}

for(int i=0;i<m;++i){
    if(pos_row.empty())
        break;
    if(i == pos_row.front())
    {
        for(int col = 0;col<n;++col)
            matrix[i][col] = 0;
        pos_row.pop();
    }
}

for(int i=0;i<n;++i){
   if(pos_col.empty())
        break;
    if(i == pos_col.front())
    {
        for(int row = 0;row<m;++row)
            matrix[row][i] = 0;
        pos_col.pop();
    } 
}
}
