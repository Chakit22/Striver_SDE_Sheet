bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int r = m - 1, c = 0;  //As the the whole matrix is sorted starting from each row its first column
    //so if we start at bottom left corner or top right corner we have a perfect choice to make.
    //in the sense if the target is equal to this element return true but if it's greater move to right
    //as the all the element to the right are greater than this element else if the element is lesser than
    //this move top because it maybe a possiblity that the element is present in the previous rows as for sure
    //it won't be present in the current row as the all the elements in this row are greater than the target.
    while (r >= 0 and c < n) {
        if (matrix[r][c] == target)
            return true;
        else if (target > matrix[r][c])
            c++;
        else
            r--;
    }
    return false;
}

//TC - O(M+N)
//SC - O(1)
