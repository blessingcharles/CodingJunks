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

24. [remove duplicates](https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-sorted-array_1102307?topList=striver-sde-sheet-problems&leftPanelTab=0)
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

25. [max consecutive 1](https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_892994?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
int longestSubSeg(vector<int> &arr , int n, int k){
    int maxlen = 0 ;
    int curzeros = 0 ;
    int right =  0 , left = 0 ;
    
    while(right < n){
        if(arr[right] == 0) curzeros++ ;
        while(curzeros > k){
            if(arr[left] == 0) curzeros-- ;
            left++ ;
        }
        maxlen = max(maxlen , right-left+1);
        right++ ;
    }
    return maxlen ;
}
```

26. [max meetings](https://www.codingninjas.com/codestudio/problems/maximum-meetings_1062658?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
     vector<int> meet ;
    for(int i = 0 ; i < start.size() ; i++){
        meet.push_back(i);
    }
   
    sort(meet.begin() , meet.end() , [&](int a , int b){
        if(end[a] == end[b]) return a < b ;
        return end[a] < end[b] ;
    });
    vector<int> res ;
    res.push_back(meet[0]+1) ;
    int curend = end[meet[0]] ;
    
    for(int i = 1 ; i < meet.size() ; i++){
        if(start[meet[i]] > curend){
            curend = end[meet[i]];
            res.push_back(meet[i]+1);
        }
    }
    return res ;
}
```

27. [min platforms](https://www.codingninjas.com/codestudio/problems/minimum-number-of-platforms_799400?topList=striver-sde-sheet-problems&leftPanelTab=3)
```cpp
int calculateMinPatforms(int at[], int dt[], int n) {
    int min_platforms = 0 , curr = 0 , ptr1 = 0 , ptr2 = 0;
    sort(at , at+n);
    sort(dt , dt+n);
    while(ptr1 < n){
        if(at[ptr1] <= dt[ptr2]){
            curr++ ; ptr1++ ;
        }
        else{
            curr-- ; ptr2++ ;
        }
        min_platforms = max(min_platforms , curr);
    }
    return min_platforms ;
}
```


28. [job sequencing problem](https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int jobScheduling(vector<vector<int>> &jobs)
{
    int max_deadline = 0 ;
    sort(jobs.begin() , jobs.end() , [&max_deadline](vector<int> &a , vector<int> &b){
       max_deadline = max({max_deadline , a[0] , b[0]});
       return a[1] > b[1] ; 
    });
    
    vector<bool> filled(max_deadline , false);
    
    int mprofit = 0 ;
    for(vector<int> &j : jobs){
        int deadline = j[0]-1 ;
        // can i place on or before the slots
        while(deadline >= 0 and filled[deadline]) deadline-- ;
        if(deadline >= 0){
            filled[deadline] = true ;
            mprofit += j[1] ; 
        }
    }
    return mprofit ;
}
```

29. [fractional knapsack](https://www.codingninjas.com/codestudio/problems/fractional-knapsack_975286?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin() , items.end() , [](pair<int,int> &a , pair<int,int> &b){
         double p1 = (double )a.second/a.first ;
         double p2 = (double )b.second/b.first ;
         return p1 > p2 ;
    });
    double mprofit = 0 ;
    for(int i = 0 ; i < n and w > 0; i++){
        if(w - items[i].first >= 0){
            mprofit += items[i].second ;
            w -= items[i].first ;
        }
        else{
            mprofit = mprofit + ((double )items[i].second/items[i].first)*w ;
            w = 0 ;
        }
    }
    return mprofit ;
}
```

30. [find min coins](https://www.codingninjas.com/codestudio/problems/find-minimum-number-of-coins_975277?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp

int findMinimumCoins(int amount) 
{
    vector<int> arr = {1000 , 500 , 100 , 50 , 20 , 10 , 5 , 2 , 1} ;
    
    int ptr = 0 ;
    int count = 0 ;
    while(amount > 0){
        if(amount - arr[ptr] >= 0){
            count += amount/arr[ptr] ;
            amount = amount%arr[ptr] ;
        }
        else{
            ptr++ ;
        }
    }
    return count ;
}
```

31. [maximum activities](https://www.codingninjas.com/codestudio/problems/maximum-activities_1062712?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> activities ;
    for(int i = 0 ; i < start.size() ; i++){
        activities.push_back({finish[i] , start[i]});
    }
    sort(activities.begin() , activities.end());
    
    int count = 1 , curend = activities[0].first ;
    
    for(int i = 1 ; i < start.size() ; i++){
        if(activities[i].second >= curend){
            curend = activities[i].first ;
            count++ ;
        }
    }
    return count ;
}
```

32. [subset sum](https://www.codingninjas.com/codestudio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
vector<int> subsetSum(vector<int> &num){
    vector<int> res ;
    res.push_back(0);
    int N = num.size() ;
    unsigned int mp = (1<<N)-1 ;
    for(int i = 1 ; i <= mp ; i++){
        int cursum = 0  ;
        for(int j = 0 ; j < N ; j++){
            if((i&(1<<j)) != 0){
                cursum += num[j];
            }
        }
        res.push_back(cursum) ;
    }
    sort(res.begin() , res.end());
    return res ;
}
```

33. [subset 2](https://www.codingninjas.com/codestudio/problems/unique-subsets_3625236?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
void helper(vector<int> &arr , int pos , vector<int> &curr , vector<vector<int>> &res){
    res.push_back(curr);
    for(int i = pos ; i < arr.size() ; i++){
        if(i != pos and arr[i] == arr[i-1]) continue ; 
        curr.push_back(arr[i]);
        helper(arr , i+1 , curr , res);
        curr.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    sort(arr.begin() , arr.end());
    vector<int> curr ; 
    vector<vector<int>> res ;
    helper(arr , 0 , curr , res);
    return res ;
}
```

34. [subsets sum to k](https://www.codingninjas.com/codestudio/problems/return-subsets-sum-to-k_759331?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
void helper(int pos , vector<int> &arr , vector<int> &curr , vector<vector<int>> &res , int cursum){
    if(cursum == 0 and pos == arr.size()){
        res.push_back(curr);
        return ;
    }
    if(pos == arr.size()) return ;
    curr.push_back(arr[pos]);
    helper(pos+1  , arr , curr , res , cursum-arr[pos]);
    curr.pop_back() ;
    helper(pos+1 , arr , curr , res , cursum);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> res ;
    vector<int> curr ;
    helper(0 , arr , curr , res , k);
    return res ;
}
```

35. [kth permutation](https://www.codingninjas.com/codestudio/problems/k-th-permutation-sequence_1112626?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

string kthPermutation(int n, int k) {
    string str = "" ;
    vector<int> arr ;
    int fact = 1 ;
    for(int i = 1 ; i < n ; i++){
        arr.push_back(i);
        fact *= i ;
    }
    arr.push_back(n);
    
    k-- ;
    while(true){
        int idx = k/fact ;
        str.push_back(arr[idx]+'0');
        arr.erase(arr.begin() + idx);
        if(arr.size() == 0) break ;
        k = k%fact ;
        fact = fact/arr.size();
    }
    return str ;
}
```

37. [N queens](https://www.codingninjas.com/codestudio/problems/n-queens_759332?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
int N ;
bool canIplace(int row , int col , vector<vector<int>> &board){
    for(int i = 0 ; i < N ; i++){
        if(board[i][col] == 1) return false ;
    }
    int k = 1 ; bool flag = true ;
    while(flag){
        flag = false ;
        if(row+k < N and col+k < N){
            flag = true ;
            if(board[row+k][col+k] == 1)
                return false ;
        } 
        if(row-k >= 0 and col-k >= 0){
            flag = true ;
            if(board[row-k][col-k] == 1)
                return false ;
        } 
        if(row+k < N and col-k >= 0){
            flag = true ;
            if(board[row+k][col-k] == 1)
                return false ;
        } 
        if(row-k >= 0 and col+k < N){
            flag = true ;
            if(board[row-k][col+k] == 1)
                return false ;
        } 
        k++ ;
    }
    return true ;
}
void solve(int row , vector<vector<int>> &board , vector<vector<int>> &ans){
    if(row == N){
        vector<int> temp ;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                temp.push_back(board[i][j]) ;
            }
        }
        ans.push_back(temp);
        return ;
    }
    for(int col = 0 ; col < N ;col++){
        if(canIplace(row , col ,board)){
            board[row][col] = 1 ;
            solve(row+1 , board , ans);
            board[row][col] = 0 ;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n , vector<int>(n , 0));
    vector<vector<int>> ans ;
    N = n ;
    solve(0 , board , ans) ;
    return ans ;
}
```

38. [sudoko](https://www.codingninjas.com/codestudio/problems/sudoku_758961?topList=striver-sde-sheet-problems&leftPanelTab=1)
```cpp
#include<bits/stdc++.h>
bool canIplace(int ele , int row , int col , int matrix[9][9]){
    for(int i = 0 ; i < 9 ; i++){
        if(matrix[row][i] == ele or matrix[i][col] == ele)
            return false ;
    }
    int s_row = 3*floor(row/3) ;
    int s_col = 3*floor(col/3) ;
    
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(matrix[i+s_row][i+s_col] == ele){
                return false ;
            }
        }
    }
    return true ;
}
bool helper(int row , int col , int matrix[9][9]){
    if(row == 9){
        return true ;
    }
    if(col == 9){
        return helper(row+1 , 0 , matrix);
    }
    if(matrix[row][col] != 0){
        return helper(row , col+1 , matrix);
    }
    for(int i = 1 ; i <= 9 ; i++){
        if(canIplace(i , row , col , matrix)){
            matrix[row][col] = i ;
            if(helper(row , col+1 , matrix)){
                return true ;
            }
            matrix[row][col] = 0 ;
        }
    }
    return false ;
}
bool isItSudoku(int matrix[9][9]) {
    return helper(0,0,matrix);
}
```

39. [m-coloring](https://www.codingninjas.com/codestudio/problems/m-coloring-problem_981273?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int N ;
bool canIPlace(int cc , int node , vector<int> &color , vector<vector<int>> &adj){
    for(int i = 0 ; i < N ; i++){
        if(adj[i][node] == 1 or adj[node][i] == 1){
            if(color[i] == cc) return false ;
        }
    }
    return true ;
}
bool canColor(int node , vector<vector<int>> &adj , int m , vector<int> &color){
    if(node == N) return true ;
    for(int c = 1 ; c<= m ; c++){
        if(canIPlace(c , node , color , adj)){
            color[node] = c ;
            if(canColor(node+1 , adj , m , color)){
                return true ;
            }
            color[node] = 0 ;
        }
    }
    return false ;
}
string graphColoring(vector<vector<int>> &adj, int m) {
    N = adj.size() ;
    vector<int> color(N , 0 );
    return (canColor(0 , adj , m , color))?"YES":"NO" ;
}
```

40. [word break 2](https://www.codingninjas.com/codestudio/problems/word-break-ii_983635?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

vector<string> helper(int pos , string &s , unordered_set<string> &dict ,unordered_map<int , vector<string> > &memo){
    if(pos == s.size()) return {} ;
    if(memo.find(pos) != memo.end()){
        return memo[pos] ;
    }
    vector<string> res ;
    if(dict.find(s.substr(pos)) != dict.end()){
        res.push_back(s.substr(pos));
    }
    string temp = "";
    for(int i = pos ; i < s.size() ; i++){
        temp.push_back(s[i]);
        if(dict.find(temp) != dict.end()){
            for(string ss : helper(i+1 , s , dict , memo)){
                res.push_back(temp + " " + ss);
            }
        }
    }
    return memo[pos] = res ;
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_set<string> dict(dictionary.begin() , dictionary.end());
    unordered_map<int,vector<string>> memo ;    
    return helper(0 , s , dict , memo);
}
```

41. [nth root of m](https://www.codingninjas.com/codestudio/problems/nth-root-of-m_1062679?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
double multiply(double m,int n){
    double ans=1.00;
    while(n>0){
        ans*=m;
        n--;
    }
    return ans;
}
double findNthRootOfM(int n, long long m) {
    double l=1,r=m,esp=1e-9;
    while((r-l)>esp){
        double mid=(l+r)/2.00;
        if(multiply(mid,n) < (double)m){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    return l;
}
```

42. [single element](https://www.codingninjas.com/codestudio/problems/unique-element-in-sorted-array_1112654?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
int uniqueElement(vector<int> arr, int n)
{
    int xor_val = 0 ;
    for(int ele : arr){
        xor_val = xor_val ^ ele ;
    }
    return xor_val ;
}
```

43. [median of two sorted array](https://www.codingninjas.com/codestudio/problems/median-of-two-sorted-arrays_985294?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
double median(vector<int> a, vector<int> b){
    /*
        1 2 3 4            a 
        1 2 3 4 5 6 7      b
    */
    if(a.size() > b.size()){
        return median(b,a);
    }
    int M = b.size() , N = a.size() ;
    int low = 0 , high = N ;
    int total = (N+M+1)/2 ;
    while(low <= high){
        int mid = low + (high-low)/2 ;
        int p2 = total - mid ;
        
//        r1 = mid , l1 = mid-1 ;
//        r2 = p2 , l2 = mid-1 ;
        
        int r1 = (mid < N)?a[mid]:INT_MAX ;
        int l1 = (mid-1 >= 0)?a[mid-1]:INT_MIN ;
        
        int r2 = (p2 < M)?b[p2]:INT_MAX ;
        int l2 = (p2-1 >= 0)?b[p2-1]:INT_MIN ;
        
        if(r1 >= l2 and r2 >= l1){
            if((M+N)%2 == 0){
                return (double )((double)max(l1 , l2) + (double)min(r1 , r2))/2.0 ;
            }
            return max(l1 , l2);
        }
        else if(l1 > r2){
            high = mid-1 ;
        }
        else{
            low = mid+1 ;
        }
    }
    return 0 ;
}
```

44. [kth element of two sorted array]()
```cpp

```

45. [Allocate Books](https://www.codingninjas.com/codestudio/problems/ayush-gives-ninjatest_1097574?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
bool isPossible(long long time_per_day , int mdays , vector<int> &time){
    long long curr = time_per_day , day = 1 ;
    for(int t : time){
        if(curr - t >= 0){
            curr -= t ;
        }
        else{
            day++ ;
            if(day > mdays) return false ;
            if(time_per_day-t < 0) return false ;
            
            curr = time_per_day-t ;
        }
    }
    return true ;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long low = 1 , high = LONG_MAX ;
    long long mid ;
    while(low < high){
        mid = low + (high - low)/2 ;
        if(not isPossible(mid , n , time)){
            low = mid+1 ;
        }    
        else{
            high = mid ;
        }
    }
    return high ;
}
```

46. [chess tournament](https://www.codingninjas.com/codestudio/problems/chess-tournament_981299?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
bool isPossible(int space , vector<int> &positions , int players){
    int prev_idx = 0 , count = 1 ;
    
    for(int i = 1 ; i < positions.size() ; i++){
        if(positions[i]-positions[prev_idx] >= space){
            prev_idx = i ;
            count++ ;
            if(count == players) return true ;
        }
    }
    return false ;
}
int chessTournament(vector<int> &positions , int n ,  int c){
    sort(positions.begin() , positions.end());
    int low = 1 , high = positions.back() - positions[0] ;
    
    while(low < high){
        int mid = low + (high - low + 1)/2 ;
        if(isPossible(mid , positions , c)){
            low = mid ;
        }
        else{
            high = mid-1 ;
        }
    }
    return low ;
}
```

47. [Min Heap](https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
class MinHeap{
public:
    vector<int> arr ;
    int size  ;
    MinHeap(){
        size = 0 ;
    }
    int getParent(int node){
        return (node-1)/2 ;
    }
    int leftChild(int node){
        return (node*2)+1 ;
    }
    int rightChild(int node){
        return (node*2)+2 ;
    }
    void insert(int val){
        arr.push_back(val);
        size++ ;
        int curr = size-1 ;
        while(curr != 0  and arr[getParent(curr)] > val){
            swap(arr[getParent(curr)] , arr[curr]);
            curr = getParent(curr);
        }
    }
    int top(){
        if(isEmpty()) return -1 ;
        return arr[0] ;
    }
    void heapify(int node){
        int r_idx = rightChild(node) , l_idx = leftChild(node) ;
        int r_val = INT_MAX , l_val = INT_MAX ;
        if(r_idx < size){
            r_val = arr[r_idx] ;
        }
        if(l_idx < size){
            l_val = arr[l_idx] ;
        }
        int minval = min(r_val , l_val);
        
        if(minval < arr[node]){
            if(minval == l_val){
                swap(arr[node] , arr[l_idx]);
                heapify(l_idx) ;
            }
            else{
                swap(arr[node] , arr[r_idx]);
                heapify(r_idx) ;
            }
        }
    }
    bool pop(){
        if(isEmpty()) return false ;
        arr[0] = arr.back() ;
        size-- ;
        arr.pop_back() ;
        heapify(0);
        return true ;
    }
    bool isEmpty(){
        return size == 0 ;
    }
};
vector<int> minHeap(int n, vector<vector<int>>& queries) {
    vector<int> res ;
    MinHeap *mh = new MinHeap() ;
    
    for(vector<int> &q : queries){
        if(q[0] == 0){
            mh->insert(q[1]);        
        }
        else{
            res.push_back(mh->top());
            mh->pop();
        }
    }
    return res ;
}
```

48. [k max combination](https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    sort(b.begin() , b.end());
    int N = b.size() ;
    
    priority_queue<pair<int,int>> pq ;
    for(int ele : a){
        pq.push({ele + b[N-1] , N-1});
    }
    pair<int,int> curr ;
    vector<int> res ;
    
    while(k--){
        curr = pq.top() ; pq.pop() ;
        res.push_back(curr.first);
        
        curr.second-- ;
        if(curr.second >= 0){
            int val = curr.first - b[curr.second+1] ; // my val
            
            pq.push({val + b[curr.second] , curr.second});
        }
    }
    return res ;
}
```

49. [Running Median](https://www.codingninjas.com/codestudio/problems/running-median_625409?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    priority_queue<int> maxh ;
    priority_queue<int , vector<int> , greater<int>> minh ;
    for(int i = 1 ; i <= n ; i++){
        maxh.push(arr[i-1]);
        if(maxh.size() > minh.size()){
            minh.push(maxh.top()) ;
            maxh.pop() ;
        }
        else if(not minh.empty() and maxh.top() > minh.top()){
            int ele = maxh.top() ; maxh.pop() ;
            maxh.push(minh.top()) ; minh.pop() ;
            minh.push(ele);
        }
        if(i%2 == 1){
            cout << minh.top() << " ";
        }
        else{
            cout << (maxh.top() + minh.top())/2 << " ";
        }
    }
}
```

50. [trie 2](https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

class Node{
public:
    Node* children[26] ;
    int childrens_count[26] ;
    int t_count ;
    bool isTerminal ;
    Node(){
        t_count = 0 ;
        memset(children ,NULL,sizeof(children) );
        memset(childrens_count , 0, sizeof(childrens_count) ) ;
        isTerminal = false ;
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    void insert(string &word){
        Node* crawler = root ;
        for(char ch : word){
            if(crawler->children[ch-'a'] == NULL){
                crawler->children[ch-'a'] = new Node() ;
            }
            crawler->childrens_count[ch-'a']++ ;
            crawler = crawler->children[ch-'a'] ;
        }
        crawler->t_count++ ;
        crawler->isTerminal = true ;
    }
    int countWordsEqualTo(string &word){
        Node* crawler = root , *prev = root;
        for(char ch : word){
            if(crawler->children[ch-'a'] == NULL){
                return 0 ;
            }
            prev = crawler ;
            crawler = crawler->children[ch-'a'] ;
        }
        if(not crawler->isTerminal) return 0 ;
        return crawler->t_count ;
    }
    int countWordsStartingWith(string &word){
        Node* crawler = root , *prev = root;
        for(char ch : word){
            if(crawler->children[ch-'a'] == NULL){
                return 0 ;
            }
            prev = crawler ;
            crawler = crawler->children[ch-'a'] ;
        }
        return prev->childrens_count[word.back()-'a'];
    }
    void erase(string &word){
        Node* crawler = root , *prev ;
        for(char ch : word){
            if(crawler->children[ch-'a'] == NULL){
                return ;
            }
            crawler->childrens_count[ch-'a']-- ;
            prev = crawler ;
            crawler = crawler->children[ch-'a'] ;
            if(prev->childrens_count[ch-'a'] == 0){
                prev->children[ch-'a'] = NULL ;
            }
        }
        crawler->t_count-- ;
        if(crawler->t_count == 0) crawler->isTerminal = false ;
    }
};
```
51. [complete stirng](https://www.codingninjas.com/codestudio/problems/complete-string_2687860?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

class Node{
public:
    Node* children[26] ;
    bool isTerminal ;
    Node(){
        memset(children, NULL, sizeof(children)) ;
        isTerminal = false ;
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    void insert(string &word){
        Node* crawler = root ;
        for(char ch : word){
            if(crawler->children[ch-'a'] == NULL){
                crawler->children[ch-'a'] = new Node() ;
            }
            crawler = crawler->children[ch-'a'];
        }
        crawler->isTerminal = true ;
    }
    bool search(string &word){
        Node* crawler = root ;
        for(char ch : word){
            if(not crawler->children[ch-'a'] or not crawler->children[ch-'a']->isTerminal){
                return false ;
            }
            crawler = crawler->children[ch-'a'] ;
        }
        return true ;
    }
};
string completeString(int n, vector<string> &a){
    Trie *t = new Trie() ;
    for(string &word : a){
        t->insert(word);
    }
    int maxlen = 0 ;
    string res = "" ;
    for(string &word : a){
        if(word.size() < maxlen 
               or not t->search(word)) continue ;
        
        if(word.size() == res.size()){
            res = min(word , res);
        }
        else{
            maxlen = word.size() ;
            res = word ;
        }
    }
    return (maxlen == 0)?"None":res ;
}
```

52. [No os distinct substring](https://www.codingninjas.com/codestudio/problems/number-of-distinct-substring_1465938?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int distinctSubstring(string &word) {
    unordered_set<string> st ;
    
    for(int i = 0 ; i < word.size() ; i++){
        string temp = "" ;
        for(int j = i ; j < word.size() ; j++){
            temp.push_back(word[j]);
            st.insert(temp);
        }
    }
    return st.size() ;
}
```

53. [power set](https://www.codingninjas.com/codestudio/problems/power-set_1062667?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
void helper(int pos , vector<int> &v , vector<int> &curr , vector<vector<int>> &res){
    if(pos == v.size()){
        res.push_back(curr) ;
        return ;
    }
    helper(pos+1 , v , curr , res);
    curr.push_back(v[pos]);
    helper(pos+1 , v , curr , res);            
    curr.pop_back();
}
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> res ;
    vector<int> curr ;
    helper(0 , v , curr , res) ;
    return res ;
}
```

54. [max xor of two elements](https://www.codingninjas.com/codestudio/problems/power-set_1062667?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

class Node{
public:
    Node* children[2] ;
    Node(){
        memset(children , NULL , sizeof(children));
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    void insert(int num){
        Node* crawler = root ;
        for(int i = 31 ; i >= 0 ; i--){
            bool isSet = (num >> i)&1 ;
            if(crawler->children[isSet] == NULL){
                crawler->children[isSet] = new Node() ;
            }
            crawler = crawler->children[isSet] ;
        }
    }
    int search(int num){
        Node* crawler = root ;
        int maxval = 0 ;
        for(int i = 31 ; i >= 0 ; i--){
            bool isSet = (num >> i)&1 ;
            bool need = not isSet ;
            if(crawler->children[need] != NULL){
                maxval = maxval | (1 << i) ;
                crawler = crawler->children[need] ;
            }
            else{
                crawler = crawler->children[isSet] ;
            }
        }
        return maxval ;
    }
};
int maximumXor(vector<int> A)
{
    Trie* t = new Trie();
    for(int ele : A){
        t->insert(ele) ;
    }
    int maxval = 0 ;
    for(int ele : A){
        maxval = max(maxval , t->search(ele));
    }
    return maxval ; 
}
```

55. [max xor with element in array](https://www.codingninjas.com/codestudio/problems/power-set_1062667?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

class Node{
public:
    Node* children[2] ;
    int minContrib ;
    Node(){
        minContrib = INT_MAX ;        
        memset(children , NULL , sizeof(children));
    }
};
class Trie{
public:
    Node* root ;
    Trie(){
        root = new Node() ;
    }
    void insert(int num){
        Node* crawler = root ;
        for(int i = 31 ; i >= 0 ; i--){
            bool isSet = (num >> i)&1 ;
            if(crawler->children[isSet] == NULL){
                crawler->children[isSet] = new Node() ;
            }
            crawler = crawler->children[isSet] ;
            crawler->minContrib = min(num , crawler->minContrib) ;
        }
    }
    int search(int num , int range){
        Node* crawler = root ;
        int maxval = 0 ;
        for(int i = 31 ; i >= 0 ; i--){
            bool isSet = (num >> i)&1 ;
            bool need = not isSet ;
            if(crawler->children[need] != NULL and crawler->children[need]->minContrib <= range){
                maxval = maxval | (1 << i) ;
                crawler = crawler->children[need] ;
            }
            else if(crawler->children[isSet]->minContrib <= range){
                crawler = crawler->children[isSet] ;
            }
            else{
                break ;
            }
        }
        return maxval ;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    Trie* t = new Trie();
    for(int ele : arr){
        t->insert(ele) ;
    }
    vector<int> res ;
    for(vector<int> &q : queries){
        int val = t->search(q[0] , q[1]) ;
        if(val == 0){
            res.push_back(-1);        
        }
        else{
            res.push_back(val);
        }
    }
    return res ; 
}
```

56. [stack using array](https://www.codingninjas.com/codestudio/problems/power-set_1062667?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
// Stack class.
class Stack {
    
public:
    int size ;
    int *arr ;
    int idx ;
    Stack(int capacity) {
        size = capacity ;
        arr = new int[size] ;
        idx = 0 ;
    }
    void push(int num) {
        if(isFull()) return ;
        arr[idx] = num ;
        idx++ ;
    }
    int pop() {
        if(isEmpty()) return -1 ;
        idx-- ;
        return arr[idx] ;
    }
    
    int top() {
        if(isEmpty()) return -1 ;
        return arr[idx-1] ;
    }
    int isEmpty() {
        return idx == 0 ;
    }
    
    int isFull() {
        return idx == size ;
    }
};
```

57. [next smaller element](https://www.codingninjas.com/codestudio/problems/power-set_1062667?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st ;
    vector<int> ans(n , -1);
    
    for(int i = n-1 ; i >= 0 ; i--){
        while(not st.empty() and st.top() >= arr[i]){
            st.pop() ;
        }
        if(not st.empty()){
            ans[i] = st.top() ;
        }
        st.push(arr[i]);
    }
    return ans ;
}
```

58. [lfu cache](https://www.codingninjas.com/codestudio/problems/lfucache_3114758?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
class LFUCache
{
    unordered_map<int , list<pair<int,int>>> bucket ;
    unordered_map<int  , int> frequency ;
    unordered_map<int , list<pair<int,int>>::iterator > memo ;
public:
    int size = 0 ;
    int count = 0 ;
    int l_freq = 1 ;
    LFUCache(int capacity){
        size = capacity ;
    }
    int get(int key)
    {
        if(memo.find(key) == memo.end()) return -1 ;
        int last_freq = frequency[key] ;
        frequency[key]++ ;
        list<pair<int,int>>::iterator it = memo[key] ;
        pair<int,int> itp = *it ;
        
        bucket[last_freq+1].push_back({itp.first , itp.second}) ;
        memo[key] = --(bucket[last_freq+1].end()) ;
        
        bucket[last_freq].erase(it) ;
        if(bucket[last_freq].size() == 0 and l_freq == last_freq){
            l_freq++ ;
        }
        return itp.second ;
    }
    void put(int key, int value)
    {
        if(memo.find(key) != memo.end()){
            int last_freq = frequency[key] ; frequency[key]++ ;
            list<pair<int,int>>::iterator it = memo[key] ;
            
            bucket[last_freq+1].push_back({key , value}) ;
            
            memo[key] = --(bucket[last_freq+1].end()) ;
            
            bucket[last_freq].erase(it) ;
            if(bucket[last_freq].size() == 0 and l_freq == last_freq){
                l_freq++ ;
            }
            return ;
        }
        if(count == size){
//             remove the least frequent guy
            list<pair<int,int>>::iterator it = bucket[l_freq].begin() ;
            pair<int,int> itp = bucket[l_freq].front() ;
            bucket[l_freq].pop_front();
            memo.erase(itp.first);
            frequency.erase(itp.first);
            count-- ;
        }
        
        count++ ;
        bucket[1].push_back({key,value}) ;
        frequency[key] = 1 ;
        memo[key] = --(bucket[1].end()) ;
        l_freq = 1 ;
    }
};

```

59. [max in sliding window k](https://www.codingninjas.com/codestudio/problems/sliding-window-maximum_980226?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    deque<int> dq ;
    vector<int> res ;
    int n = nums.size() ;
    for(int i = 0 ; i < n ; i++){
        if(not dq.empty() and dq.front() == i-k) dq.pop_front() ;
        
        while(not dq.empty() and nums[dq.back()] < nums[i]) dq.pop_back() ;
        dq.push_back(i) ;
    
        if(i-k >= -1){
            res.push_back(nums[dq.front()]);
        }
    }
    return res ;
}
```

60. [min stack](https://www.codingninjas.com/codestudio/problems/min-stack_3843991?topList=striver-sde-sheet-problems&leftPanelTab=1)
```cpp
class minStack
{
    stack<int> st ;
    stack<int> mini ;
	public:
		minStack(){ 
		}
		void push(int num){
            st.push(num) ;
            if(mini.empty() or mini.top() >= num){
                mini.push(num);
            }
		}
		int pop()
		{
            if(isEmpty()) return -1 ;
            int ele = st.top() ; st.pop() ;
            if(mini.top() == ele){
                mini.pop() ;
            }
            return ele ;
        }
		int top()
		{
            if(isEmpty()) return -1 ;
            return st.top() ;
        }
		int getMin()
		{
            if(isEmpty()) return -1 ;
            return mini.top() ;
        }
        bool isEmpty(){
            return st.empty() ;
        }
};
```


61. [Rotting oranges](https://www.codingninjas.com/codestudio/problems/rotting-oranges_701655?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int M , N ;
bool isInvalid(int row , int col){
    return row < 0 or col < 0  or row >= M or col >= N ;
}

int minTimeToRot(vector<vector<int>>& grid, int m, int n)
{
    M = m; N = n ;
    int fresh_oranges = 0 ;
    queue<pair<int,int>> q ;
    for(int i = 0 ;i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            if(grid[i][j] == 2){
                q.push({i,j});
                grid[i][j] = 0 ;
            }
            else if(grid[i][j] == 1){
                fresh_oranges++ ;
            }
        }
    }
    if(fresh_oranges == 0) return 0 ;
    int time = 1 ;
    int dx[4] = {-1 ,1,0,0};
    int dy[4] = {0,0,1,-1};
    
    while(not q.empty()){
        int sz = q.size() ;
        while(sz--){
            int row = q.front().first , col = q.front().second ;
            q.pop() ;
            for(int i = 0 ; i < 4 ; i++){
                int neigh_r = row + dx[i] ;
                int neigh_c = col + dy[i] ;
                if(isInvalid(neigh_r , neigh_c) or grid[neigh_r][neigh_c] != 1){
                    continue ;
                }
                grid[neigh_r][neigh_c] = 0;
                fresh_oranges-- ;
                q.push({neigh_r , neigh_c});
            }
        }
        if(fresh_oranges == 0) return time ;
        time++ ;
    }
    return -1 ;
}
``` 
62. [atoi](https://www.codingninjas.com/codestudio/problems/atoi_981270?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int atoi(string str) {
    int val = 0 ;
    int i = 0 ;
    bool isnegative = false ;
    if(str[i] == '-'){
        i++ ;
        isnegative = true ;
    }
    for( ;i < str.size() ; i++){
        if(not isdigit(str[i])) continue ;
        val = val*10 + (str[i]-'0');
    }
    if(isnegative) return -1*val ;
    return val ;
}
```

63. [pattern matching](https://www.codingninjas.com/codestudio/problems/stringmatch-rabincarp_1115738?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
void lps(string &pat , vector<int> &table){
    int ptr = 0 , right = 1 ;
    while(right < pat.size()){
        if(pat[right] == pat[ptr]){
            ptr++ ;
            table[right] = ptr ;
            right++ ;
        }
        else{
            if(ptr != 0){
                ptr = table[ptr-1] ;
            }
            else{
                right++ ;
            }
        }
    }
}
vector<int> stringMatch(string &str, string &pat) {
    vector<int> table(pat.size() , 0);
    lps(pat , table);
    int s_ptr = 0 , p_ptr = 0 , N = pat.size() ;
    vector<int> res ;
    while(s_ptr < str.size()){
        if(str[s_ptr] == pat[p_ptr]){
            s_ptr++ ; p_ptr++ ;
            if(p_ptr == N){
                res.push_back(s_ptr-N) ;
                p_ptr = table[p_ptr-1] ;
            }
        }
        else{
            if(p_ptr != 0){
                p_ptr = table[p_ptr-1] ;
            }
            else{
                s_ptr++ ;
            }
        }
    }
    return res ;
}
```

64. [z algorithm](https://www.codingninjas.com/codestudio/problems/z-algorithm_1112619?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
void lps(string &pat , vector<int> &table){
    int ptr = 0 , right = 1 ;
    while(right < pat.size()){
        if(pat[right] == pat[ptr]){
            ptr++ ; 
            table[right] = ptr ;
            right++ ;
        }
        else{
            if(ptr != 0){
                ptr = table[ptr-1] ;
            }
            else{
                right++ ;
            }
        }
    }
}
int zAlgorithm(string &s, string &p, int n, int m)
{
    vector<int> table(m , 0);
    lps(p , table);
    int s_ptr = 0 , p_ptr = 0 , count = 0;
    while(s_ptr < n){
        if(s[s_ptr] == p[p_ptr]){
            s_ptr++ ; p_ptr++ ;
            if(p_ptr == m){
                count++ ;
                p_ptr = table[p_ptr-1];
            }
        }
        else{
            if(p_ptr != 0){
                p_ptr = table[p_ptr-1];
            }
            else{
                s_ptr++ ;
            }
        }
    }
    return count ;
}
```

65. [check permutation](https://www.codingninjas.com/codestudio/problems/check-permutation_1172164?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
bool areAnagram(string &str1, string &str2){
    if(str1.size() != str2.size()) return false ;
    vector<char> charmap(128 , 0);
    for(char ch : str1) charmap[ch]++ ;
    
    for(char ch : str2){
        if(charmap[ch] == 0) return false ;
        charmap[ch]-- ;
    }
    for(int ele : charmap){
        if(ele != 0) return false ;
    }
    return true ;
}
```

66. [bottom view of bt](https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
vector<int> bottomView(BinaryTreeNode<int> * root){
    unordered_map<int,int> memo ;
    int min_level = 0 , max_level = 0 ;
    queue<pair<int ,BinaryTreeNode<int> *> > q ;
    q.push({0,root}) ;
    pair<int,BinaryTreeNode<int> * > curr ;
    
    while(not q.empty()){
        int sz = q.size();
        while(sz--){
            curr = q.front() ; q.pop() ;
            memo[curr.first] = curr.second->data ;
            min_level = min(min_level , curr.first);
            max_level = max(max_level , curr.first);

            if(curr.second->left){
                q.push({curr.first-1 , curr.second->left});
            }   
            if(curr.second->right){
                q.push({curr.first+1 , curr.second->right});
            }
        }
    }
    vector<int> res ;
    for(int i = min_level ; i <= max_level ; i++){
        res.push_back(memo[i]);
    }
    return res ;
}
```

67. [top view](https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    if(not root) return {} ;
    unordered_map<int,int> memo ;
    int min_level = 0 , max_level = -1 ;
    queue<pair<int ,TreeNode<int> *> > q ;
    q.push({0,root}) ;
    pair<int,TreeNode<int> * > curr ;
    
    while(not q.empty()){
        int sz = q.size();
        while(sz--){
            curr = q.front() ; q.pop() ;
            if(memo.find(curr.first) == memo.end())
                memo[curr.first] = curr.second->val ;
            min_level = min(min_level , curr.first);
            max_level = max(max_level , curr.first);

            if(curr.second->left){
                q.push({curr.first-1 , curr.second->left});
            }   
            if(curr.second->right){
                q.push({curr.first+1 , curr.second->right});
            }
        }
    }
    vector<int> res ;
    for(int i = min_level ; i <= max_level ; i++){
        res.push_back(memo[i]);
    }
    return res ;
}
```

68. [path in tree](https://www.codingninjas.com/codestudio/problems/path-in-a-tree_3843990?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
bool helper(TreeNode<int> *root , int x , vector<int> &path){
    if(not root) return false ;
    path.push_back(root->data);
    if(root->data == x){
        return true ;
    }
    if(helper(root->left , x , path) or helper(root->right , x , path)) 
        return true ;
    path.pop_back();
    return false ;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> path ;
    (helper(root , x , path));
    return path ;
}

```
69. [height of tree level order and inorder](https://www.codingninjas.com/codestudio/problems/calculate-the-height-of-binary-tree-using-inorder-and-level-order-traversal_841416?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
int helper(vector<int> &inorder , int start , int end , unordered_map<int,int> &memo){
    if(start > end) return 0 ; 
    if(start == end) return 1 ;
    
    int idx = 1e9 , in_idx = start;
    for(int i = start ; i <= end ; i++){
        if(idx > memo[inorder[i]]){
            idx = memo[inorder[i]] ;
            in_idx = i ;
        }
    }
    int leftH = helper(inorder , start , in_idx-1 , memo);
    int rightH = helper(inorder , in_idx+1 , end , memo);
    return 1+max(leftH , rightH);
}
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    unordered_map<int,int> memo ;
    for(int i = 0 ; i < N ; i++){
        memo[levelOrder[i]] = i ;
    }
    
    return helper(inorder , 0 , N-1 , memo)-1;
}
```

70. [Bt zigzag traversal](https://www.codingninjas.com/codestudio/problems/zig-zag-traversal_1062662?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> res ;
    if(not root)
        return res ;
    queue<BinaryTreeNode<int>* > q;
    q.push(root);
    int level = 0 ;
    while(not q.empty()){
        int sz = q.size() ;
        vector<int> temp ;
        while(sz--){
            root = q.front() ; q.pop() ;
            temp.push_back(root->data);
            if(root->left){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
        }
        if((level&1) == 1){
            reverse(temp.begin() , temp.end());
        }
        res.insert(res.end() , temp.begin() , temp.end());
        level++ ;
    }
    
    return res ;
}
```
71. [max path sum between two leaves](https://www.codingninjas.com/codestudio/problems/maximum-path-sum-between-two-leaves_794950?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
long long int helper(TreeNode<int> * root , long long int &maxval){
    if(not root)
        return -1 ;
    if(not root->left and not root->right) return root->val ;
    long long int right_side = helper(root->right , maxval) ;

    long long int left_side = helper(root->left , maxval) ;
    
    if(left_side != -1 and right_side != -1){
        maxval = max(maxval , left_side+right_side+root->val);
    }
    return root->val+max(left_side , right_side);
//     return ls ;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    long long int maxval = -1 ;
    helper(root , maxval);
    return maxval ;
}
```

72. [children sum property](https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
void helper(BinaryTreeNode<int> *root , int &maxval){
    if(not root) return ;
    maxval = max(maxval , root->data);
    helper(root->left , maxval);
    helper(root->right , maxval);
}
void solve(BinaryTreeNode<int> *root , int &maxval){
    if(not root) return ;
    if(not root->left and not root->right){
        root->data = maxval ;
        return ;
    }

    solve(root->left , maxval);
    solve(root->right , maxval);
    root->data = 0 ;
    if(root->left){
        root->data = root->left->data ;
    }
    if(root->right){
        root->data += root->right->data ;
    }
}
void changeTree(BinaryTreeNode < int > * root) {
    int maxval = -1e9 ;
    helper(root , maxval) ;
    solve(root , maxval);
}  
```

73. [connect nodes at same level](https://www.codingninjas.com/codestudio/problems/connect-nodes-at-same-level_985347?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
      queue<BinaryTreeNode<int> * > q ;
      q.push(root) ;
      while(not q.empty()){
          int sz = q.size() ;
          while(sz--){
              root = q.front() ; q.pop() ;
              if(sz != 0){
                  root->next = q.front() ;
              }
              else{
                  root->next = NULL ;
              }
              if(root->left) q.push(root->left);
              if(root->right) q.push(root->right) ;
          }
      }
}
```

74. [construct bst from preoder](https://www.codingninjas.com/codestudio/problems/bst-from-preorder_2689307?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>

TreeNode<int>* helper(int left , int right , vector<int> &pre , vector<int> &greater){
    if(left > right) return NULL ;
    if(left == right) return new TreeNode<int>(pre[left]) ;
    
    TreeNode<int>* root = new TreeNode<int>(pre[left]);
    root->left = helper(left+1 , greater[left]-1 , pre , greater);
    root->right = helper(greater[left] , right , pre , greater);
    return root ;
}
TreeNode<int>* preOrderTree(vector<int> &pre){
    int N = pre.size() ;

    vector<int> nxtGreater(N , N-1);
    stack<int> st ;

    for(int i = N-1 ; i >= 0 ; i--){
        while(not st.empty() and pre[st.top()] < pre[i]){
            st.pop() ;
        }
        if(not st.empty()) nxtGreater[i] = st.top() ;
        else nxtGreater[i] = N ;
        st.push(i) ;
    }
    return helper(0 , N-1 ,pre , nxtGreater);
}
```

75. [lca of two nodes in bst](https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    while(root){
        if(root->data > P->data and root->data > Q->data){
            root=root->left ;
        }
        else if(root->data < P->data and root->data < Q->data){
            root=root->right ;
        }
        else{
            return root ;
        }
    }
    return NULL ;
}
```

76. [predessor and successor](https://www.codingninjas.com/codestudio/problems/_893049?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
int predessor = -1 , successor = -1 ;
bool helper(BinaryTreeNode<int> *root , int key, int &prev_val){
    
    if(not root) return false ;
    if(helper(root->left , key,prev_val))
        return true ;
    if(prev_val == key){
        successor = root->data ;
        return true ;
    }
    if(root->data == key){
        predessor = prev_val ;
    }
    prev_val = root->data ;
    return helper(root->right , key ,prev_val);
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    predessor = -1 ; successor = -1 ;
    int prev_val = -1 ;
    helper(root , key , prev_val) ;
    return {predessor , successor} ;
}
```

77. [floor in bst](https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
void helper(TreeNode<int> *root , int target , int &maxval){
    if(not root) return  ;
    if(root->val <= target){
        maxval = max(maxval , root->val);
    }
    if(root->val == target) return ;
    if(root->val < target){
        helper(root->right , target , maxval);
    }
    else{
        helper(root->left , target , maxval);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    int maxval = -1 ;
    helper(root , X , maxval);
    return maxval ;
}
```

78. [ceil from bst](https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
void helper(BinaryTreeNode<int> *root , int t , int &minval){
    if(not root) return  ;
    if(root->data >= t){
        minval = min(minval , root->data);
    }
    if(root->data == t){
        return  ;
    }
    if(root->data < t){
        helper(root->right , t , minval);
    }
    else{
        helper(root->left , t , minval);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    int minval = INT_MAX ;
    helper(node , x , minval);
    return (minval==INT_MAX)?-1:minval ;
}
```

79. [kth largest bst](https://www.codingninjas.com/codestudio/problems/k-th-largest-number_920438?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
bool helper(TreeNode<int>* root ,int &k , int &val){
    if(not root) return false ;
    if(helper(root->right , k , val)){
        return true ;
    }
    k-- ;       
    if(k == 0){
        val = root->data ;
        return true ;
    }
    return helper(root->left , k , val);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int count = 0 ;
    int val = -1 ;
    helper(root , k , val);
    return val ;
}
```

80. [two sum bst](https://www.codingninjas.com/codestudio/problems/pair-sum-in-bst_920493?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
bool helper(BinaryTreeNode<int> *root , int t , unordered_set<int> &memo){
    if(not root) return false ;
    if(memo.find(t-root->data) != memo.end()){
        return true ;
    }
    memo.insert(root->data) ;
    return helper(root->left , t , memo) or helper(root->right , t , memo);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_set<int> memo ;
    return helper(root , k , memo);
}
```

90. [bt to dll(https://www.codingninjas.com/codestudio/problems/convert-a-given-binary-tree-to-doubly-linked-list_893106?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
BinaryTreeNode<int>* preve ;

void helper(BinaryTreeNode<int>* root , BinaryTreeNode<int>* &head){
    if(not root) return ;
    helper(root->left , head);
    if(preve == NULL){
        head = root ;
    }
    else{
        preve->right = root ;
        root->left = preve ;
    }
    preve = root ;
    helper(root->right , head);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* head ;
    preve = NULL ;
    helper(root , head);
    return head ;
}
```

91. [median of streams](https://www.codingninjas.com/codestudio/problems/convert-a-given-binary-tree-to-doubly-linked-list_893106?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
    vector<int> res ;
    priority_queue<int> maxh ;
    priority_queue<int , vector<int> , greater<int> > minh ;
    for(int i = 0 ; i < n ; i++){
        maxh.push(arr[i]) ;
        if(maxh.size()-1 > minh.size()){
            minh.push(maxh.top()) ; maxh.pop() ;
        }
        if(not minh.empty() and maxh.top() > minh.top()){
            int ele = minh.top() ; minh.pop() ;
            minh.push(maxh.top()) ; maxh.pop() ;
            maxh.push(ele) ;
        }
        
        if((i&1) == 1){
            res.push_back((maxh.top() + minh.top())/2) ;
        }
        else{
            res.push_back(maxh.top());
        }
    }
    return res ;
}
```

92. [kth largest element in stream](https://www.codingninjas.com/codestudio/problems/convert-a-given-binary-tree-to-doubly-linked-list_893106?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
class Kthlargest {
public:
    priority_queue<int , vector<int> , greater<int>> pq ;
    int K ;
    Kthlargest(int k, vector<int> &arr) {
        K = k ;
        for(int ele : arr){
            pq.push(ele);
            if(pq.size() > k) pq.pop() ;
        }
    }
    void add(int ele) {
        pq.push(ele);
        if(pq.size() > K) pq.pop() ;
    }

    int getKthLargest() {
        return pq.top() ;
    }

};
```

93. [count distinct ele in k size window](https://www.codingninjas.com/codestudio/problems/count-distinct-element-in-every-k-size-window_920336?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    unordered_map<int,int> memo ;
    for(int i = 0 ; i < k ; i++){
        memo[arr[i]]++ ;
    }
    int right = k , left = 0 ;
    vector<int> res ;
    res.push_back(memo.size());
    
    while(right < arr.size()){
        memo[arr[right++]]++ ;
        memo[arr[left++]]-- ;
        if(memo[arr[left-1]] == 0){
            memo.erase(arr[left-1]);
        }
        res.push_back(memo.size());
    }
    return res ;
}

```

94. [kth largest element](https://www.codingninjas.com/codestudio/problems/kth-largest-element-in-the-unsorted-array_893030?topList=striver-sde-sheet-problems&leftPanelTab=1)
```cpp
int quickSelect(vector<int>& arr ,int left , int right ,int k){
    int ele = arr[right] ;
    int ptr = left ; 
    int idx = left ;
    while(idx < right){
        if(arr[idx] < ele){
            swap(arr[idx] , arr[ptr]) ;
            ptr++ ;
        }
        idx++ ;
    }
    swap(arr[ptr] , arr[right]) ;
    if(arr.size()-k == ptr){
        return ele ;
    }
    if(arr.size()-k > ptr){
        return quickSelect(arr , ptr+1 , right , k);
    }
    return quickSelect(arr , left , ptr-1 , k);
}
int kthLargest(vector<int>& arr, int size, int K)
{
    return quickSelect(arr , 0 , size-1 , K);
}
```

95. [Bfs ](https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=striver-sde-sheet-problems&leftPanelTab=0)
```cpp
#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<bool> visited(vertex , false);
    vector<vector<int>> graph(vertex) ;
    for(pair<int,int> &e : edges){
        graph[e.first].push_back(e.second) ;
        graph[e.second].push_back(e.first) ;
    } 
    for(int i = 0 ; i < vertex ; i++){
        sort(graph[i].begin() , graph[i].end()); 
        
    }
    vector<int> res ;
    queue<int> q ;
    for(int i = 0 ; i < vertex ; i++){
        if(visited[i]) continue ;
        q.push(i) ;
        visited[i] = true ;

        while(not q.empty()){
            int sz = q.size() ;
            while(sz--){
                int curr = q.front() ; q.pop() ;
                res.push_back(curr) ;
                for(int neigh : graph[curr]){
                    if(visited[neigh]) continue ;
                    visited[neigh] = true ;
                    q.push(neigh) ;
                }
            }
            
        }
    }
    return res ;
}
```
96. []()
```cpp
```