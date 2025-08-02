### [Combination Sum](https://leetcode.com/problems/combination-sum/) <br>

Given an array of **distinct** integers `candidates` and a target integer `target`, return a list of all **unique combinations** of `candidates` where the chosen numbers sum to `target`. You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is **guaranteed** that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.



#### Example 1:

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

```

#### Example 2:

```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

```

#### Example 3:

```
Input: candidates = [2], target = 1
Output: []

```

#### Example 4:

```
Input: candidates = [1], target = 1
Output: [[1]]

```

#### Example 5:

```
Input: candidates = [1], target = 2
Output: [[1,1]]

```

# Solutions

### Python
```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        '''
        Tabulation

        dp[i] stores all combinations that sum up to i.
        Ex:
        [2,3,6,7] target 7
        [[[]], [], [[2]], [[3]], [[2, 2]], [[2, 3]], [[2, 2, 2], [3, 3], [6]], [[2, 2, 3], [7]]]

        '''
        dp=[[] for _ in range(target+1)]
        dp[0]=[[]]
        
        ######################################################
        ## Generates [[3,2,2],[2,3,2],[2,2,3],[7]]
        ######################################################
        # for i in range(1, target+1):
        #     for cand in candidates:
        #         if i-cand >= 0:
        #             path=[]
        #             for a in dp[i-cand]:
        #                 path.append(a+[cand])
        #             dp[i] += path
        ######################################################
        
        ######################################################
        ## Generates[[2,2,3],[7]]
        ######################################################
        for cand in candidates:
            for i in range(cand, target+1):
                if i-cand >= 0:
                    path=[]
                    for a in dp[i-cand]:
                        path.append(a+[cand])
                    dp[i] += path
        ######################################################
        
        return dp[target]
    
        
#     def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
#         '''
#         Recursion
#         Note:            
#             If we remove `first` parameter here we will have all
#             [[3,2,2],[2,3,2],[2,2,3],[7]] arrays returned.
            
#             here we have only have [[3,2,2],[7]]  returned
#         '''
        
#         ######################################################
#         ## Generates [[3,2,2],[2,3,2],[2,2,3],[7]]
#         ######################################################
#         def dfs(target):
#             if target == 0:
#                 return [[]]
#             if target < 0:
#                 return []
#             paths=[]
#             for i in range(len(candidates)):
#                 cand=candidates[i]
#                 arr=dfs(target-cand)
#                 path=[]
#                 for a in arr:
#                     path.append(a+[cand])
#                 if path:
#                     paths += path
                    
#             return paths
#         res=dfs(target)
#         ######################################################


#         ######################################################
#         ## Generates[[2,2,3],[7]]
#         ######################################################
#         def dfs(target, first):
#             if target == 0:
#                 return [[]]
#             if target < 0:
#                 return []
#             paths=[]
#             for i in range(first, len(candidates)):
#                 cand=candidates[i]
#                 arr=dfs(target-cand, i)
#                 path=[]
#                 for a in arr:
#                     path.append(a+[cand])
#                 if path:
#                     paths += path
                    
#             return paths
#         res=dfs(target, 0)
#         ######################################################    
        
#         return res
        
    
    
#     def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
#         ans=[]
#         def backtrack(remain, cands, start):
#             if remain==target:
#                 ans.append(list(cands))
#                 return
#             if remain>target:
#                 return
            
#             for i in range(start, len(candidates)):
#                 cands.append(candidates[i])
#                 backtrack(remain+candidates[i], cands, i)
#                 cands.pop()
                
        
#         backtrack(0, [], 0)
        
#         return ans
```
