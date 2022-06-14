bool isPossible(vector<int>& packages,  int days , int weight){
    int required_days = 1 , cur_sum = 0 ;
    
    for(int i = 0 ; i < packages.size() ; i++){
        if(cur_sum + packages[i] > weight){
            required_days++ ;
            if(required_days > days){
                return false ;
            }
            cur_sum = packages[i] ;
        }
        else{
            cur_sum += packages[i] ;
        }
    }
    return true ;
}

int Solution::solve(vector<int> &A, int B) {
    lon left = *max_element(A.begin() , A.end());
    int right = accumulate(A.begin() , A.end() , 0);
    int mid ;
    
    while(left < right){
        mid = left + (right - left)/2 ;
        if(not isPossible(A , B , mid)){
            left = mid+1 ;
        }
        else{
            right = mid ;
        }
    }
    return right ;
}
