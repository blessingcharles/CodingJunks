#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

#include <bits/stdc++.h> 
void sort012(vector<int> arr, int n)
{
    int ptr1 = 0 , ptr2 = 0 , ptr3 = n-1 ;
    
    while(ptr2 <= ptr3){
		cout << ptr2 << endl ;
        if(arr[ptr2] == 0){
            swap(arr[ptr1] , arr[ptr2]) ;
            ptr1++ ; ptr2++ ;
        }
        else if(arr[ptr2] == 2){
            swap(arr[ptr2] , arr[ptr3]);
            ptr3++ ;
        }
        else{
            ptr2++ ;
        }
    }
    
}
int main(){
	vector<int>arr = {0 ,1 ,2 ,2 ,1 ,0};
	sort012(arr , 6);
}