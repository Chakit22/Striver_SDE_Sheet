vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());  //A 2D vector can also be sorted by a normal sort function.
    vector<vector<int>>ans;
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= ans.back()[1])  //Chances that it may overlap.
            ans.back()[1] = max(intervals[i][1], ans.back()[1]);  //So it overlaps also we know that intervals[i][0] >= intervals[i-1][0], so if we just take the max of the ending vaues of the already merged intervals and this intervals our job is done.
        else
            ans.push_back(intervals[i]);  //Push the new INterval.
    }
    return ans;
}
