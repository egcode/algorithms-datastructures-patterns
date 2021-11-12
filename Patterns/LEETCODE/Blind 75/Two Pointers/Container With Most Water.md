### [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) <br>

Given `n` non-negative integers <img src="https://render.githubusercontent.com/render/math?math=a_1">, <img src="https://render.githubusercontent.com/render/math?math=a_2">, ..., <img src="https://render.githubusercontent.com/render/math?math=a_n"> , where each represents a point at coordinate (<img src="https://render.githubusercontent.com/render/math?math=a_i">, <img src="https://render.githubusercontent.com/render/math?math=i">). `n` vertical lines are drawn such that the two endpoints of the line `i` is at (<img src="https://render.githubusercontent.com/render/math?math=i">, <img src="https://render.githubusercontent.com/render/math?math=a_i">) and (<img src="https://render.githubusercontent.com/render/math?math=i">, <img src="https://render.githubusercontent.com/render/math?math=0">). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

**Notice** that you may not slant the container.



#### Example 1:
<img src="../../../../images/11question_11.jpg">

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

```

#### Example 2:

```
Input: height = [1,1]
Output: 1

```

#### Example 3:

```
Input: height = [4,3,2,1,4]
Output: 16

```

#### Example 4:

```
Input: height = [1,2,1]
Output: 2

```


# Solutions

### Python
```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        p1=0
        p2=len(height)-1
        
        res=0
        while p1<p2:
            res = max(res, min(height[p1],height[p2]) * (p2-p1))
            if height[p1]<height[p2]:
                p1 += 1
            else:
                p2 -= 1
        return res

```
