pair<int, int> missingAndRepeating(vector<int> &a, int n)
{
	long long sm1 = 0ll, sm2 = ((long long)n * (n + 1)) / 2; //sum of n natural numbers is n*(n+1)/2
	long long sm_squ1 = 0ll, sm_squ2 = ((long long)(n) * (n + 1) * (2 * n + 1)) / 6;  //sum of squares of n
	//natural numbers is n*(n+1)*(2n+1)/6;
	for (int i = 0; i < n; ++i)
	{
		sm1 += a[i];
		sm_squ1 += a[i] * a[i];
	}
	int diff = sm2 - sm1; //missing - repeating
	int sum = (sm_squ2 - sm_squ1) / diff; //missing + repeating = (missing^2 - repeating^2)/(missing - repeating)
	pair<int, int>ans;
	ans.first = (sum + diff) / 2;
	ans.second = (sum - diff) / 2;
	return ans;
}
