### [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) <br>

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



#### Example 1:

```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

```

#### Example 2:

```
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

```



# Solutions

### Python
```
class Solution:
    
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res=[]
        candidates.sort()
        def dfs(path, summ, first):
            nonlocal res
            if summ > target:
                return 
            if summ==target:
                res.append(path[:])
                return
            
            for i in range(first,  len(candidates)):
                # since array is sorted we could have duplicates like in [1,1,2,5,6,7,10]
                # here we need to skip all ones, because they should be used only once
                if i>first and candidates[i]==candidates[i-1]:
                    continue
                dfs(path+[candidates[i]] ,summ+candidates[i], i+1)
                
        dfs([], 0, 0)
        return res

```
