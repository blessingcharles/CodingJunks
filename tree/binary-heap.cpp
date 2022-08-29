#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

class MinHeap{
public:
    vector<int> arr ;
    int size ;
    MinHeap(){
        size = 0;
    }
    int get_parent(int i){
        return (i-1)/2 ;
    }
    bool isEmpty(){
        return size == 0 ;
    }
    int leftchild(int i){
        return(2*i)+1 ;
    }
    int rightchild(int i){
        return (2*i)+2 ;
    }
    void push(int val){
        arr.push_back(val);
        size++ ;
        int curr = size-1 ;
        
        while(curr != 0 and arr[get_parent(curr)] > arr[curr]){
            swap(arr[get_parent(curr)] , arr[curr]);
            curr = get_parent(curr);
        }
    }
    void heapify(int curr){
        // the method assumes all the subtrees are already heapified
        int left = leftchild(curr);
        int right = rightchild(curr);

        int smallest = curr ;
        if(left < size and arr[left] < arr[smallest]){
            smallest = left ;
        }
        if(right < size and arr[right] < arr[smallest]){
            smallest = right ;
        }
        if(smallest != curr){
            swap(arr[smallest] , arr[curr]);
            heapify(smallest);
        }
    }

    int pop(){
        if(isEmpty())
            return -1 ;
            
        int val = arr[0] ;
        arr[0] = arr.back() ;
        arr.pop_back(); size-- ;
        heapify(0);
        return val ;
    }

};

int main(){
    MinHeap *pq = new MinHeap();

    pq->push(5);
    pq->push(15);
    pq->push(2);
    pq->push(32);

    cout << pq->pop() << " " ;
    cout << pq->pop() << " " ;
    cout << pq->pop() << " " ;
    cout << pq->pop() << " " ;

}