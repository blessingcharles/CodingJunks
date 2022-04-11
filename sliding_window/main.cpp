#include<iostream>
#include<bits/stdc++.h>

using namespace std ;



template<typename T>
void print2d(vector<vector<T>> &mat){
    for(int i = 0 ; i < mat.size() ; i++){
        for(int j = 0 ; j < mat[0].size() ; j++)
            cout << mat[i][j] << " " ;

        cout << endl ;
    }
}
vector<vector<int>> calc_2dPrefixSum(vector<vector<int>> &mat){

    int m = mat.size() , n = mat[0].size() ;

    vector<vector<int>> psum(m+1 , vector<int>(n+1 , 0));

    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1]+mat[i-1][j-1] ;
        }
    }
    // print2d(psum);
    return psum ;
}

int squareSum(vector<vector<int>>& prefixSum, int x1, int y1, int x2, int y2) {
        return prefixSum[x2][y2] - prefixSum[x1][y2] - prefixSum[x2][y1] + prefixSum[x1][y1];
}


int main(int argc , char **argv){

    vector<int> arr = {4,8,13,20,23} ;

    auto it = upper_bound(arr.begin() , arr.end() , stoi(argv[1]));

    cout << it - arr.begin() << endl ;

    return 0 ;
}