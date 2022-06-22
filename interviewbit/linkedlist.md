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