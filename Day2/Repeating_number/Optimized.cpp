//Below is the concept of remove loop in a linked list.
//As mentioned in Brute.cpp here the same concept is used with the modification that we
//are not modifying the array a.The concept used is if there is a repeating number then there will
//exist a cycle just like in the case of Cycle in Linked list.

//This only works when the integers in the array of size (n+1) is from 1 to n.
//s thaat index always exists i the array.
//for a duplicated number there will two links inward both of them pointing to it.

int findDuplicate(vector<int>& a) {
    int n = a.size();
    int slow = a[0]; //same as slow = head;
    int fast = a[0]; //both slow and fast are pointing to head;
    while (1) { //as there always exists a repeating number as mentioned in the question run till infinite
        //as the condition slow == fast will become true at some point of time.
        slow = a[slow];      //same as slow = slow->next
        fast = a[a[fast]];  //same as fast = fast->next->next;
        if (slow == fast)
            break;
    }
    slow = a[0];  //point slow to head
    while (slow != fast)
    {
        slow = a[slow];  //same as slow = slow->next.
        fast = a[fast];  //same as fast = fast->next.
    }
    return slow;
}
