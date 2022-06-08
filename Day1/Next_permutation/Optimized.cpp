void nextPermutation(vector<int>& nums) {
    //No need to find nearest smaller element to each element because we just need to find an index where the element
    //is just smaller than it's next as that will be the element nearest and having the smallest place value

    //No need to find the nearest element to each index as we need to find the first element which is
    //smaller because that will have the least place value.

    int nsr = nums.size() - 2;
    while (nsr >= 0 and nums[nsr] >= nums[nsr + 1])
        nsr--;

    //this is the first element which is smaller
    if (nsr == -1)
    {
        reverse(nums.begin(), nums.end()); //if i is -1 then no smaller element is found which means te array is sorted in desecending order so just reverse the array as that will be the next greater permutation.
        return;
    }

    reverse(nums.begin() + nsr + 1, nums.end()); //reverse the array from the next element till the end
    int ub = upper_bound(nums.begin() + nsr + 1, nums.end(), nums[nsr]) - (nums.begin()); //after that as the right part of the array will be sorted
    //find the element just greater than this nearest smaller element using upper bound as just greater element will be in the just next permutation.
    swap(nums[nsr], nums[ub]); //swap this nearest smaller element with that upper bound element
}
