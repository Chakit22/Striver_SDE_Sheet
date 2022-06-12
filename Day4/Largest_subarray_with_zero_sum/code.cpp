int maxLen(vector<int>&A, int n)
{
    int max_len = 0;
    int prefix[n];
    prefix[0] = A[0];
    for (int i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + A[i];
    unordered_map<int, int>mp;
    for (int i = 0; i < n; ++i) {
        if (prefix[i] == 0)
            max_len = max(max_len, i + 1);
        else {
            if (mp.find(prefix[i]) != mp.end())
                max_len = max(max_len, i - mp[prefix[i]]);
            else
                mp[prefix[i]] = i;
        }
    }
    return max_len;
}
