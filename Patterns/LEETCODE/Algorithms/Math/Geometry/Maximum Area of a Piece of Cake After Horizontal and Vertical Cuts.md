### [Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/) <br>

You are given a rectangular cake of size `h x w` and two arrays of integers `horizontalCuts` and `verticalCuts` where:

 - `horizontalCuts[i]` is the distance from the top of the rectangular cake to the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> horizontal cut and similarly, and
 - `verticalCuts[j]` is the distance from the left of the rectangular cake to the <img src="https://render.githubusercontent.com/render/math?math=j^{th}"> vertical cut.

Return *the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays `horizontalCuts` and `verticalCuts`*. Since the answer can be a large number, return this **modulo** <img src="https://render.githubusercontent.com/render/math?math=10^9"> + <img src="https://render.githubusercontent.com/render/math?math=7">.




#### Example 1:
<img src="../../../../../images/1465leetcode_max_area_2.png">

```
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.

```

#### Example 2:
<img src="../../../../../images/1465leetcode_max_area_3.png">

```
Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.

```

#### Example 3:

```
Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9

```



# Solutions

### Python
```
class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.insert(0, 0)
        horizontalCuts.append(h)
        verticalCuts.insert(0, 0)
        verticalCuts.append(w)
        verticalCuts.sort()
        horizontalCuts.sort()
        
        max_h=0
        max_v=0
        
        for i in range(1, len(horizontalCuts)):
            max_h=max(max_h, abs(horizontalCuts[i]-horizontalCuts[i-1]))
        for i in range(1, len(verticalCuts)):
            max_v=max(max_v, abs(verticalCuts[i]-verticalCuts[i-1]))
            
        return (max_h * max_v) % 1000000007

```
