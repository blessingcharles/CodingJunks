## Graph Problems List 

#### DFS
1. [Minimum depth of binary tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
2. [Same Tree](https://leetcode.com/problems/same-tree/submissions/)
3. [Trie Dictionary](https://leetcode.com/problems/design-add-and-search-words-data-structure)
4. [Invert Tree](https://leetcode.com/problems/invert-binary-tree/)
5. [Kth Smallest Element](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
    *Inorder Traversal of a BST gives the elements in ascending order*
6. [LCA on BST](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/)
7. [LCA on BT](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) 
    ```
        Find path from root to p and q .
        iterate from last of p , and return if it is in q 
    ```
8. [House Robber 3](https://leetcode.com/problems/house-robber-iii/)
9. [Flatten Nested Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/)
10. [Lexicographical Number](https://leetcode.com/problems/lexicographical-numbers/)
11. [Evaluate Division](https://leetcode.com/problems/evaluate-division/)
    ```
        Create a adjacency List a --> {b , val} which implies a/b = val 
        To solve queries:
                a/c = a/b * b/c  so move from a-->b , b-->c return the value .
    ````
12. [Sum of left leaves](https://leetcode.com/problems/sum-of-left-leaves)
13. [BattleShips](https://leetcode.com/problems/battleships-in-a-board/submissions/)
14. [path Sum](https://leetcode.com/problems/path-sum-iii/)
    ```
        Its a combination of traversing tree + subarray sum equals to k

        arr     2 4 3  5 -3  2 -1  3 -4                 k = 5

        cum_sum 2 6 9 14 11 13 12 15 11

        subarray_count += memo[cum_sum - k] ;

        if cum_sum - k occurs previously , then from that place to here sum of k had occured .

    ```
15. [serialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst)
16. [Island Perimeter](https://leetcode.com/problems/island-perimeter/submissions/)
17. [Mode in BST](https://leetcode.com/problems/find-mode-in-binary-search-tree)
    ```
        Inorder traversal of BST to get ascending order and then find mode
    ```
18. [Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/)
19. [Find Bottom Left Value](https://leetcode.com/problems/find-bottom-left-tree-value/)
20. [Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/)
21. [Minimum Absolute difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst)
22. [Convert BST to greater Sum](https://leetcode.com/problems/convert-bst-to-greater-tree/submissions/)
23. [Diameter of BT](https://leetcode.com/problems/diameter-of-binary-tree/submissions/)
24. [Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)
25. [BT tilt sum](https://leetcode.com/problems/binary-tree-tilt)
26. [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree)
    ```
        isSameTree(root , subRoot) or isSubTree(root->left , subRoot) or isSubtree(root->right , subRoot);

    ```
27. [Array Nesting](https://leetcode.com/problems/array-nesting/)
28. [Construct String from binary Tree](https://leetcode.com/problems/construct-string-from-binary-tree/submissions/)
29. [Merge Two Binary Tree](https://leetcode.com/problems/merge-two-binary-trees/)
30. [Add one Row to Tree](https://leetcode.com/problems/add-one-row-to-tree/)
31. [Average Levels of BT](https://leetcode.com/problems/average-of-levels-in-binary-tree/submissions/)
32. [Duplicate Subtree](https://leetcode.com/problems/find-duplicate-subtrees/)
```
    generate all subtree and store it as string in memo , if it occurs twice append to result 
```
33. [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/)
34. [Maximum width of BT](https://leetcode.com/problems/maximum-width-of-binary-tree/)
```
    Use BFS and for each parent the child node is 
            left-child = pid*2
            right-child = pid*2+1 
```
35. [print BT](https://leetcode.com/problems/print-binary-tree/submissions/)
36. [Trim a BST](https://leetcode.com/problems/trim-a-binary-search-tree/)
37. [Second min in BT](https://leetcode.com/problems/second-minimum-node-in-a-binary-tree)
38. [Longest Unique Value Paths](https://leetcode.com/problems/longest-univalue-path/)
39. [longest Univalue Path](https://leetcode.com/problems/longest-univalue-path/)
40. [Employee Importance](https://leetcode.com/problems/employee-importance)
41. //  [Couples Holding Hands](https://leetcode.com/problems/couples-holding-hands/)
42. [Binary Tree Prunning](https://leetcode.com/problems/binary-tree-pruning)
43. [All paths from src to target](https://leetcode.com/problems/all-paths-from-source-to-target/)
44. [Loud and Rich](https://leetcode.com/problems/loud-and-rich/submissions/)
45. [All Nodes distance k in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)
```
    1. Store each element parent for going up
    2. start exploring from the target
        - move to left child if present
        - move to right child if present
        - move to parent if present
```
46. [Smallest Subtree with all the Deepest Nodes](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/)
    ```
        Find the start node and end node of the deepest level .
        Perform LCA(start , end) .
    ```

47. [Leaf Similar Trees](https://leetcode.com/problems/leaf-similar-trees/submissions/)
48. [possible bipartition](https://leetcode.com/problems/possible-bipartition/submissions/)
49. [Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/)
50. [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)
51. [Flip Equivalent BT](https://leetcode.com/problems/flip-equivalent-binary-trees/submissions/)
52. [Univalued Binary Tree](https://leetcode.com/problems/univalued-binary-tree/)
53. [Flip BT to match pot](https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/)


#### BFS
1. [Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/)
2. [Zig Zag traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
3. [Level order Traversal 2](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
4. [Word Ladder](https://leetcode.com/problems/word-ladder/)
```
    Insert the beginWord into queue    
        Loop each level seperately untill queue empty
            - pick a word from queue and remove it from bucket and queue
            - break if word == endWord
            - insert all its neighbour into the queue
```
5. // [Word Ladder 2](https://leetcode.com/problems/word-ladder-ii/)
6. [Remove invalid Parenthesis](https://leetcode.com/problems/remove-invalid-parentheses/submissions/)
```
    Try to find parenthesis combination with few optimization if checks
```
7. [longest increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)
8. [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation/)
9. [Open the Lock](https://leetcode.com/problems/open-the-lock/)
10. [Min distance between BST nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)
11. [Bus routes](https://leetcode.com/problems/bus-routes/)
```
    Make a Adj List like [from cur_stop what are the next possible routes]
    Perform Bfs:
        from current_stop what are the possible routes available
        add to it , if its not visited

```
12. [Making a Larger Island](https://leetcode.com/problems/making-a-large-island/)
```
    Perform bfs on each 1 to color each island with unique color and store its size
    Again Iterate
            if grid[i][j] == 0:
                join the unique island to produce larger island 
```
13. [Sliding Puzzle](https://leetcode.com/problems/sliding-puzzle/)
```
    Convert the board configuration to string .
    Do BFS and explore all possible ways to move to success
```
14. [Snakes and Ladders](https://leetcode.com/problems/snakes-and-ladders/)
```
    From a given pos explore the next 6 neighbours and add it to the queue ,
    Increase the depth for each level 
```
15. [Serialize and Deserialize BT](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
16. [Completeness of BT](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)
17. [Shortest path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)
18. [Shortest path visiting All nodes](https://leetcode.com/problems/shortest-path-visiting-all-nodes/)
19. [Cousins of BT](https://leetcode.com/problems/cousins-in-binary-tree/)
20. [Coloring a Border](https://leetcode.com/problems/coloring-a-border/)
21. [LCA of Deepest leaves](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/)
22. [Maximum sum of BT](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)
23. [Shortest Path Alternating Colors](https://leetcode.com/problems/shortest-path-with-alternating-colors/)
24. [Count Servers that Communicate](https://leetcode.com/problems/count-servers-that-communicate/)
25.  
