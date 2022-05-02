### Strings

1. [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion)
2. [Integer to Roman](https://leetcode.com/problems/integer-to-roman/)
3. [Roman To Integer](https://leetcode.com/problems/roman-to-integer/)
4. [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)
5. [Plus One](https://leetcode.com/problems/plus-one/)
6. [word pattern](https://leetcode.com/problems/word-pattern/)
7. [longest substring containing even vowels](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)

[Make Strings equal]
1. [close strings](https://leetcode.com/problems/determine-if-two-strings-are-close/)
2. [min swaps to make equal 2 chars](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/)
3. [min swaps to make anagram](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)
4. 

[Count of substring based on Condition]

1. [wonderful substring](https://leetcode.com/problems/number-of-wonderful-substrings)
2. [beauty of substring](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/)

[check type of string]

1. [Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)
2. [valid anagram](https://leetcode.com/problems/valid-anagram)
3. [Additive number](https://leetcode.com/problems/additive-number/)
4. [buddy strings](https://leetcode.com/problems/buddy-strings/)
5. [longest happy prefix](https://leetcode.com/problems/longest-happy-prefix/)
6. [decreasing increasing string](https://leetcode.com/problems/increasing-decreasing-string/)
7. [can break another string](https://leetcode.com/problems/check-if-a-string-can-break-another-string/)

[Equivalent]
1. [string array equivalent](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/)
2. [summation of two words](https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/)
3. [one swap make string equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)

[Palindromes]
1. [partitioning](https://leetcode.com/problems/palindrome-partitioning)
2. [partitioning 2](https://leetcode.com/problems/palindrome-partitioning-ii/)
3. [partition 3](https://leetcode.com/problems/palindrome-partitioning-iii/)
4. [partition 4](https://leetcode.com/problems/palindrome-partitioning-iv/)


```c
bool isPalindrome(string &s , int start , int end){
    
    if(dp[start][end] != -1)
        return dp[start][end] ;
    
    while(start < end){
        if(s[start] != s[end])
            return dp[start][end] = false ;
        start++ ; end-- ;
    }
    return dp[start][end] = true ;
}

bool isPalindrome(string& s, int i, int j) {
	if (i >= j) return true;
	if (dp[i][j] != -1) return dp[i][j];
	if (s[i] == s[j]) return dp[i][j] = isPalindrome(s, i + 1, j - 1);
	return dp[i][j] = false;
}
```

