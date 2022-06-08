vector<vector<int>> generate(int numRows) {
vector<vector<int>>ans;
for(int i=0;i<numRows;++i){
    vector<int>v;
    v.push_back(1); //First element of every row will be 1
    for(int j=1;j<=i;++j){  //iterate from the second element of the row till the last element.
        v.push_back(j == ans[i-1].size() ? ans[i-1][j-1] : ans[i-1][j-1] + ans[i-1][j]);  //if it's on the last element then THE LAST ELEMENT OF THE PREVIOUS ROW WILL be the current element.
//else this element will be the sum of it's upper and upper-left element.
    }
    ans.push_back(v);
}
return ans;
}
