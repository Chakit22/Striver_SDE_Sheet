#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> find_pair_sums(int a[], int n, int sm) {
	vector<pair<int, int>>ans;
	unordered_set<int>st;
	for (int i = 0; i < n; ++i) {
		if (st.find(sm - a[i]) != st.end() and st.find(a[i]) == st.end())
			//st.find(a[i]) == st.end() must be written because a[i] must not be present in the array
			//because if a[i] was present in the array then a pair would have already been inserted into
			//ans.
			ans.push_back({min(a[i], sm - a[i]), max(a[i], sm - a[i])});

		st.insert(a[i]);
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main() {
	int n, sm;
	cin >> n >> sm;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<pair<int, int>>ans = find_pair_sums(a, n, sm);
	for (auto i : ans)
		cout << i.first << "  " << i.second << "\n";

}
