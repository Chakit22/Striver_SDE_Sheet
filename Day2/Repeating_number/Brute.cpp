//This method modifies the array a
int findDuplicate(vector<int>& a) {
    for (int i = 0; 1;) {
        if (a[abs(a[i])] >= 0) {  //if a number is repeating then when im moving to the index of that number
            //it will be marked -1 only if that number is marked negative because indices are unique and
            //A number at index i will be marked negative by number i so when this i is repeated then whne it comes
            //to mark for the second time it will already be marked negative.A number at index i will only be
            //negative by i itself.
            a[abs(a[i])] *= -1;
            i = abs(a[i]);
        }
        else
            return abs(a[i]);
    }
    return -1;
}

//TC - O(N) as in the worst case atmost n-1 numbers will be marked negative and after that repeating number
//will be found so max iterations N.
//SC - O(1)
