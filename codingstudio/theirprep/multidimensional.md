1. [symmetrix matrix](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111356/offering/1280158?leftPanelTab=0)
```cpp
bool isMatrixSymmetric(vector<vector<int>> matrix){
    int N = matrix.size() ;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(matrix[i][j] != matrix[j][i]) return false ; 
        }
    }
    return true ;
}
```

2. [search in sorted matrix]()
```cpp
pair<int, int> search(vector<vector<int>> matrix, int x)
{
    // Write your code here.
    for(int i = 0 ; i < matrix.size() ; i++){
            int left = 0 , right = matrix[0].size()-1 , mid ;
            while(left <= right){
                mid = left + (right - left)/2 ;
                if(matrix[i][mid] == x) return {i , mid};
                else if(matrix[i][mid] > x) right = mid-1 ;
                else left = mid+1 ;
            }
   }
   return {-1,-1};
}
```

3. [Right rotate matrix](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111356/offering/1280161?leftPanelTab=0)
```cpp
vector<int> rotateMatRight(vector<vector<int>> mat, int n, int m, int k) {
    int M = mat.size() , N = mat[0].size() , start_col ;
    k = k%N ;
    if(k == 0){
        start_col = 0;
    }
    else{
         start_col = N-k ;   
    }
    vector<int> res ;
    int r_col ;
    
    for(int row = 0 ;row < M ; row++){
        
        for(int i = 0 ; i < N ; i++){
            r_col = (start_col + i)%N ;
            res.push_back(mat[row][r_col]);
        }
    }
    return res ;
}
```

4.  [count flips](https://www.codingninjas.com/codestudio/guided-paths/interview-guide-for-product-based-companies/content/111356/offering/1280162?leftPanelTab=3)
```cpp
int countFlip(vector<vector<int>> &mat)
{
	bool first_col  = false ;
    int M = mat.size() , N = mat[0].size() ;
    int flip = 0 ;
    
    for(int row = 0 ; row < M ; row++){
        for(int col = 0 ; col < N ; col++){
            if(mat[row][col] == 0){
                if(col == 0){
                    first_col = true ;
                    continue ;
                }
                
                if(mat[row][0] == 1) flip++ ;
                if(mat[0][col] == 1) flip++ ;
                
                mat[row][0] = 0 ;
                mat[0][col] = 0 ;
            }
        }
    }
    
    for(int row = N-1 ; row >= 0 ; row--){
        for(int col = N-1 ; col >= 0 ; col--){
            if(mat[row][col] == 1){
                if(col == 0){
                    if(first_col){
                        flip++ ;
                        mat[row][col] = 0 ;
                    }
                }
                else{
                    if(mat[0][col] == 0 or mat[row][0] == 0){
                        flip++ ;
                        mat[row][col] = 0 ;
                    }
                }
            }
        }
    }
    return flip ;
    
}
```