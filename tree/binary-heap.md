### Binary Heap 

- Full BT : If all levels are completely filled eg : for a bbt of height h there are 2^h - 1 nodes

- Complete BT : If level order traversal is represented in an array , there should be no gaps between in array .

            3
          /   \
         5     6
        / \
       8   9

    arr : 3 5 6 8 9 

    parent : (i-1)/2
    child1 : (2*i) + 1
    child2 : 2*i + 2

##### Heap
    Heap is a complete binary tree
- maxheap : A bt is a maxheap if any root is greater than all its descendents
- minheap : A bt is a minheap if any root is smaller than all its descendents


### Problems

1. [top-k-frequent](https://leetcode.com/problems/top-k-frequent-elements/)
2. [relative-raning](https://leetcode.com/problems/relative-ranks/)
3. [importance-of-roads](https://leetcode.com/problems/maximum-total-importance-of-roads/)
4. [max-product-after-k-incre](https://leetcode.com/problems/maximum-product-after-k-increments/)
5. [dig-swap-parity]9https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
6. [ugly-number-ii](https://leetcode.com/problems/ugly-number-ii/)
7. 