# Linked List


### Practise
1. [reverse-ll](https://www.interviewbit.com/problems/reverse-linked-list/)
```cpp
ListNode* Solution::reverseList(ListNode* A) {
    ListNode* prev = NULL , *curr = A , *next = A->next ;
    
    while(curr){
        curr->next = prev ;
        prev = curr ;
        curr = next ;
        if(curr){
            next = curr->next ;
        }
    }
    return prev ;
}
```

2.  [intersection-ll](https://www.interviewbit.com/problems/intersection-of-linked-lists/)
```cpp
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    unordered_set<ListNode *> memo ;
    while(A){
        memo.insert(A) ;
        A = A->next ;
    }
    
    while(B){
        if(memo.find(B) != memo.end()){
            return B ;
        }
        B = B->next ;
    }  
    return NULL ;
}
```

## Sort 

1. [sort-ll](https://www.interviewbit.com/problems/sort-binary-linked-list/)
```cpp
ListNode* Solution::solve(ListNode* A) {
    ListNode* ptr1 = A , *ptr2 = A ;
    
    while(ptr2){
        if(ptr2->val == 1){
            ptr2 = ptr2->next ;
        }
        else{
            swap(ptr1->val,ptr2->val);      
            ptr1 = ptr1->next ;
            ptr2 = ptr2->next ;
        }
    }
    return A ; 
}
```

2. [partition-list](https://www.interviewbit.com/problems/partition-list/)
```cpp
ListNode* Solution::partition(ListNode* A, int B) {
    vector<int> lesser , greater ;
    ListNode* temp = A , *ptr1 = NULL , *ptr2 = NULL , *start2 = NULL, *start1 = NULL ;
    
    while(temp){
        if(temp->val < B){
           if(not ptr1){
               ptr1 = temp ;
               start1 = temp ;
           }
           else{
               ptr1->next = temp ;
               ptr1 = temp ;
           }
        }
        else{
            if(not ptr2){
               ptr2 = temp ;
               start2 = temp ;
            }
            else{
                ptr2->next = temp ;
                ptr2 = temp ;
            }
        }     
        temp = temp->next ;   
    }
    if(not start1){
        return start2 ;
    }
    ptr1->next = start2 ;
    if(ptr2)
        ptr2->next = NULL ;
    
    return start1 ;
}
```

3. [sort-list](https://www.interviewbit.com/problems/insertion-sort-list/)
```cpp
ListNode* findNode(ListNode *ptr , ListNode *head){
    ListNode* prev = head;
    while(head and head->val <= ptr->val){
        prev = head ;
        head = head->next ;
    }
    
    return prev ;
}

ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* head = new ListNode(INT_MIN) ;
    head->next = A ;
    ListNode* ptr1 = A->next ;
    ListNode* prev = A ;
    
    while(ptr1){
        if(ptr1->val >= prev->val){
            prev = ptr1 ;
            ptr1 = ptr1->next ;
        }
        else{
            // find a node whose value is lesser or equal to cur value
            ListNode *temp_prev = findNode(ptr1 , head);
            ListNode *temp = temp_prev->next ;
            
            temp_prev->next = ptr1 ;
            ListNode* nxt = ptr1->next ;
            ptr1->next = temp ;
            
            prev->next = nxt ;
            ptr1 = nxt ;
        }
    }
    return head->next ;
}
```
4. [sort-list](https://www.interviewbit.com/problems/sort-list/)
```cpp
ListNode* getMid(ListNode* head){
    ListNode* slow = head , *fast = head->next ;
    while(fast and fast->next){
        slow = slow->next ; 
        fast = fast->next->next ;
    }
    return slow  ;
}

ListNode* merge(ListNode *ptr1 , ListNode *ptr2){
    ListNode* head = new ListNode(0);
    ListNode* pt = head ;
    while(ptr1 and ptr2){
        if(ptr1->val <= ptr2->val){
            pt->next = ptr1 ;
            pt = ptr1 ;
            ptr1 = ptr1->next ;
        }
        else{
            pt->next = ptr2 ;
            pt = ptr2 ;
            ptr2 = ptr2->next ;
        }
    }
    while(ptr1){
        pt->next = ptr1 ;
        pt = ptr1 ;
        ptr1 = ptr1->next ;
    }
    while(ptr2){
        pt->next = ptr2 ;
        pt = ptr2 ;
        ptr2 = ptr2->next ;
    }
    pt->next = NULL ;
    
    return head->next ;
}
ListNode* Solution::sortList(ListNode* head) {
    if(not head or not head->next){
        return head ;
    }
    ListNode* mid = getMid(head);
    ListNode* right = mid->next ;
    mid->next = NULL ;
    head = sortList(head);
    right = sortList(right);
    head = merge(head , right);
    return head ;
}
```

### List math

1. [add-two-numbers](https://www.interviewbit.com/problems/add-two-numbers-as-lists/)
```cpp
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    if(not A){
        return B ;
    }
    
    ListNode* ptr1 = A , *ptr2 = B ;
    int carry = 0 ;
    int cursum ;
    
    ListNode* prev = A ;
    
    while(ptr1 and ptr2){
        cursum = ptr1->val + ptr2->val + carry ;
        
        carry = cursum/10 ;
        ptr1->val = cursum%10 ;
        
        prev = ptr1 ;    
        ptr1 = ptr1->next ;
        ptr2 = ptr2->next ;    
    
    }
    while(ptr1){
        cursum = ptr1->val + carry ;
       
        carry = cursum/10 ;
        ptr1->val = cursum%10 ;
        prev = ptr1 ;
        ptr1 = ptr1->next ;
    }
    
    while(ptr2){
        cursum = ptr2->val + carry ;
        carry = cursum/10 ;
        prev->next = new ListNode(cursum%10);
        prev = prev->next ;
        
        ptr2 = ptr2->next ;    
    }
    if(carry){
        prev->next = new ListNode(carry);
    }
    
    return A ;
}
```

2. [detect-cycle](https://www.interviewbit.com/problems/list-cycle/)
```cpp
ListNode* Solution::detectCycle(ListNode* A) {
    if(not A or not A->next){
        return NULL ;
    }
    
    ListNode* slow = A , *fast = A;
    
    do{
        slow = slow->next ;
        fast = fast->next->next ;
    }while(fast and fast->next and fast != slow);
    
    if(not fast or not fast->next){
        return NULL ;
    }
    fast = A ;
    while(fast != slow){
        fast = fast->next ;
        slow = slow->next ;
    }

    return fast ;
}
```

### List trick

1. [kth-node-from-middle](https://www.interviewbit.com/problems/kth-node-from-middle/)
```cpp
ListNode* getMid(ListNode *head , vector<ListNode *> &arr){
    ListNode* fast = head ;
    arr.push_back(head);
    
    while(fast and fast->next){
        head = head->next;
        arr.push_back(head) ;
        fast = fast->next->next ;
    }
    return head ;
}

int Solution::solve(ListNode* head, int B) {
    vector<ListNode* > arr ;

    ListNode* mid = getMid(head , arr);
    
    if(arr.size() < B+1){
        return -1 ;
    }
    return arr[arr.size()-B-1]->val ;
}
```

2. [Reverse-alternative-k-nodes](https://www.interviewbit.com/problems/reverse-alternate-k-nodes/)
```cpp
pair<ListNode* ,ListNode*> reverseNode(ListNode* head , int count){
    ListNode* prev = NULL , *nxt = head->next;
    while(head and count--){
        head->next = prev ;
        prev = head ;
        head = nxt ;
        if(nxt){
            nxt = head->next ;
        }
    }
    return {prev , head} ;
}

ListNode* Solution::solve(ListNode* A, int B) {
    ListNode* head = new ListNode(0);
    head->next = A ;
    ListNode* ptr = A ;
    ListNode* prev = head ;
    
    while(ptr){
        pair<ListNode* , ListNode*> t = reverseNode(ptr , B);
        prev->next = t.first ; ptr->next = t.second ;
         
        ptr = ptr->next ;
        int count = B ;
        
        while(ptr and count--){
            prev = ptr ;
            ptr = ptr->next ;
        }
    }
    return head->next ;
}
```

3. [reverse-ll-2](https://www.interviewbit.com/problems/reverse-link-list-ii/)
```cpp
pair<ListNode* , ListNode* > reverse(ListNode *head , int count){
    ListNode* prev = NULL , *nxt = NULL ;
    while(head and count--){
        nxt = head->next ;
        head->next = prev ;
        prev = head ;
        head = nxt ;
        if(nxt){
            nxt = nxt->next ;
        }
    }
    return {prev , head}; 
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    int count = 1 ;
    ListNode* head = new ListNode(0); head->next = A ;
    
    ListNode* prev = head , *ptr = A ;
    
    while(count < B){
        count++ ;
        prev = ptr ;
        ptr = ptr->next ;
    }
    
    // reverse the part 
    pair<ListNode* , ListNode*> t = reverse(ptr , C-B+1);
    prev->next = t.first ;
    ptr->next = t.second ;
    return head->next ;
}
```

4. [reorder-list](https://www.interviewbit.com/problems/reorder-list/)
```cpp
ListNode* Solution::reorderList(ListNode* A) {
    vector<ListNode *> arr ;
    ListNode* temp = A ;
    while(temp){
        arr.push_back(temp);
        temp = temp->next ;
    }
    int left = 0 , right = arr.size()-1 ;
    ListNode* head = new ListNode(0);
    ListNode* ptr = head ;
    
    while(left <= right){
        if(left == right){
            ptr->next = arr[left];
            left++ ;
            ptr->next->next = NULL ;
        }    
        else{
            ptr->next = arr[left++] ;
            ptr = ptr->next ;
            ptr->next = arr[right--] ;
            ptr = ptr->next ;
            ptr->next = NULL ;
        }
    } 
    return head->next ;
}
```

### List 2 pointer

1. [palindrome-list](https://www.interviewbit.com/problems/palindrome-list/)
```cpp
ListNode* Solution::reorderList(ListNode* A) {
    vector<ListNode *> arr ;
    ListNode* temp = A ;
    while(temp){
        arr.push_back(temp);
        temp = temp->next ;
    }
    int left = 0 , right = arr.size()-1 ;
    ListNode* head = new ListNode(0);
    ListNode* ptr = head ;
    
    while(left <= right){
        if(left == right){
            ptr->next = arr[left];
            left++ ;
            ptr->next->next = NULL ;
        }    
        else{
            ptr->next = arr[left++] ;
            ptr = ptr->next ;
            ptr->next = arr[right--] ;
            ptr = ptr->next ;
            ptr->next = NULL ;
        }
    } 
    return head->next ;
}
```

2. [remove-dup-2](https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/)
```cpp
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* head = new ListNode(0);
    
    ListNode* ptr1 = A , *prev = head ;
    ListNode* mover = A ;
    int prev_val = INT_MIN ;
    
    while(mover){
        if(mover->val != prev_val){
           if(not mover->next or (mover->next->val != mover->val)){
               prev->next = mover ;
               prev = mover ;
           }
        }
        prev_val = mover->val ;
        mover = mover->next ;
    }
    if(prev)
        prev->next = NULL ;
    
    return head->next ;
}
```

3. [merge-list](https://www.interviewbit.com/problems/merge-two-sorted-lists/)
```cpp
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* head = new ListNode(0);
    ListNode* prev = head ;
    while(A and B){
        if(A->val <= B->val){
            prev->next = A ;
            prev = A ;
            A = A->next ;
        }
        else{
            prev->next = B ;
            prev = B ;
            B = B->next ;
        }
    }
    while(A){
        prev->next = A ;
        prev = A ;
        A = A->next ;
    }
    while(B){
        prev->next = B ;
        prev = B ;
        B = B->next ;
    }
    
    prev->next = NULL ;
    return head->next ;
}
```

4. [remove-dup](https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/)
```cpp
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* ptr = A , *mover = A->next ;
    int prev_val = A->val ;
    
    while(mover){
        if(mover->val != prev_val){
            ptr->next = mover ;
            ptr = mover ;
            prev_val = mover->val ;
        }
        mover = mover->next ;
    } 
    
    ptr->next = NULL ;
    return A ;
}
```

5. [remove-nth-node](https://www.interviewbit.com/problems/remove-nth-node-from-list-end/)
```cpp
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(B <= 0){
        return A ;
    }
    
    int len = 0 ;
    ListNode* temp = A ;
    while(temp){
        temp = temp->next ;
        len++ ;
    }
    len = len-B ;
    temp = A ;
    if(len <= 0){
        return A->next ;
    }
    ListNode* prev = A ;
    
    while(temp and len--){
        prev = temp ;
        temp = temp->next ;    
    }
    
    prev->next = temp->next ;
    return A ;
}
```