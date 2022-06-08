int maxSubArray(vector<int>& nums) {
    int max_till_now = 0, max_final = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        max_till_now += nums[i];  //Even if you include the negative elements but sum is not coming out to be negative and then you find positive elements after that then it can be or can be not
//greater than max_final
        if (max_till_now > max_final)
            max_final = max_till_now;
        if (max_till_now < 0) //As the above condition will take care of the fact that even if there are negative elements it will updated in max_final.
            max_till_now = 0 ;
    }
    return max_final;
}
