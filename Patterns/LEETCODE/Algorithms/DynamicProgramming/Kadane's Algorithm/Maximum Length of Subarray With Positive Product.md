### [Maximum Length of Subarray With Positive Product](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/) <br>

Given an array of integers `nums`, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the **maximum length of a subarray with positive product**.



#### Example 1:

```
Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.

```

#### Example 2:

```
Input: nums = [0,1,-2,-3,-4]
Output: 3
Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.

```

#### Example 3:

```
Input: nums = [-1,-2,-3,0,1]
Output: 2
Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].

```
#### Example 4:

```
Input: nums = [-1,2]
Output: 1

```
#### Example 5:

```
Input: nums = [1,2,3,5,-6,4,0,10]
Output: 4

```
# Solutions

### Python
```
class Solution:
#     def getMaxLen(self, nums: List[int]) -> int:
#         '''
#         Kadane's Algorithm tricky variation.
#         - we count minuses, if minuses count is even we count all sequence
#         - we reset minuses and length if zero
#         '''
#         n=len(nums)
#         non_zero_len = 1 if nums[0] != 0 else 0
#         best_max1 = 1 if nums[0] > 0 else 0
#         minus_count = 1 if nums[0] < 0 else 0
        
#         for i in range(1, n):
#             minus_count += 1 if nums[i]<0 else 0
#             if nums[i]==0:
#                 non_zero_len=0
#                 minus_count=0
#             else:
#                 non_zero_len += 1
                
#             if nums[i]>0:
#                 best_max1=max(best_max1, 1)            
#             if minus_count%2==0:
#                 best_max1=max(best_max1, non_zero_len)

#         # Reverse  
#         non_zero_len = 1 if nums[-1] != 0 else 0
#         best_max2 = 1 if nums[-1] > 0 else 0
#         minus_count = 1 if nums[-1] < 0 else 0
        
#         for i in range(n-1)[::-1]:
#             minus_count += 1 if nums[i]<0 else 0
#             if nums[i]==0:
#                 non_zero_len=0
#                 minus_count=0
#             else:
#                 non_zero_len += 1
                
#             if nums[i]>0:
#                 best_max2=max(best_max2, 1)            
#             if minus_count%2==0:
#                 best_max2=max(best_max2, non_zero_len)
                
#         return max(best_max1, best_max2)
    
    
    
#     def getMaxLen(self, nums: List[int]) -> int:
#         '''
#         Kadane's Algorithm tricky variation.
#         - we count minuses, if minuses count is even we count all sequence
#         - we reset minuses and length if zero
#         '''
#         n=len(nums)
        
#         def handle(num):
#             nonlocal non_zero_len
#             nonlocal best_max
#             nonlocal minus_count
#             minus_count += 1 if num<0 else 0
#             if num==0:
#                 non_zero_len=0
#                 minus_count=0
#             else:
#                 non_zero_len += 1
                
#             if num>0:
#                 best_max=max(best_max, 1)            
#             if minus_count%2==0:
#                 best_max=max(best_max, non_zero_len)
        
        
#         ###### Looping Forward
#         non_zero_len = 1 if nums[0] != 0 else 0
#         best_max = 1 if nums[0] > 0 else 0
#         minus_count = 1 if nums[0] < 0 else 0
                
#         for i in range(1, n):
#             handle(nums[i])
#         res=[best_max]
                
            
#         ###### Looping Backward  
#         non_zero_len = 1 if nums[-1] != 0 else 0
#         best_max = 1 if nums[-1] > 0 else 0
#         minus_count = 1 if nums[-1] < 0 else 0
        
#         for i in range(n-1)[::-1]:
#             handle(nums[i])
#         res.append(best_max)
                
#         return max(res)
    
    
    def getMaxLen(self, nums):
        """
        Kadane's Algorithm tricky variation.
        https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/discuss/819432/Python-Easy-to-understand-DP
        """
        n = len(nums)
        dp = [[0] * 2 for _ in range(n)]   
        # dp[i][0] : max length of subarray ending with index i With positive product   
		# dp[i][1] : max length of subarray ending with index i With negative product 
		
        # Base case: when index is 0, only one number can be used
        if nums[0] > 0:
            dp[0][0] = 1
        
        if nums[0] < 0:
            dp[0][1] = 1
            
        res = dp[0][0]
        
        for i in range(1, n):
            cur = nums[i]
            
            if cur > 0:
                dp[i][0] = dp[i - 1][0] + 1
                if dp[i - 1][1] > 0: # if previous negative subarray exists
                    dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1)
            if cur < 0:
                dp[i][1] = dp[i - 1][0] + 1
                if dp[i - 1][1] > 0: # if previous negative subarray exists
                    dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1)
                    
            res = max(res, dp[i][0])
            
        return res

```
