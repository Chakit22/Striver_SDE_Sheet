int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    //As there can be only one majority element in the array so it will anyway occur on both halfs of the array on
    //left as well as right in the sense
    //if array size is 7 then that element appears atleast (7/2 + 1) = 4 times so even if it starts
    //from index 0 it will end at index 3 and if starts at index 1 ends at index 4 and starts at index 2 ends
    //at index 5 so the element at mid that is nums[n/2] will always be majority element.
    //So if it starts at any index i it will end at min index [i+n/2] so the max value of i can be
    //when the majority element ends at n-1 .i.e. i+n/2 = n-1, i= n/2 - 1 which occurs in the left half of the
    //array at index < mid and will end at index >= mid, so mid will be covered by the majority element.
    return nums[n / 2];
}
