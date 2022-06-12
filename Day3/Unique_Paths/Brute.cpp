#include<bits/stdc++.h>
using namespace std;

int count_paths(int i, int j, int m, int n) {
    int count = 0;  //current count of paths from parituclar [i,j]
    //base conditions
    if (i == m - 1 and j == n - 1)
        return 1;  //found one path to reach the destination.

    if (i<0 or j<0 or i >= m or j >= n)
        return 0;

    count += count_paths(i, j + 1, m, n) + count_paths(i + 1, j, m, n);  //No of paths from the current location will be
    //sumof number of thats from it's right and it's left
    return count;
}

int uniquePaths(int m, int n) {
    int i = 0, j = 0;
    return count_paths(i, j, m, n);
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n);
}
