/*Intuition :
As we knwo that there can be a maximum of one majority element in the array.So if the cnt of this majority element
is x and even if reduce the cnt by -1 each time it will not reduce to 0 as it's frequency is greater than all of the
other elements frequency, so the ele variable will never get updated.
*/

int majorityElement(vector<int>& nums) {
    int cnt = 0, ele = INT_MIN;
    for (int i : nums) {
        if (cnt == 0)  //if cnt == 0 it means that the no of majority elements were cancelled by the minority
            //elements in it's prefix so majority element will exist in the right half of the array.
            //So carry out the same process in the right half of the array.
            ele = i;  //Assume this to be a majority element
        if (i == ele)  //if the current element is the assumed element then increment the count else
            //decrement it showing that one minority element has decremented it's count.
            cnt++;
        else
            cnt--;
    }
    return ele;
}

//TC - O(n)
//SC - O(1)
