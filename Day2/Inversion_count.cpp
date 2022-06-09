#include <bits/stdc++.h>
long long merge(long long *arr, int l, int mid, int h) {
	long long inv = 0;
	long long tmp[h - l + 1];
	int i = l, j = mid + 1; //pointing to the first element of both the arrays,left half and right half
	int k = 0;

	while (i <= mid and j <= h) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
		} else {
			inv += mid - i + 1; //as the array is sorted so the inversion count
			//will occur for ith index element as well as elements after the ith
			//index for that particular j
			tmp[k++] = arr[j++];
		}
	}

	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= h)
		tmp[k++] = arr[j++];

	for (int itr = l; itr <= h; ++itr)
		arr[itr] = tmp[itr - l];  //As the tmp function will have zero based indexing it will start from 0
	// and values in the array will be inputted starting from index l.
	return inv;
}

long long mergeSort(long long *arr, int l, int h) { //This function will sort the array from l to h
	long long inv = 0; //current inversion count of the array is 0.
	if (l < h) {
		int mid = l + (h - l) / 2;
		inv += mergeSort(arr, l, mid); //first sort the array from l to mid.
		inv += mergeSort(arr, mid + 1, h); //sort the array from mid+1 to h
		inv += merge(arr, l, mid, h); //merge both the sorted parts. After merging, the array will be sorted from l to h
	}//The total inversion count is the sum of the inversion counts from the left that is l to mid and from the right .i.e. mid+1 to h and inversion counts occuring when both are being merged.
	return inv;
}

long long getInversions(long long *arr, int n) {
	int l = 0, h = n - 1;
	return mergeSort(arr, l, h);
}

//Don't use Global variables in Interviews.
