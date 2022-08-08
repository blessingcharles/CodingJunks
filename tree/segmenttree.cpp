#include<iostream>
#include<bits/stdc++.h>
using namespace std ;

class SegmentTree{
public:
    // range of sum
    vector<int> tree ;
    vector<int> arr ;
    int N ;
    
    SegmentTree(vector<int> &arr){
        this->arr = arr ;
        N = arr.size() ;
        int x = (int)(ceil(log2(N)));
 
        //Maximum size of segment tree
        int max_size = 2*(int)pow(2, x) - 1 ; 

        tree.resize(max_size , 0);
        constructTree(0,N-1,0);
    }
    int constructTree(int ss , int se , int cur_node){
        if(ss == se){
            return tree[cur_node] = arr[ss] ;
        }
        int mid = getmid(ss,se);

        return tree[cur_node] = constructTree(ss , mid , 2*cur_node+1) + constructTree(mid+1 , se , 2*cur_node+2);
    }
    
    int pointUpdate(int ss , int se , int idx , int val , int curnode){
        if(idx < ss or idx > se or ss > se) return 0 ;
        
        if(ss == se){
            return tree[curnode] = val ;
        }
        
        int mid = getmid(ss , se) ;
        
        if(idx <= mid)
            pointUpdate(ss , mid  , idx , val , 2*curnode+1) ;
        else
            pointUpdate(mid+1 ,se , idx , val , 2*curnode+2) ;
        
        return tree[curnode] = tree[2*curnode+1] + tree[2*curnode+2] ;
    }

    int query(int qs , int qe , int ss , int se , int cur_node){
        if(ss > qe or se < qs)
            return 0 ;

        if(ss >= qs and se <= qe)
            return tree[cur_node] ;

        int mid = getmid(ss , se);

        return query(qs , qe , ss , mid , 2*cur_node+1) + query(qs , qe , mid+1 , se , 2*cur_node+2);
    }

    int getmid(int start , int end){
        return start + (end-start)/2 ;
    }
};
int main(){

    vector<int> arr = {1, 3, 5, 7, 9, 11} ;

    SegmentTree *st = new SegmentTree(arr);
    cout << st->query(1,5,0,5,0);

    return 0 ;
}