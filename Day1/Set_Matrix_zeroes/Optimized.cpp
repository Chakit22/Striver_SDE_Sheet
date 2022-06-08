void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool col_0 = false;  //if 0 is present on col0 or not, this variable has to be taken because if we are on the
    //first row and matrix[0][0] is set to zero then if it is set to zero due to the any element 0 on 0th column
    //and not due to 0th row so if the variable is not taken then we will set the 0th row also as 0 which should
    //not be set to 0 because that 0 is set due to an element 0 appearing in the 0th column.
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) //if any element on the 0th column is zero then set that col_0 as true;
            col_0 = true;
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) //if any element is 0 set that row's first column as zero and set it's column in the
                //first row to be 0 denoting that this whole column and this whole row must be set to zero.
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    //Start iterating from the last row as if iterated from the first row it will already set those elements
    //as zero if 0 is set on it's row and first column so the row's below it will fill zeroes according to it
    //which is not right.

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 or matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if (col_0 == true)
            matrix[i][0] = 0;
    }
}
