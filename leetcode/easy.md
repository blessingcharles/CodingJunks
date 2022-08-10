1. [single number](https://leetcode.com/problems/single-number/)
```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_val = 0 ;
        for(int ele : nums){
            xor_val = xor_val ^ ele ;
        }
        return xor_val ;
    }
};
```

2. [Excel colum sheet](https://leetcode.com/problems/excel-sheet-column-title/)
```cpp
class Solution {
public:
    string convertToTitle(int col) {
        string res = "" ;

        while(col){
            col -= 1 ;
            int rem = col%26 ;
            res.push_back('A'+rem) ;
            col = col/26 ;
        }
        
        reverse(res.begin() , res.end());
        return res ;
    }
};
```

3. [Excel sheet number](https://leetcode.com/problems/excel-sheet-column-number/)
```cpp
class Solution {
public:
    int titleToNumber(string col) {
        long long mult = 1 ;
        int res = 0 ;
        
        
        for(int i = col.size()-1 ; i >= 0 ; i-- , mult = mult*26){
            int cc = (col[i] - 'A')+1 ;
            res = res + cc*mult ;
            
        }
        return res ;
    }
};
```
4. [reverse bits](https://leetcode.com/problems/reverse-bits/)
```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0 ;
        
        int ptr1 = 0 , ptr2 = 31 ;
        while(ptr1 < 32){
            bool is_set = n&(1<<ptr1) ;
            if(is_set){
                res = res | (1<<ptr2) ;
            }
            ptr1++ ;
            ptr2-- ;
        }
        
        return res ;
    }
};
```

5. []()
```cpp

```