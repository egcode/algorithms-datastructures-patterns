### [Maximum Alternating Subsequence Sum](https://leetcode.com/problems/maximum-alternating-subsequence-sum/) <br>

The **alternating sum** of a **0-indexed** array is defined as the **sum** of the elements at **even** indices **minus** the **sum** of the elements at **odd** indices.

 - For example, the alternating sum of `[4,2,5,3]` is `(4 + 5) - (2 + 3) = 4`.
Given an array `nums`, return the **maximum alternating sum** of any subsequence of `nums` (after **reindexing** the elements of the subsequence).

A **subsequence** of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, `[2,7,4]` is a subsequence of `[4,2,3,7,2,1,4]` (the underlined elements), while `[2,4,2]` is not.



#### Example 1:

```
Input: nums = [4,2,5,3]
Output: 7
Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.

```

#### Example 2:

```
Input: nums = [5,6,7,8]
Output: 8
Explanation: It is optimal to choose the subsequence [8] with alternating sum 8.

```

#### Example 3:

```
Input: nums = [6,2,1,2,4,5]
Output: 10
Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.

```

# Solutions

### Python
```
class Solution:
    
    def maxAlternatingSum(self, nums: List[int]) -> int:
        sumEven=0
        sumOdd=0
        
        for i in range(len(nums))[::-1]:
            tmpEven=max(sumEven, sumOdd+nums[i])
            tmpOdd=max(sumOdd, sumEven-nums[i])
            
            sumEven=tmpEven
            sumOdd=tmpOdd
        
        return sumEven
    
    
#     def maxAlternatingSum(self, nums: List[int]) -> int:
#         memo={}
#         n=len(nums)
        
#         def dfs(index, even):            
#             if (index, even) in memo.keys():
#                 return memo[(index, even)]
            
#             if index==n:
#                 memo[(index, even)]=0
#                 return 0
            
#             current=nums[index]
            
#             # if even we allowed to add current value            
#             if even==False:
#                 current=-nums[index]
#             # print(memo)
            
#             withValue = current+dfs(index+1, not even) # using the value and changing the sign
#             withoutValue = dfs(index+1, even) # here we are skipping the value and not changin the sign
            
#             memo[(index, even)]=max(withValue, withoutValue)
#             return memo[(index, even)]
            
#         return dfs(0, True)
```
