/*
e1's count should not by decremented by e2 and e2's count should not be decremented by e1.
Due to which only one of the conditions gets executed in the below code.
*/

vector<int> majorityElement(vector<int>& nums) {
    int e1 = INT_MIN, e2 = INT_MIN;
    int n = nums.size();
    int c1 = 0, c2 = 0;
    for (auto i : nums) {
        if (e1 == i)  //These upgradation condition has to written first because if written after
            //c1 == 0 or c2 == 0 there may be a case when e1 and e2 both have the same value.
            c1++;
        else if (e2 == i)
            c2++;
        else if (c1 == 0) {
            e1 = i;
            c1 = 1;
        } else if (c2 == 0) {
            e2 = i;
            c2 = 1;
        } else {  //Only if i is not equal to el1 and el2 then only decrement the count of both of them.
            //as this element i will be the minority element to both of them.
            c1--;
            c2--;
        }
    }

    c1 = c2 = 0;
    for (auto i : nums) {
        c1 += (i == e1);
        c2 += (i == e2);
    }
    vector<int>ans;
    if (c1 > n / 3)
        ans.push_back(e1);
    if (c2 > n / 3)
        ans.push_back(e2);
    return ans;
}
