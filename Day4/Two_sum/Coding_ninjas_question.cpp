#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int sm) {
    // Write your code here.
    vector<vector<int>>ans;
    int n = arr.size();
    map<pair<int, int>, int>mp;
    map<int, int>st;
    for (int i = 0; i < n; ++i) {
        if (st.find(sm - arr[i]) != st.end()) {
            int itr = st[sm - arr[i]];
            while (itr--)
                mp[ {min(arr[i], sm - arr[i]), max(arr[i], sm - arr[i])}]++;
        }
        st[arr[i]]++;
    }
    for (auto i : mp) {
        cout << i.first.first << "   " << i.first.second << "\n";
        int itr = i.second;
        while (itr--)
            ans.push_back({i.first.first, i.first.second});
    }
    return ans;
}
