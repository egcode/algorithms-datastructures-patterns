### [Subsets](https://leetcode.com/problems/subsets/) <br>

Given an integer array `nums` of **unique** elements, return *all possible subsets (the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.



#### Example 1:

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

```

#### Example 2:

```
Input: nums = [0]
Output: [[],[0]]

```

# Solutions

### Python
```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res=[]
        def backtrack(first, path):
            res.append(path[:])
            for i in range(first, len(nums)):
                path.append(nums[i])
                backtrack(i+1, path) # first should be i+1 because it should not add duplicates
                path.pop()
                
                
        backtrack(0, [])
        return res

```
