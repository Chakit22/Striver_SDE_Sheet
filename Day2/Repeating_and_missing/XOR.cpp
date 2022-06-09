int *findTwoElement(int *arr, int n) {
    // code here
    int *ans = new int[2];
    int xor_ = 0;
    for (int i = 0; i < n; ++i) {
        xor_ ^= arr[i];
        xor_ ^= (i + 1);
    }

    //As the values in the array are just from 1 to N so all the possibilites of set bit 1
    //is taken care off and let's say te xor_set bucket contains missing number
    //then as the numbers are from 1 to n with some numbers having bit set as in the array while
    //one number begin different so final xor will give out the misssing number.

    //No need to check out the other set bits are the range is limited to 1 to N and al elements occur.
    //so the bit in arr[i] will be set as in the same numbers from 1 to N as arr just contains [1,N].


    //xor_ value is XOR(ARR ELEMENTS)^(XOR(1,2,3,....n)
    //xor_ will now contian missing^repeating's value or repeating^missing's value
    int xor_set = 0, xor_unset = 0; //As repeating number and missing number won't be the same
    //xor_ will contain at most one set bit
    int bit = log2(xor_); //calculates the position of rightmost set bit
    for (int i = 0; i < n; ++i) {
        if ((arr[i] & (1 << bit))) //if bit is set add it in bucket set
            xor_set ^= arr[i];
        else
            xor_unset ^= arr[i];  //if the bit is unset add it in unset bucket

        if ((i + 1) & (1 << bit)) //if bit is set add it in bucket set
            xor_set ^= (i + 1);
        else
            xor_unset ^= (i + 1); //if the bit is unset add it in unset bucket
    }
    //As xor_Set will never be zero one bit will be set in missing or repating which gave rise to the rightmost set bit
    //of xor_ so the bits must be alternting for it to be set in xor_.
    for (int i = 0; i < n; ++i) {
        if (xor_set == arr[i])
        {
            ans[0] = xor_set;
            ans[1] = xor_unset;
            return ans;
        }
    }
    ans[0] = xor_unset;
    ans[1] = xor_set;
    return ans;
}
