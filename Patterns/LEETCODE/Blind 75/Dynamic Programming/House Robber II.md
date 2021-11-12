### [House Robber II](https://leetcode.com/problems/house-robber-ii/) <br>

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are **arranged in a circle**. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return the **maximum amount of money** you can rob tonight **without alerting the police**.



#### Example 1:

```
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

```

#### Example 2:

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

```

#### Example 3:

```
Input: nums = [1,2,3]
Output: 3

```

# Solutions

### Python
```
class Solution:
    def rob(self, nums: List[int]) -> int:
        '''
        Since House[1] and House[n] are adjacent, they cannot be robbed together. 
        Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], 
        depending on which choice offers more money. 
        Now the problem has degenerated to the House Robber, which is already been solved.
        
        '''
        
        n=len(nums)
        if n==1: return nums[0]
        a=0
        b=0
        c=0
        d=0
        for i in range(n-1): # House[1]-House[n-1]
            if i%2==0:
                a=max(b, a+nums[i])
            else:
                b=max(a, b+nums[i])
                
        for i in range(1, n): # House[2]-House[n]
            if i%2==0:            
                c=max(d, c+nums[i])
            else:
                d=max(c, d+nums[i])
                    
                    
        out = max(a,b,c,d)                    
                    
        return out

```
