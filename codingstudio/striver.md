1. [set matrix zero](https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems)
```cpp
#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
    bool fr_zero = false ;
    int M = matrix.size() , N = matrix[0].size() ;
    
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(matrix[i][j] == 0){
                if(i == 0){
                    fr_zero = true ;
                    matrix[0][j] = 0 ;
                }
                else{
                    matrix[i][0] = 0 ;
                    matrix[0][j] = 0 ;
                }
            }        
        }
    }
    for(int i = M-1 ; i >= 0 ; i--){
        for(int j = N-1 ; j >= 0 ; j--){
            if(i != 0 and (matrix[i][0] == 0 or matrix[0][j] == 0)){
                matrix[i][j] = 0 ;
            }
            else if(i == 0 and fr_zero){
                matrix[0][j] = 0 ;
            }
        }
    }
}
```

2. [pascals triangle](https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_1089580?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> res ;
    res.push_back({1});
    if(n == 1) return res ;
    
    for(int i = 1 ; i < n ; i++){
        vector<long long int> tt ;
        tt.push_back(1);
        for(int j = 1 ; j < i ; j++){
            tt.push_back(res[i-1][j-1] + res[i-1][j]) ;
        }
        tt.push_back(1);
        res.push_back(tt);
    }
    return res ;
}
```
3. [permutation](https://www.codingninjas.com/codestudio/problems/next-permutaion_893046?topList=striver-sde-sheet-problems&leftPanelTab=1)
```cpp
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &arr, int n)
{
    /*
        2 3 5 4 1    2 4 1 3 5
           
    */
    int a_peak = 0 ;
    
    for(int i = n-2 ; i >= 0 ; i--){
        if(arr[i] < arr[i+1]){
            a_peak = i ;
            break ;
        }
    }
    for(int i = n-1 ; i > a_peak ; i--){
        if(arr[i] > arr[a_peak]){
            swap(arr[a_peak] , arr[i]);
            a_peak++ ;
            break ;
        }
    }
    reverse(arr.begin()+a_peak , arr.end());
    return arr ;
}
```
4. [maximum subarray sum](https://www.codingninjas.com/codestudio/problems/maximum-subarray-sum_630526?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long cursum = arr[0] ;
    long long maxsum = 0 ;
    for(int i = 1 ; i < n ; i++){
        cursum = max(cursum + arr[i] , (long long )arr[i]);
        maxsum = max(cursum , maxsum);
    }
    return maxsum ;
}
```

5. [sort012](https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    int ptr1 = 0 , ptr2 = 0 , ptr3 = n-1 ;
    
    while(ptr2 <= ptr3){
        if(arr[ptr2] == 0){
            swap(arr[ptr1] , arr[ptr2]) ;
            ptr1++ ; ptr2++ ;
        }
        else if(arr[ptr2] == 2){
            swap(arr[ptr2] , arr[ptr3]);
            ptr3-- ;
        }
        else{
            ptr2++ ;
        }
    }
    
}
```

6. [merge sorted arrrays](https://www.codingninjas.com/codestudio/problems/ninja-and-sorted-arrays_1214628?topList=striver-sde-sheet-problems&leftPanelTab=1)
```cpp
#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    vector<int> res ;
    int ptr1 = 0 , ptr2 = 0 ;
    while(ptr1 < m  and ptr2 < n){
        if(arr1[ptr1] < arr2[ptr2]){
            res.push_back(arr1[ptr1++]);
        }
        else{
            res.push_back(arr2[ptr2++]);
        }
    }
    while(ptr1 < m){
        res.push_back(arr1[ptr1++]);
    }
    while(ptr2 < n){
        res.push_back(arr2[ptr2++]);
    }
    return res ;
}
```

7. [find duplicate](https://www.codingninjas.com/codestudio/problems/find-duplicate-in-array_1112602?topList=striver-sde-sheet-problems&leftPanelTab=1)
```cpp
#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
     for(int i = 0 ; i < n ; i++){
         int ele = abs(arr[i]) ;
         int idx = ele-1 ;
         if(arr[idx] < 0) return ele ;
         arr[idx] *= -1 ;
     }
    return n ;
}
```
8. [missing and repeating number]()
```cpp
#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int xor1 = 0 ;
    for(int i = 1 ; i <= n ; i++){
        xor1 = xor1 ^ arr[i-1] ;
        xor1 = xor1 ^ i ;
    }
    int last_set_bit = xor1 & (~(xor1-1)) ;
    //1 1 0 0  1 0 1 1 == 0 1 0 0
    
    int x = 0 , y = 0 ;    
    for(int ele : arr){
        if((ele & last_set_bit) >= 1){
            x = x^ele ;
        }
        else{
            y = y^ele ;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if((i&last_set_bit) >= 1){
            x = x ^ i ;
        }
        else{
            y = y ^ i ;
        }
    }
    // assume x be the repeating number
    for(int ele : arr){
        if(x == ele){
            return {y , x};
        }
    }
    return {x , y} ;
}

```

9. [search in a 22d matrix](https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_980531?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
#include <vector>

bool binsearch(vector<int> &arr , int left , int right , int target){
    int mid ; 
    while(left <= right){
        mid = left  + (right-left)/2 ;
        if(arr[mid] == target) return true ;
        else if(arr[mid] < target) left = mid+1 ;
        else right = mid-1 ;
    }
    return false ;
}
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    for(int i = 0 ; i < m ; i++){
        if(mat[i][0] > target or mat[i][n-1] < target) continue ;
        if(binsearch(mat[i], 0 , n-1 , target)) return true ;
    }
    return false ;
}
```

10. [modular exponentiation](https://www.codingninjas.com/codestudio/problems/modular-exponentiation_1082146?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
    if(n == 0) return 1 ;
    
    long long res = x%m ; n-- ;
    while(n--){
        res = (res*x)%m ;
    }
    return res ;
}

#include <bits/stdc++.h> 

int mod ;
long helper(int x , int n){
    if(n == 0) return 1 ;
    if(n == 1) return x%mod ;
    long half = helper(x , n/2) ;
    long full = (half*half)%mod ;
    if((n&1) == 1){
        return (full*x)%mod ;
    }
    return full ;
}
int modularExponentiation(int x, int n, int m) {
    mod = m ;
    return helper(x , n) ;
}
```

11. [majority element](https://www.codingninjas.com/codestudio/problems/majority-element_842495?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    int cur_ele = arr[0] , votes = 1 ;
    
    for(int i = 1 ; i < n ; i++){
        if(arr[i] == cur_ele) votes++ ;
        else votes-- ;
        if(votes < 0){
            votes = 1 ; cur_ele = arr[i] ;
        }
    }
    int count = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(cur_ele == arr[i]) count++ ;
    }
    if(count > n/2) return cur_ele ;
    return -1 ;
}
```

12. [reverse pairs](https://www.codingninjas.com/codestudio/problems/reverse-pairs_1112652?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
int counter = 0 ;
void merge(vector<int> &arr , int left , int mid , int right){
    vector<int> newone ;
    int ptr1 = left , ptr2 = mid+1 ;
    while(ptr1 <= mid and ptr2 <= right){
        if(arr[ptr1] > (long )2*arr[ptr2]){
            counter += (mid-ptr1+1) ;
            ptr2++ ;
        }
        else{
            ptr1++ ;
        }
    }
    
    ptr1 = left ; ptr2 = mid+1 ;
    while(ptr1 <= mid and ptr2 <= right){
        if(arr[ptr1] <= arr[ptr2]){
            newone.push_back(arr[ptr1++]);
        }
        else{
            newone.push_back(arr[ptr2++]);
        }
    }
    while(ptr1 <= mid) newone.push_back(arr[ptr1++]) ;
    while(ptr2 <= right) newone.push_back(arr[ptr2++]) ;
    
    for(int i = 0 ; i < newone.size() ; i++){
        arr[i+left] = newone[i] ;
    }
}
void mergeSort(vector<int> &arr , int left , int right){
    if(left >= right) return  ;
    int mid = left + (right - left)/2 ;
    mergeSort(arr , left , mid);
    mergeSort(arr , mid+1 , right);
    merge(arr , left , mid , right);
}
int reversePairs(vector<int> &arr, int n){
    counter = 0 ;
    mergeSort(arr , 0 , n-1);
    return counter ;
}
```

13. [pair sum](https://www.codingninjas.com/codestudio/problems/pair-sum_697295?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    unordered_map<int,int> memo ;
    vector<vector<int>> res ;
    sort(arr.begin() , arr.end());
    for(int ele : arr){
        int req = s-ele ;
        if(memo.find(req) != memo.end()){
            int counter = memo[req] ;
            while(counter--){
                res.push_back({req , ele});
            }
        }
        memo[ele]++ ;
    }
    sort(res.begin() , res.end());
    return res ;
}
```

14. [longest subarray zero sum](https://www.codingninjas.com/codestudio/problems/longest-subset-zero-sum_920321?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

    int maxlen = 0 ;
    unordered_map<int,int> memo ;
    int cursum = 0 ;
    for(int i = 0 ; i < arr.size() ; i++){
        cursum += arr[i] ;
        
        if(cursum == 0){
            maxlen = i+1 ;
        }
        else if(memo.find(cursum) != memo.end()){
            maxlen = max(maxlen , i-memo[cursum]);
        }
        else{
            memo[cursum] = i ;
        }
    }
    return maxlen ;
}
```

15. [subarray with given xor](https://www.codingninjas.com/codestudio/problems/count-subarrays-with-given-xor_1115652?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int count = 0 , cur_xor = 0 ;
    unordered_map<int,int> memo ;
    memo[0] = 1 ;
    for(int i = 0 ; i < arr.size() ; i++){
        cur_xor = cur_xor ^ arr[i] ;
        if(memo.find(cur_xor ^ x) != memo.end()){
            count += memo[cur_xor ^ x] ;
        }
        memo[cur_xor]++ ;
    }
    return count ;
}
```

16. [longest substr without repeating char](https://www.codingninjas.com/codestudio/problems/longest-unique-substring_630418?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
int uniqueSubstrings(string &input)
{
    int left = 0 , right = 0 , maxlen = 1 ;
    vector<int> charmap(26 , 0);
    
    while(right < input.size()){
        while(charmap[ input[right] - 'a'] == 1){
            charmap[ input[left] - 'a']-- ;
            left++ ;
        }
        charmap[ input[right] - 'a']++ ;
        maxlen = max(maxlen , (right-left+1));
        right++ ;
    }
    return maxlen ;
}
```

17. [middle of ll](https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
Node *findMiddle(Node *head) {
    if(not head or not head->next) return head ;
    Node* slow = head , *fast = head->next ;
    while(fast){
        slow = slow->next ;
        if(fast->next != NULL) fast = fast->next->next ;
        else break ;
    }
    return slow ;
}
```

18. [merge two sorted list](https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* head = new Node<int>(0);
    Node<int>* top = head ;
    while(first and second){
        if(first->data < second->data){
            head->next = first ;
            head = first ;
            first = first->next ;
        }
        else{
            head->next = second ;
            head = second ;
            second = second->next ;
        }
    }
    while(first){
        head->next = first ;
        head = first ;
        first = first->next ;
    }
    while(second){
        head->next = second ;
        head = second ;
        second = second->next ;
    }
    return top->next ;
}
```

19. [delete kth node from end](https://www.codingninjas.com/codestudio/problems/delete-kth-node-from-end-in-linked-list_799912?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(not head or K == 0) return head ;
    
    int mlen = 0;
    LinkedListNode<int> *curr = head , *prev ;
    while(curr){
        mlen++ ; curr = curr->next ;
    }
    int front = mlen-K ;
    if(front == 0) return head->next ;
    curr = head ;
    while(front--){
        prev = curr ;
        curr = curr->next ;
    }
    prev->next = curr->next ;
    return head ;
}
```

20. [Add two numbers as ll](https://www.codingninjas.com/codestudio/problems/add-two-numbers-as-linked-lists_1170520?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp

Node *addTwoNumbers(Node *head1, Node *head2)
{
    int carry = 0 ;
    Node* head = new Node(0) ;
    Node* curr = head ;
    while(head1 and head2){
        int ss = head1->data + head2->data + carry ;
        head1->data = ss%10 ;
        carry = ss/10 ;
        curr->next = head1 ;
        curr = head1 ;
        
        head1 = head1->next ;
        head2 = head2->next ;
    }
    while(head1){
        int ss = head1->data  + carry ;
        head1->data = ss%10 ;
        carry = ss/10 ;
        curr->next = head1 ;
        curr = head1 ;
        
        head1 = head1->next ;
    }
    while(head2){
        int ss = head2->data + carry ;
        head2->data = ss%10 ;
        carry = ss/10 ;
        curr->next = head2 ;
        curr = head2 ;
        
        head2 = head2->next ;
    }
    if(carry > 0){
        curr->next = new Node(carry);
    }
    return head->next ;
}
```

21. [reverse nodes in k groups](https://www.codingninjas.com/codestudio/problems/reverse-blocks_763406?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 
pair<Node * , Node *> reverseList(Node* curr, int mlen){
    Node* prev = NULL , *nxt = curr->next;
    while(curr and mlen--){
        curr->next = prev ;
        prev = curr ;
        curr = nxt ;
        if(nxt){
            nxt = nxt->next ;
        }
    }
    return {prev , curr} ;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    int ptr = 0 ;
    Node* newnode = new Node(0);
    Node* curr = newnode ;
    
    while(head and ptr < n){
        if(b[ptr] == 0){
            ptr++ ; continue ;
        }        
        if(b[ptr] == 1){
            curr->next = head ;
            curr = head ;
            head = curr->next ;
            ptr++ ;
            continue ;
        }
        
        pair<Node* , Node* > res = reverseList(head , b[ptr]);
        
        curr->next = res.first ;
        curr = head ;
        head = res.second ;
        
        ptr++ ;
    }
    if(head){
        curr->next = head ;
    }
    return newnode->next ;
}
```

22. [linked list cycle 2](https://www.codingninjas.com/codestudio/problems/detect-the-first-node-of-the-loop_1112628?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include <bits/stdc++.h> 

Node *firstNode(Node *head)
{
    Node* slow = head , *fast = head ;
    while(fast and fast->next){
        slow = slow->next ; 
        fast = fast->next->next ;
        if(slow == fast){
            fast = head ;
            while(fast != slow){
                slow = slow->next ;
                fast = fast->next ;
            }
            return fast ;
        }
    }
    return NULL ;
}
```

23. [rotate link list](https://www.codingninjas.com/codestudio/problems/rotate-linked-list_920454?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
Node *rotate(Node *head, int k) {
    int mlen = 0 ;
    Node* curr = head , *last , *prev;
    while(curr){
        mlen++ ;
        last = curr ;
        curr = curr->next ;
    }
    k = k%mlen ;
    if(k == 0) return head ;
    k = mlen - k ;
    curr = head ;
    while(k--){
        prev = curr ;
        curr = curr->next ;
    }
    prev->next = NULL ;
    last->next = head ;
    return curr ;
}
```

24. []()
```cpp
int removeDuplicates(vector<int> &arr, int n) {
    int ptr = 1 , count = 1;
    
    while(ptr < n){
        while(ptr < n and arr[ptr-1] == arr[ptr]) ptr++ ;
        if(ptr < n) count++ ;
        ptr++ ;
    }
    return count ;
}
```