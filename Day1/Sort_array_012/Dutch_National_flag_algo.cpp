void sortColors(vector<int>& nums) {
    //Dutch National Flag Algorithm
    int low, mid, high, n = nums.size();
    low = mid = 0;
    high = n - 1;
    while (mid <= high) {
        //low will basically point to the first one from the left if there are ones in the array after some zeroes
        //so as mid keeps on moving when 1 is encountered so the moment mid encounters 0 it will swap with low which points to the
        //first one after zeroes which statisfies that condition that nums[0,low-1] = 0.When 2 is encountered it is swapped with high as
        //it should be placed at last and then, only move the high pointer not the mid pointer, because when swapped the element could be 0 or 1.
	//nums[low,mid] will try to maintain ones and nums[high+1,n-1] = 2, so the moment mid crosses high it means we have to stop as nums[0,low-1] = 0,nums[low,mid] = 1,nums[mid+1,n-1] = 2,here 	
	//high will become mid when mid crosses high so it has been divided into parts of 0,1,2.
        switch (nums[mid]) {
        case 0: swap(nums[mid++], nums[low++]);
            	break;
        case 1: mid++;
            	break;
        case 2: swap(nums[mid], nums[high--]);
            	break;
        }
    }
}
