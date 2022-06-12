int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    int st = 0, e = 0, n = s.size();
    unordered_map<char, int>mp;
    while (e < n) {
        if (mp.find(s[e]) == mp.end())
            mp[s[e++]]++;
        else
        {
            max_len = max(max_len, e - st);
            while (st < e and mp[s[e]] != 0)
                mp[s[st++]]--;
            mp[s[e++]]++;
        }
    }
    max_len = max(max_len, e - st);
    return max_len;
}
