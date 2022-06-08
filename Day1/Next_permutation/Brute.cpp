void nextPermutation(vector<int>& nums) {
int n=nums.size();
pair<pair<int,int>,int>p = {{INT_MAX,-1},-1}; //{{ele,idx},nxt_sl_idx}
for(int i=n-1;i>=0;i--){
    int j;
    for(j=i-1;j>=0;j--){
        if(nums[j] < nums[i]){
          break;  
        }
    }
    if(j > p.second){
        p = {{nums[i],i},j};
    }
}
if(p.second != -1)
    swap(nums[p.first.second],nums[p.second]);
sort(nums.begin() + p.second + 1,nums.end());
}
