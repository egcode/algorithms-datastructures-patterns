### [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) <br>

Given an integer array `nums` and an integer `k`, return *`true` if `nums` has a continuous subarray of size ***at least two*** whose elements sum up to a multiple of `k`, or `false` otherwise*.

An integer `x` is a multiple of `k` if there exists an integer `n` such that `x = n * k`. `0` is **always** a multiple of `k`.

 


#### Example 1:

```
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

```

#### Example 2:

```
Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

```

#### Example 3:

```
Input: nums = [23,2,6,4,7], k = 13
Output: false

```


# Solutions

### Python
```
class Solution:
    def checkSubarraySum(self, nums, k):
        '''
        Idea: if sum(nums[i:j]) % k == 0 for some i < j, then sum(nums[:j]) % k == sum(nums[:i]) % k. 
        So we just need to use a dictionary to keep track of sum(nums[:i]) % k and the corresponding index i. 
        Once some later sum(nums[:i']) % k == sum(nums[:i]) % k and i' - i > 1, we return True.

        Time complexity: O(n), space complexity: O(min(k, n)) if k != 0, else O(n).

        '''
        # If zero there is no multiple of k
        if k == 0:
            return False
        
        dic = {0:-1}
        summ = 0
        for i, n in enumerate(nums):
            summ = (summ + n) % k
            
            if summ not in dic:
                dic[summ] = i
            else:
                if i - dic[summ] >= 2:
                    return True
        return False

```
