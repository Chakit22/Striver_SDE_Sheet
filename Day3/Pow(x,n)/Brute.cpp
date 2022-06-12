double power(double a, int b) {
    double ans = 1.0;
    while (b--)
        ans *= a;
    return ans;
}

double myPow(double x, int n) {
    double ans;
    ans = power(x, abs(n));
    if (n < 0)
        ans = 1.0 / ans;
    return ans;
}
