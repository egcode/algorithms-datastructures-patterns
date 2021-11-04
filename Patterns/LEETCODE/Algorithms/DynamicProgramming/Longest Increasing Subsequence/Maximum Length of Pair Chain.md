### [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/) <br>

You are given an array of `n` pairs `pairs` where $pairs[i]$ = [$left_i$, $right_i$] and $left_i$ < $right_i$.

A pair `p2 = [c, d]` **follows** a pair `p1 = [a, b]` if `b < c`. A **chain** of pairs can be formed in this fashion.

Return the **length longest chain which can be formed**.

You do not need to use up all the given intervals. You can select pairs in any order.



#### Example 1:

```
Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].

```

#### Example 2:

```
Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].

```

# Solutions

### Python
```
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        '''
        Longest increasing subsequence
        '''
        pairs.sort(key=lambda x:x[0])
        n=len(pairs)
        dp=[1 for _ in range(n)]

        for i in range(1, n):
            for j in range(i):
                r1=pairs[j]
                r2=pairs[i]
                if r1[1]<r2[0]:
                    dp[i]=max(dp[i], dp[j]+1)
        return dp[-1]

```
