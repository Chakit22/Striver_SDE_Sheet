double power(double a, int b) {
    if (b == 1)
        return a;
    if (b == 0)
        return 1;

    double tmp = power(a, b / 2);
    tmp = tmp * tmp;
    if (b % 2)
        tmp = tmp * a;
    return tmp;
}

double myPow(double x, int n) {
    double ans;
    ans = power(x, abs(n));
    if (n < 0)
        ans = 1.0 / ans;
    return ans;
}
