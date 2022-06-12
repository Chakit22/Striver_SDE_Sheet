#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> find_pair_sums(int a[], int n, int sm) {
	sort(a, a + n);
	vector<pair<int, int>>ans;
	int l = 0, h = n - 1;
	while (l < h) {
		if (a[l] + a[h] == sm) {
			ans.push_back({a[l], a[h]});
			while (l < h and a[l] == a[l + 1])l++;
			l++;
			while (h > l and a[h] == a[h - 1])h--;
			h--;
		} else if (a[l] + a[h] < sm) {
			while (l < h and a[l] == a[l + 1])l++;
			l++;
		} else {
			while (h > l and a[h] == a[h - 1])h--;
			h--;
		}
	}
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
