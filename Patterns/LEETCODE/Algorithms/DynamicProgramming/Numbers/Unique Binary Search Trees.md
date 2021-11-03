### [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/) <br>

Given an integer `n`, return the number of structurally unique **BST**'s (binary search trees) which has exactly `n` nodes of unique values from `1` to `n`.


#### Example 1:
<img src="../../../../../images/uniquebstn3.jpg">

```
Input: n = 3
Output: 5

```

#### Example 2:

```
Input: n = 1
Output: 1

```

# Solutions

### Python
```
class Solution:
    def numTrees(self, n: int) -> int:
        '''        
        if i=root
        left  = i-1
        right = n-i 
        
        '''
        numTree=[0]*(n+1)
        numTree[0]=1
        numTree[1]=1
        
        for total_nodes in range(2, n+1): # increasing total nodes and calculate each number separately
            total=0
            for root in range(1, total_nodes+1):
                left=numTree[root-1]
                right=numTree[total_nodes-root]
                total += (left * right)
                
            numTree[total_nodes]=total
            
        return numTree[n]
```
