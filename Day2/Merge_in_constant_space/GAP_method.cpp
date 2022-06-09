#include<bits/stdc++.h>
using namespace std;
void mergeSort(int a1[], int a2[], int n, int m) {
	int gap = ceil((n + m) / 2.0);
	while (gap > 0) {
		int itr = n + m - gap;
		int i = 0, j = (i + gap) % n;
		bool trans1 = false, trans2 = false; //trans1 says whether pointer i has transited to second array
		//or not.trans2 says whether the pointer j has transited to the second array or not.
		if ((i + gap) >= n)
			trans2 = true;
		for (; itr > 0  ; i++, j++, itr--) {
			if (i == n and !trans1) { //if i is n and trans1 is false it means i is about to
				//transit to the second array
				trans1 = true;
				i = 0, j = i + gap;
				if (a2[i] <= a2[j])
					continue;
				else
					swap(a2[i], a2[j]);
			} else if (j == n and !trans2) { //if j is n and trans2 is false it means j pointer was not already
				//present in the second array.
				trans2 = true;
				j = 0;
				if (a1[i] <= a2[j])
					continue;
				else
					swap(a1[i], a2[j]);
			} else if (!trans1 and !trans2 and j < n) { //if both trans1 and trans2 are false then none of the pointers
				//have transited to the second array
				if (a1[i] <= a1[j])
					continue;
				else
					swap(a1[i], a1[j]);
			} else if (!trans1 and trans2) { // if trans1 is false and trans2 is true it means that pointer i has
				//not transited to the second array while pointer is already in array2
				if (a1[i] <= a2[j])
					continue;
				else
					swap(a1[i], a2[j]);
			} else { //this condition is executed when trans1 and trans2 are true
				if (a2[i] <= a2[j])
					continue;
				else
					swap(a2[i], a2[j]);
			}
		}
		if (gap == 1)
			break;
		gap = ceil(gap / 2.0);
	}
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

//TC - O((N+M)LOG2(N+M))
//SC - O(1)
