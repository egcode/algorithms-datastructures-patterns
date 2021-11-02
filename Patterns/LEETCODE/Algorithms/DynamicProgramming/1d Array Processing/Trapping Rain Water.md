### [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) <br>

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.


#### Example 1:
<img src="../../../../../images/rainwatertrap.png">

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

```


#### Example 2:

```
Input: height = [4,2,0,3,2,5]
Output: 9

```


# Solutions

### Python
```
class Solution:
#     def trap(self, height: List[int]) -> int:
#         n=len(height)
#         left=0
#         right=n-1
        
#         left_max=0
#         right_max=0
        
#         res=0
#         while left<right:
#             if height[left]<height[right]:
#                 if height[left]>left_max:
#                     left_max=height[left]
#                 else:
#                     res += left_max-height[left]
#                 left += 1
#             else:
#                 if height[right]>right_max:
#                     right_max=height[right]
#                 else:
#                     res += right_max-height[right]
#                 right -= 1
                
#         return res
    
    def trap(self, height: List[int]) -> int:
        n=len(height)
        if not height: return 0
        
        max_right=[0]*n
        max_right[0]=height[0]
        for i in range(1, n):
            max_right[i]=max(max_right[i-1], height[i])
            
        max_left=[0]*n
        max_left[n-1]=height[n-1]
        for i in reversed(range(n-1)):
            max_left[i]=max(max_left[i+1], height[i])
            
        res=0
        for i in range(n):
            res += min(max_right[i], max_left[i]) - height[i]
        
        return res
            
    
```
