double myPow(double x, int n) {
    if (n < 0)
        x = 1 / x;
    long num = abs(n);
    double pow = 1;

    while (num) {

        if (num % 2)  //This will tell whether the rightmost bit is set or not. If it is set then multiply it with the current place value of that bit that is x^(2^place) where place>=0
            pow *= x;
        x *= x; //For the next place value the power is just double of this so just multiply x with itself.
        num /= 2;
    }
    return pow;
}

//for ex 3^ 13
/*
13 = (1101) in binary
3 ^ (13) = 3^(1101) = 3 ^ (8 + 4 + 0 + 1) = 3^8 * 3^4 * 3^0 * 3^1 = (3^(2^3)) * (3^(2^2)) * 3^0 * (3^(2^0)).
*/
