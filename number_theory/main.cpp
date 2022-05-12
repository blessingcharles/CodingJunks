#include<iostream>
#include<bits/stdc++.h>

using namespace std ;


void seive_of_erasthonis(int n){
    vector<int> seive(n+1 , 1);

    for(int i = 2 ; i <= n ; i++){
        if(seive[i]){
            cout << i << " " ;
            for(int j = i*i ; j <= n ; j = j+i){
                seive[j] = 0 ;
            }
        }
    }
}

int main(){
    seive_of_erasthonis(100);
    
}