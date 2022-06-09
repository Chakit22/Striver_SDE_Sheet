int findDuplicate(vector<int>& a) {
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i - 1]) //if the number is repeating then it will be adjacent to each other in the
            //sorted order.
            return a[i];
    }
    return -1;
}
