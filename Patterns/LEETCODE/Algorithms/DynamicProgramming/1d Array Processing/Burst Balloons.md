### [Burst Balloons](https://leetcode.com/problems/burst-balloons/) <br>

You are given `n` balloons, indexed from `0` to `n - 1`. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the <img src="https://render.githubusercontent.com/render/math?math=t^{th}"> balloon, you will get `nums[i - 1] * nums[i] * nums[i + 1]` coins. If `i - 1` or `i + 1` goes out of bounds of the array, then treat it as if there is a balloon with a `1` painted on it.

Return *the maximum coins you can collect by bursting the balloons wisely*.



#### Example 1:
```
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

```

#### Example 2:
```
Input: nums = [1,5]
Output: 10

```



# Solutions

### Python
```
class Solution:

    def maxCoins(self, nums: List[int]) -> int:
        '''
        Explanation https://www.youtube.com/watch?v=VFskby7lUbw&ab_channel=NeetCode
        
        This is opposite to brut force method above.
        We are starting from the end.
        
        '''
        
        # special case
        if len(nums) > 1 and len(set(nums)) == 1:
            return (nums[0] ** 3) * (len(nums) - 2) + nums[0] ** 2 + nums[0]

        nums = [1] + nums + [1]
        
        @lru_cache(None)
        def dfs(lo, hi):
            if lo>hi:
                return 0
            res = 0
            for i in range(lo, hi+1):
                gain = nums[lo-1] * nums[i] * nums[hi+1]
                gain += dfs(lo, i-1) + dfs(i+1, hi)
                res = max(res, gain)
            return res
        
        return dfs(1, len(nums) - 2)        

```
