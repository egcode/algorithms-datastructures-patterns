### [Number of Subarrays With GCD Equal to K](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/) <br>

Given an integer array `nums` and an integer `k`, return the number of **subarrays** of `nums` *where the greatest common divisor of the subarray's elements is* `k`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

The **greatest common divisor of an array** is the largest integer that evenly divides all the array elements.



#### Example 1:
```
Input: nums = [9,3,1,2,6,3], k = 3
Output: 4
Explanation: The subarrays of nums where 3 is the greatest common divisor of all the subarray's elements are:
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]

```

#### Example 2:
```
Input: nums = [4], k = 7
Output: 0
Explanation: There are no subarrays of nums where 7 is the greatest common divisor of all the subarray's elements.

```

# Solutions

### Python
```
class Solution:
    def subarrayGCD(self, nums: List[int], k: int) -> int:
        res=0
        for i in range(len(nums)):
            g=nums[i]
            for j in range(i,len(nums)):
                g = gcd(g, nums[j])
                if g==k:
                    res += 1
                if g<k:
                    break
        return res
            
    def gcd(a,b):
        while b:
            a,b = b, a%b
        return abs(a)
        
```

### CPP
```
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res=0;
        for (int i=0;i<nums.size();++i) {
            int g=nums[i];
            for (int j=i;j<nums.size();++j) {
                g = gcd(g, gcd(g, nums[j]));
                if (g == k)
                    res++;
                if (g < k)
                    break;
            }
        }
        return res;
    }
};
```
