### [Arithmetic Slices II - Subsequence](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/) <br>

Given an integer array `nums`, *return the number of all the ***arithmetic subsequences*** of* `nums`.

A sequence of numbers is called arithmetic if it consists of **at least three elements** and if the difference between any two consecutive elements is the same.

 - For example, `[1, 3, 5, 7, 9]`, `[7, 7, 7, 7]`, and `[3, -1, -5, -9]` are arithmetic sequences.
 - For example, `[1, 1, 2, 5, 7]` is not an arithmetic sequence.

A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

 - For example, `[2,5,10]` is a subsequence of `[1,2,1,2,4,1,5,10]`.

The test cases are generated so that the answer fits in **32-bit** integer.



#### Example 1:

```
Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
```

#### Example 2:

```
Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.

```


# Solutions

### Python
```
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n=len(nums)
        res=0
        dp=[defaultdict(int) for _ in range(n)]
        
        for i in range(n):
            for j in range(i):
                diff=nums[i]-nums[j]
                dp[i][diff] += 1+dp[j][diff]
                res += dp[j][diff]
        
        return res
```

### CPP
```
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), res=0;
        vector<unordered_map<long long,int>>dp(n);
        for (int i=0;i<n;++i) {
            for (int j=0;j<i;++j) {
                long long diff = (long long) nums[i] - nums[j];
                int count = 0;
                if (dp[j].count(diff)) {
                    count = dp[j][diff];
                } else {
                    count=0;
                }
                dp[i][diff] += count+1;
                res += dp[j][diff];
            }
        }
        return res;
    }
    
};
```
