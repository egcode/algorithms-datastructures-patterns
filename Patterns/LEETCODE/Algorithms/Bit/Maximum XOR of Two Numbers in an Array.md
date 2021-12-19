### [Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) <br>

Given an integer array `nums`, return *the maximum result of `nums[i] XOR nums[j]`, where `0 <= i <= j < n`*.


#### Example 1:

```
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

```

#### Example 2:

```
Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127

```



# Solutions

### Python
```
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        '''
        Critical part: to solve this in O(n) it's important to know that 
        If a ^ b = c, then a ^ c = b and 
                           c ^ b = a. 
        
        So, if we are looking for a particular number (in our case a possible maximum) we can do the following search: 
        iterate in the numbers that we `AND`'d with the mask. 
        If our potental maximum is c, and our current number is a, we're looking for another number b that XOR'd with a gives c. 
        Since we also know from above that a ^ c = b, 
        we can just look for b it directly in our numbers (i.e. b = a ^ c, in code, possible_mx ^ bit).
        
        '''
            
        res=0 # Equivalent to hash map in TwoSum
        mask = 0
        for i in range(31)[::-1]:
            # print("\nindex: "+str(i))
            # adds one  to the mask 
            # bit by bit
            # eg. 0000000000000000000000000000000 -> 1111111111000000000000000000000 -> 1111111111111111111111111111111
            mask |= 1<<i
            # print("mask: "+ format(mask, '0{}b'.format(31)))
            
            
            bits = set()
            # Perform AND operator between mask and every num
            # Example: 
            # mask=        '1111111111111111111111111111100'
            # num=         '0000000000000000000000000000101'
            # add_to_set=  '0000000000000000000000000000100'            
            for num in nums:
                add_to_set = num & mask
                # print("add_to_set: "+ format(add_to_set, '0{}b'.format(31)))
                bits.add(add_to_set)
            # print("found set: "+str(bits))
            
            
            # Start from our res and add one 1
            possible_mx = res | 1<<i
            # print("possible_mx: "+ format(possible_mx, '0{}b'.format(31)))
            
            for bit in bits:
                # Apply TwoSum problem: 
                # if we found two numbers with XOR starting with possible_mx, then we are happy: 
                # we update our ans and break for inner loop: so we continue to look at the next digit.
                search = possible_mx ^ bit # if we found our 
                # print("search: "+ format(search, '0{}b'.format(31)))
                if search in bits:
                    # print("Found search  RES: "+ format(possible_mx, '0{}b'.format(31)) + "    digit: "+str(possible_mx))                    
                    res = possible_mx
                    break
                    
        return res
```
