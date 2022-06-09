void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(matrix[i][j], matrix[j][i]);  //iterate on lower traingular matrix
        }
    }
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());  //just reverse it
    }
}

//TC - O(ROW*COL)
//SC - O(1)
