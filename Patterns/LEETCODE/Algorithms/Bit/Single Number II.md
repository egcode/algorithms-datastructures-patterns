### [Single Number II](https://leetcode.com/problems/single-number-ii/) <br>

Given an integer array `nums` where every element appears **three times** except for one, which appears **exactly once**. *Find the single element and return it*.

You must implement a solution with a linear runtime complexity and use only constant extra space.



#### Example 1:

```
Input: nums = [2,2,3,2]
Output: 3

```

#### Example 2:

```
Input: nums = [0,1,0,1,0,1,99]
Output: 99

```



# Solutions

### Python
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        seen_once, seen_twice = 0,0
                
        for num in nums:
            '''
            Example: x=2
            
            1.first appearance: 
            add num to seen_once 
            don't added to seen_twice because of presence in seen_once
            Example:
            seen_once = ~seen_twice & (seen_once ^ num)  # 0 0 0 0 0 0 1 0
            seen_twice = ~seen_once & (seen_twice ^ num) # 0 0 0 0 0 0 0 0            
            2.second appearance: 
            remove num from seen_once 
            add num to seen_twice
            Example:
            seen_once = ~seen_twice & (seen_once ^ num)  # 0 0 0 0 0 0 0 0
            seen_twice = ~seen_once & (seen_twice ^ num) # 0 0 0 0 0 0 1 0
            
            3.third appearance: 
            don't add to seen_once because of presence in seen_twice
            remove num from seen_twice
            Example:
            seen_once = ~seen_twice & (seen_once ^ num)  # 0 0 0 0 0 0 0 0
            seen_twice = ~seen_once & (seen_twice ^ num) # 0 0 0 0 0 0 0 0
            
            '''
            
            seen_once = ~seen_twice & (seen_once ^ num)
            seen_twice = ~seen_once & (seen_twice ^ num)
        
        return seen_once
```
