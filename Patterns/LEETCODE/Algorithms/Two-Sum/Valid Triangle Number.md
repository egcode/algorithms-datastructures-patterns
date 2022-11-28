### [Valid Triangle Number](https://leetcode.com/problems/valid-triangle-number/) <br>

Given an integer array `nums`, return *the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle*.



#### Example 1:
```
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

```

#### Example 2:

```
Input: nums = [4,2,3,4]
Output: 4

```



# Solutions

### Python
```
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        '''
        For triangle there should be a condition:
        a+b>c
        
        Example:
         i                  j   k
        [3, 19, 22, 24, 35, 82, 84] 
        
        because 3 + 82 > 84 and the numbers between 3 and 82 are always larger than 3, so we can quickly tell that there will be j - i combination which can form the triangle, and they are
        
        
         i          j   k
        [3, 19, 22, 24, 35, 82, 84]
        because 3 + 24 < 35, if we move j to the left, the sum will become even smaller, so we have to move pointer i to the next number 19, and now we found that 19 + 24 > 35, and we don't need to scan 22, we know that 22 must be ok!
        '''
        res=0
        nums.sort()
        for k in range(len(nums))[::-1]:
            i=0
            j=k-1
            while i<j:
                if nums[i]+nums[j]>nums[k]:
                    res += j-i
                    j -= 1                    
                else:
                    i += 1                    
        return res
    
```

