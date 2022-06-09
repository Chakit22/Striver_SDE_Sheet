#include<bits/stdc++.h>
using namespace std;
void mergeSort(int a1[], int a2[], int n, int m) {
	int i = 0, j = 0;
	while (i < n and j < m) {
		if (a1[i] <= a2[j])
			i++;
		else {
			//if a1[i] > a2[j] then insert a2[j] at a1[i]
			//the lower code performs the insertion operation similar to insertion sort
			//When tmp stores a2[j] then after the insertion the element present here will be the max element
			//of the array a1 and as there is a smaller element present at a2[j] then that max element will never
			//appear in the array a1 for sure.
			long long tmp = a2[j];
			a2[j] = a1[n - 1];
			for (int k = n - 2; k >= i; k--)
				a1[k + 1] = a1[k];
			a1[i++] = tmp;
			j++;
		}
	}
	sort(a1, a1 + n);
	sort(a2, a2 + m);
}

int main() {
	int n, m;
	cin >> n >> m;
	int a1[n], a2[m];
	for (int i = 0; i < n; ++i)
		cin >> a1[i];
	for (int i = 0; i < m; ++i)
		cin >> a2[i];

	mergeSort(a1, a2, n, m);
	for (int i = 0; i < n; ++i)
		cout << a1[i] << "  ";
	cout << "\n";
	for (int i = 0; i < m; ++i)
		cout << a2[i] << "  ";
}
