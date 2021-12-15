### [Combinations](https://leetcode.com/problems/combinations/) <br>

Given two integers `n` and `k`, return *all possible combinations of `k` numbers out of the range `[1, n]`*.

You may return the answer in **any order**.


#### Example 1:

```
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

```

#### Example 2:

```
Input: n = 1, k = 1
Output: [[1]]

```


# Solutions

### Python
```
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        '''
        Similar as 46.Permutations but first should be after current
        We just create nums array ourselves
        '''
        
        res=[]
        nums=[i+1 for i in range(n)]

        def dfs(path, first):
            if len(path)==k:
                res.append(path[:])
                return
            
            for i in range(first, len(nums)):
                dfs(path+[nums[i]], i+1) # first should be after current
            
        dfs([], 0)
        
        return res

```
