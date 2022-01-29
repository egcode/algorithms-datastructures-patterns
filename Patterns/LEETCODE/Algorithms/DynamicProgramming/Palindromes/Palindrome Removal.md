### [Palindrome Removal](https://leetcode.com/problems/palindrome-removal/) <br>

Given an integer array `arr`, in one move you can select a **palindromic** subarray `arr[i], arr[i+1], ..., arr[j]` where `i <= j`, and remove that subarray from the given array. Note that after removing a subarray, the elements on the left and on the right of that subarray move to fill the gap left by the removal.

Return the minimum number of moves needed to remove all numbers from the array.

 



#### Example 1:

```
Input: arr = [1,2]
Output: 2

```

#### Example 2:

```
Input: arr = [1,3,4,1,5]
Output: 3
Explanation: Remove [4] then remove [1,3,1] then remove [5].

```



# Solutions

### Python
```
class Solution:
    def minimumMoves(self, arr: List[int]) -> int:
        '''
        Example: 
        arr = [1,3,4,1,5]
        
        Start with:        
            [5, 5, 5, 5, 5]
            [5, 5, 5, 5, 5]
            [5, 5, 5, 5, 5]
            [5, 5, 5, 5, 5]
            [5, 5, 5, 5, 5]
        End with:
               1  3  4  1  5
            1 [1, 2, 3, 2, 3]
            3 [5, 1, 2, 3, 4]
            4 [5, 5, 1, 2, 3]
            1 [5, 5, 5, 1, 2]
            5 [5, 5, 5, 5, 1]
        '''
        n=len(arr)
        dp=[[n]*n for _ in range(n)]
        for l in range(n-1,-1,-1):
            for r in range(l,n):
                if l==r:
                    dp[l][r]=1
                elif l+1==r:
                    dp[l][r]=2 # 12
                    if arr[l]==arr[r]:
                        dp[l][r]=1 # 11
                else:
                    dp[l][r]=min(dp[l][r],
                       dp[l+1][r-1] + (0 if arr[l]==arr[r] else 2),  # 12221, 12223
                       dp[l+1][r] + 1, # 23333
                       dp[l][r-1] + 1  # 22223
                       )

                    for k in range(l,r):
                        dp[l][r]=min(dp[l][r], dp[l][k]+dp[k+1][r]) # 2223333 
                                                
        return dp[0][-1]
```
