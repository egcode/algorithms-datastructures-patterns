### [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) <br>

Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return *the area of the largest rectangle in the histogram*.



#### Example 1:
<img src="../../../../../images/84histogram.jpg">

```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

```

#### Example 2:
<img src="../../../../../images/84histogram-1.jpg">

```
Input: heights = [2,4]
Output: 4

```



# Solutions

### Python
```
class Solution:
#     def largestRectangleArea(self, heights: List[int]) -> int:
#         '''
#         Using Stack:
#         for each height we calculating borders.
#         first: left borders array 
#         second: right borders array 
        
#         and finally multiply length of borders to height 
        
#         '''
#         n=len(heights)
#         stack=[]
#         res=0
        
        
#         left=[0]*n
#         for i, h in enumerate(heights):
#             while stack and h <= heights[stack[-1]]:
#                 stack.pop()
#             if stack:
#                 left[i]=stack[-1]+1
#             stack.append(i)                    
            
#         stack=[]
#         right=[n-1]*n
#         for i, h in reversed(list(enumerate(heights))):
#             while stack and h <= heights[stack[-1]]:
#                 stack.pop()
#             if stack:
#                 right[i]=stack[-1]-1
#             stack.append(i)                    
                        
#         for i in range(n):
#             length = right[i] - left[i] + 1
#             res=max(res, length*heights[i])            
            
#         return res
        
    
    
    def largestRectangleArea(self, heights: List[int]) -> int:
        '''
        Using Stack:
        if last in stack bigger that current, we calculating stack ones.
        stack stores ascending heights indexes
        '''
        heights.append(0)
        n=len(heights)
        stack=[]
        maxarea=0
        
        left=[0]*n
        for i in range(len(heights)):
            while stack and heights[i] < heights[stack[-1]]:
                h = heights[stack.pop()]
                w = i if not stack else i-stack[-1]-1
                maxarea=max(maxarea, w*h)                            
            stack.append(i)                    
                        
        return maxarea

```
