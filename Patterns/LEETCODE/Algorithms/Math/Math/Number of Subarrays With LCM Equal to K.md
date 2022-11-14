### [Number of Subarrays With LCM Equal to K](https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/) <br>

Given an integer array `nums` and an integer `k`, return the number of **subarrays** of nums where the *least common multiple of the subarray's elements is* `k`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

The **least common multiple of an array** is the smallest positive integer that is divisible by all the array elements.


#### Example 1:

```
Input: nums = [3,6,2,7,1], k = 6
Output: 4
Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]
- [3,6,2,7,1]

```

#### Example 2:

```
Input: nums = [3], k = 2
Output: 0
Explanation: There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.
```

# Solutions

### Python
```
class Solution:
    def subarrayLCM(self, nums: List[int], k: int) -> int:
        cnt = 0
        for i in range(0, len(nums)):       # [1] for every initial number, try extending
            l = nums[i]                     #     a continuous sequence of numbers
            for j in range(i, len(nums)):  
                l = lcm(l,nums[j])          # [2] once LCM becomes 'k', each subsequent number
                if l == k :                 #     that don't increase this value will give one
                    cnt += 1                #     more valid subarray
                if l > k  : break           
            
        return cnt
    
    def gcd(a,b):
        while b:
            a,b = b, a%b
        return abs(a)

    def lcm(a,b):
        return a*b / gcd(a,b)    
```

### CPP
```
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int res=0;
        for (int i=0;i<nums.size();i++) {
            int l=nums[i];
            for (int j=i;j<nums.size();j++) {
                l=lcm(l, nums[j]);
                if (l==k)
                    res++;
                if (l>k)
                    break;
            }
        }
        return res;
    }
    
    int lcm(int a, int b) {
        return (a*b)/gcd(a,b);
    }
};
```
