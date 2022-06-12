bool ispresent(vector<int>&arr, int key, int l, int h) {
    if (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == key)
            return true;
        else if (arr[mid] > key)
            return ispresent(arr, key, l, mid - 1);
        else
            return ispresent(arr, key, mid + 1, h);
    } else
        return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (int i = 0; i < matrix.size(); ++i) {
        if (ispresent(matrix[i], target, 0, matrix[i].size() - 1))
            return true;
    }
    return false;
}

//TC - O(MlogN)
//SC - O(1)
