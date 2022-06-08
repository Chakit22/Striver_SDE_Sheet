void sortColors(vector<int>& nums) {
int zero = 0, one = 0, two = 0;
for(auto i:nums){
    if(i == 0)
	zero++;
    else if(i == 1)
	one++;
    else
	two++;
}

for(int i=0;i<nums.size();++i)
{
    if(i < zero)
	nums[i] = 0;
    else if(i<one+zero)
	nums[i] = 1;
    else
	nums[i] = 2;
}
}
