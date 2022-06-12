int Solution::solve(vector<int> &A, int B) {
   int n = A.size();
   int ans = 0;
   unordered_map<int, int>mp;
   int prefix_xor = 0;
   for (int i = 0; i < n; ++i) {
      prefix_xor ^= A[i];
      if (prefix_xor == B)
         ans++;

      if (mp.find(prefix_xor ^ B) != mp.end())
         ans += mp[prefix_xor ^ B];

      mp[prefix_xor]++;
   }
   return ans;
}
