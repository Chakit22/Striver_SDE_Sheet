bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int l = 0, h = n * m - 1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        int r = mid / n, c = mid % n; //mid = n*r + c
        if (matrix[r][c] == target)
            return true;
        else if (target > matrix[r][c])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return false;
}

//TC - O(LOG(M*N))
//SC - O(1)
