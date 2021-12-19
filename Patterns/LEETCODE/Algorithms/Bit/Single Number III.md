### [Single Number III](https://leetcode.com/problems/single-number-iii/) <br>

Given an integer array `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in **any order**.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



#### Example 1:

```
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

```

#### Example 2:

```
Input: nums = [-1,0]
Output: [-1,0]

```

#### Example 3:

```
Input: nums = [0,1]
Output: [1,0]

```


# Solutions

### Python
```
class Solution:
    # def singleNumber(self, nums: List[int]) -> List[int]:
    #     '''
    #     HashMap
    #     '''
    #     c=Counter(nums)
    #     return [k for k,v in c.items() if v==1]
    
    def singleNumber(self, nums: List[int]) -> List[int]:
        '''
        Bit Masking
        '''
        # we are looking for x and y
        # bitmask contains both x and y
        bitmask=0
        for num in nums:
            bitmask = bitmask ^ num
        
        # rightmost 1-bit diff between x and y
        dif = bitmask & (-bitmask)
        # print(" dif:  ")
        # print(format(dif, '0{}b'.format(8)))
        # print("\n")
        
        x=0
        for num in nums:
            # bitmask which will contain only x
            if num & dif: # KEY condition
                # print(" num:  "+str(num))
                # print(format(num, '0{}b'.format(8)))
                x ^= num
                
        # remove x from bitmask we got y        
        y=bitmask^x
        return [x, y]
```
