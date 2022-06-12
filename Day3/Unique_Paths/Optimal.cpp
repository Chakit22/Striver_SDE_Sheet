int uniquePaths(int m, int n) {
    //As the robot can move down or right at any moment then to reach the destination it will need n-1 rights and m-1 downs
    //as this displacement in any order would reach it's destination.
    int a = max(m, n), b = 1;
    long ans = 1;
    while (a <= m + n - 2) {
        ans = (ans * a) / b;
        //This will never give out a remainder because
        //for ex if we are caluating 198!/99! * 99! so if we start b from 1 then going successively to the next numbers ans*a will always
        //be divisible by b as we are adding one each time for the first time it is divisble by 1 next time it will be divisible by 2
        //as one is added so it will be even or odd and for three either the when multiplied by next factor it will be divisible by
        //3 or might be already divisible by 3.
        a++;
        b++;
    }
    return ans;
}

//TC - O(min(m,n)) as the no iterations will be (m+n-2 - m)==n if m is max else it will be
//(m+n-2)-(n) == m if n is max so m will be min.
//SC - O(1)
