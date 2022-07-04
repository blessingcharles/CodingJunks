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

2. 