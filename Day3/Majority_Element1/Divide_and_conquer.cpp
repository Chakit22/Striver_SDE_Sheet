/*Intuition :
If some how i know the majority element in the left half as well as right half then we can
definitely find the majorty element in the whole array.
For ex: Let's assume the majority element always exists in the array, so it's minimum cnt will be
(n/2 + 1).
Let's say in the left half the majority element is e1 and in the right half the majority element is e2
if both are equal then definitely this will be the majority element as:
left half size l1 , right half size l2
if the majority element e1 occurs greater >l1/2 times on left and >l2/2 times on right and both majority
elements are equal it means that element occurs >(l1+l2)/2 times which is >n/2 times
hence for sure it is majority element.  (Dry run on different test cases for better understanding).

if both are not equal then it means one element occurs >l1/2 times on left and the other element
occurs >l2/2 times on the right then either one of them will be majority element as:
the other elements can occur a max of n - ceil(((l1+l2) == n)/2) times which can never be a majority element.
*/

int cnt(int ele, int a[], int l, int h) {
    int cnt = 0;
    for (int i = l; i <= h; ++i)
        cnt += (a[i] == ele ? 1 : 0);

    return cnt;
}

int find_majority(int a[], int l, int h) {
    if (l == h) //there is only one element in the array then definitely this is the majority element
        return a[l];

    int mid = l + (h - l) / 2;
    int left_maj = find_majority(a, l, mid);
    int right_maj = find_majority(a, mid + 1, h);

    if (left_maj == right_maj)
        return left_maj;

    int cnt_left_maj = cnt(left_maj, a, l, h);
    int cnt_right_maj = cnt(right_maj, a, l, h);

    //As we know that one of the above two element can be a majority element then return the majority element
    ///as the one which has higher count

    return (cnt_left_maj > cnt_right_maj ? left_maj : right_maj); //If both of them are equal then there doesn't
    //exists a majority element in the current a[l,h] but it might exist in the whole array.
}

int majorityElement(int a[], int n)
{
    int maj = find_majority(a, 0, n - 1);
    return (cnt(maj, a, 0, n - 1) > n / 2 ? maj : -1);
}

//TC - O(NlogN)
//SC - O(1)
