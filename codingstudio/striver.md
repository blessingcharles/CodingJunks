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