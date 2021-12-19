### [Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/) <br>

You are given an integer array `nums` and you have to return a new `counts` array. The `counts` array has the property where `counts[i]` is the number of smaller elements to the right of `nums[i]`.



#### Example 1:

```
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

```

#### Example 2:

```
Input: nums = [-1]
Output: [0]

```

#### Example 3:

```
Input: nums = [-1,-1]
Output: [0,0]

```


# Solutions

### Python
```
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        '''
        Explanation: 
        https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/445769/merge-sort-CLEAR-simple-EXPLANATION-with-EXAMPLES-O(n-lg-n)
        
        Based on merge sort.
        when mergesort splits array, it splits with same order  [5,2,6,1] --> [5] [2] [6] [1]
        and we compare and merge  if [5] > [2]  left bigger than right - we increment
        
        '''
        
        arr=[] # array with indexes
        res=[0]*len(nums)
        
        # add (num, index) tuples
        for i,num in enumerate(nums):
            arr.append((num, i))
    
    
        def merge(left, right):
            l=0
            r=0
            # print("\nleft:"+str(left)+"  right:"+str(right))
            out=[]
            numElemsRightArrayLessThanLeftArray=0
            
            while l < len(left) and r < len(right):
                # print("l:"+str(l)+"  r:"+str(r) + "   len(left):"+str(len(left))+"   len(right):"+str(len(right)))
                # print("left[l][0]:"+str(left[l][0])+"  right[r][0]:"+str(right[r][0]))
                
                if left[l][0] > right[r][0]:
                    out.append(right[r])
                    r += 1
                    
                    numElemsRightArrayLessThanLeftArray += 1                 
                else:
                    out.append(left[l])
                    res[left[l][1]] += numElemsRightArrayLessThanLeftArray
                    l += 1
                                        
            # print("1out:"+str(out) + "   l:"+str(l)+" r:"+str(r))
            if l < (len(left)):
                for i in range(l, len(left)):
                    out.append(left[i])
                    res[left[i][1]] += numElemsRightArrayLessThanLeftArray
                    
            if r < (len(right)):
                for i in range(r,len(right)):
                    out.append(right[i])

            # print("2out:"+str(out))
            return out

        def merge_sort(arr):
            if len(arr)==1:
                return arr

            midIndex=len(arr)//2
            left_side=merge_sort(arr[:midIndex])
            right_side=merge_sort(arr[midIndex:])
            return merge(left_side, right_side)
        _=merge_sort(arr)
        return res

```
