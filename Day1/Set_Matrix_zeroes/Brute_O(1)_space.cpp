void setZeroes(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    bool flag_upper_r = false;  //Check if -1 is due to 0 in the row or not
    for (int r = 0; r < m; ++r) {
        bool flag_cur_r = false; //Chech if 0 exists in the row
        for (int c = 0; c < n; ++c) {
            if (mat[r][c] == 0) {
                int row = r - 1;
                while (row >= 0)
                    mat[row--][c] = 0; //first replace all the rows above it with 0

                if (!flag_cur_r) {
                    int col = 0;
                    while (col < c) {
                        if (mat[r][col] != 0)
                            mat[r][col] = -1;  //replace all the columns leaving 0 with -1
                        col++;
                    }
                }
                flag_cur_r = true;
            } else {
                if (flag_cur_r)
                    mat[r][c] = -1;

                if (r == 0)
                    continue;
                else {
                    if (mat[r - 1][c] == -1) {
                        if (flag_upper_r) //While iterating in the next row if the value in the upper row and
                            //is -1 then check whether it is -1on it's own or had been replaced.
                            mat[r - 1][c] = 0;
                    } else if (mat[r - 1][c] == 0) {
                        mat[r][c] = 0;  //if the upper value is 0 then replace current value with 0 as the
                        //upper value was zero because 0 was already present in the block.
                    }
                }
            }
        }
        flag_upper_r = flag_cur_r;
    }
    for (int c = 0; c < n; ++c) {
        if (flag_upper_r == false)
            break;
        if (mat[m - 1][c] == -1)
            mat[m - 1][c] = 0;
    }
}
