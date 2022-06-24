# HEAP 

1. [n-pair-combinations](https://www.interviewbit.com/problems/n-max-pair-combinations/)
6. [max-comb](https://www.interviewbit.com/problems/maximum-sum-combinations/)
```cpp
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    if(A.size() == 1){
        return {A[0]+B[0]} ;
    }
    
    priority_queue<pair<int , pair<int,int>>> pq ;
    set<pair<int,int>> st ;
    
    sort(A.begin() , A.end() , greater<int>());
    sort(B.begin() , B.end() , greater<int>());
    
    int N = A.size() ;
    vector<int> ans ;
    pq.push({A[0]+B[0] , {0,0}});
    st.insert({0,0,});
    pair<int,int> curr ;
    int K = A.size() ; 
    
    while(K--){
        int curr_sum = pq.top().first ; 
        curr = pq.top().second ; pq.pop() ;
        
        ans.push_back(curr_sum);
        
        //two possibilites (i+1 , j) and (i , j+1)
        int poss1_i = curr.first+1 , poss1_j = curr.second ;
        int poss2_i = curr.first , poss2_j = curr.second+1 ;
        
        if(poss1_i < N and poss1_j < N and st.find({poss1_i , poss1_j}) == st.end()){
        
            st.insert({poss1_i , poss1_j});
            pq.push({A[poss1_i] + B[poss1_j] , {poss1_i , poss1_j}});
        
        }
        
        if(poss2_i < N and poss2_j < N and st.find({poss2_i , poss2_j}) == st.end()){
         
            st.insert({poss2_i , poss2_j});
            pq.push({A[poss2_i] + B[poss2_j] , {poss2_i , poss2_j}});
        
        }
    }
    return ans ;
}
```

2. [k-largest](https://www.interviewbit.com/problems/k-largest-elements/)
```cpp
vector<int> Solution::solve(vector<int> &A, int B) {
    sort(A.begin() , A.end() , greater<int>());
    vector<int> ans(A.begin() , A.begin()+B);
    return ans ;
}
```

3. [profit-maximization](https://www.interviewbit.com/problems/profit-maximisation/)
```cpp
int Solution::solve(vector<int> &A, int B) {
    priority_queue<int> pq(A.begin() , A.end()) ;
    int maxprofit = 0 ;
    
    while(B--){
        int curticket = pq.top() ;
        maxprofit += curticket ;
        pq.pop() ;
        pq.push(curticket-1);    
    }
    return maxprofit ;
}
```

4. [merge-k-sorted-array](https://www.interviewbit.com/problems/merge-k-sorted-arrays/)
```cpp
vector<int> Solution::solve(vector<vector<int> > &A) {
    multiset<int> st ;
    
    for(int i = 0 ; i < A.size() ; i++){
        for(int j = 0 ; j < A[i].size() ; j++){
            st.insert(A[i][j]);
        }
    }
    
    return vector<int>(st.begin() , st.end());
}
```

5. [magician-chocalates](https://www.interviewbit.com/problems/magician-and-chocolates/)
```cpp
int Solution::nchoc(int A, vector<int> &B) {
    long long ans = 0 ;
    long long mod = 1e9+7 ;
    
    priority_queue<int> pq(B.begin() , B.end());
    int cur ;
    
    while(A--){
        cur = pq.top(); pq.pop() ;
        ans = (ans+cur)%mod ;   
        
        pq.push(floor(cur/2)); 
    }
    
    return ans%mod ;
}
```
6. [merge-k-sorted-list](https://www.interviewbit.com/problems/merge-k-sorted-lists/)
```cpp
 class MyComparator{
public:
     bool operator()(ListNode* const A , ListNode* const B){
         return A->val > B->val ;
     }
 };
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode* , vector<ListNode* > , MyComparator> pq ;
    
    for(ListNode* ele : A){
        pq.push(ele) ;
    }
    ListNode* head = new ListNode(0);
    ListNode* ptr = head ;
    while(not pq.empty()){
        ListNode* curr = pq.top() ; pq.pop() ;
        ptr->next = curr ;
        ptr = curr ;
        if(curr->next)
            pq.push(curr->next);
    }
    
    return head->next ;
}
```