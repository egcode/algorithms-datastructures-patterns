### [Missing Ranges](https://leetcode.com/problems/missing-ranges/) <br>

You are given an inclusive range `[lower, upper]` and a **sorted unique** integer array `nums`, where all elements are in the inclusive range.

A number `x` is considered **missing** if `x` is in the range [`lower, upper]` and `x` is not in `nums`.

Return *the ***smallest sorted*** list of ranges that ***cover every missing number exactly****. That is, no element of `nums` is in any of the ranges, and each missing number is in one of the ranges.

Each range `[a,b]` in the list should be output as:

 - `"a->b"` if `a != b`
 - `"a"` if `a == b`
 


#### Example 1:

```
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: ["2","4->49","51->74","76->99"]
Explanation: The ranges are:
[2,2] --> "2"
[4,49] --> "4->49"
[51,74] --> "51->74"
[76,99] --> "76->99"

```

#### Example 2:

```
Input: nums = [-1], lower = -1, upper = -1
Output: []
Explanation: There are no missing ranges since there are no missing numbers.

```



# Solutions

### Python
```
class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        res=[]
        
        # Handle start
        # remove elements that are smaller than lower
        while nums and nums[0]<lower:
            del nums[0]
        # add lower to the begining of the array            
        if nums and lower < nums[0]:
            nums.insert(0, lower-1) # we add lower-1 so we won't miss the range in the future loop

        # Handle end 
        # remove elements that are bigger than upper
        while nums and upper<nums[-1]:
            nums.pop()
        # add upper to the end of array            
        if nums and upper > nums[-1]:
            nums.append(upper+1) # we add upper+1 so we won't miss the range in the future loop
                
                
        # empty arr
        if not nums:
            if lower==upper:
                return [str(lower)]
            else:
                return[str(lower)+"->"+str(upper)]
        
        # not empty arr
        for i in range(1, len(nums)):
            cur=nums[i]              
            prev=nums[i-1]
            
            # range boundaries
            lo=prev+1
            up=cur-1
            
            # if ranges not intersect, (if boundaries are equal is not intersection)
            # for example: array [1, 2]  lo=1+1=2 up=2-1=1, 2>1 nothing is missing here
            if lo <= up:
                if lo == up:
                    # for example: array [0, 2]  lo=0+1=1 up=2-1=1, 1==1 they are equal
                    # only one digit between elements
                    res.append(str(lo))
                else:
                    res.append(str(lo)+"->"+str(up))
        
        return res

```
