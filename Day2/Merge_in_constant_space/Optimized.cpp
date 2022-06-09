void merge(long long arr1[], long long arr2[], int n, int m)
{
    //This is based on the approach of insertion sort
    int i = 0, j = 0, k = n - 1;
    while (i <= k and j < m) {
        if (arr1[i] <= arr2[j])
            i++;  //if it is less then don't do anything just move pointer u
        else {
            long long tmp = arr2[j];
            arr2[j] = arr1[k];
            arr1[k] = tmp;  //swap the elements at jth and kth position as in the case of insertion as
            //we saw that the greatest element gets removed from the array so the element at the kth
            //position will never occur in arr1.
            k--; //so move k, now the elements from n to k will definitely occur in arr1
            j++; //increment j as element at jth position will occur in arr2 as it doesn't occur
            //in arr1
            //don't move i as it may happen that arr1[i] is still greater than arr2[j]
        }
    }
    sort(arr1, arr1 + n); //sort the arrays as the order is not maintined while performing the above operations.
    sort(arr2, arr2 + m);
}

//TC - O(nlogn + mlogm)
//SC - O(1)
