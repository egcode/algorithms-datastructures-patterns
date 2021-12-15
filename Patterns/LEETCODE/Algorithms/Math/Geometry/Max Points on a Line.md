### [Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/) <br>

Given an array of points where <img src="https://render.githubusercontent.com/render/math?math=points[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=x_i">, <img src="https://render.githubusercontent.com/render/math?math=y_i">] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.



#### Example 1:
<img src="../../../../../images/149plane1.jpg">

```
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

```

#### Example 2:
<img src="../../../../../images/149plane2.jpg">

```
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4

```


# Solutions

### Python
```
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        '''
        (x1, y2),  (x2, y2),  (x3, y3)
        y2-y1/x2-x1 = y3-y1/x3-x1 
        if slopes are equal - same line
        '''
        
        n=len(points)
        if n<3: return n
        res=0
        
        for i in range(n):
            dic={'zero_division': 1}
            for j in range(i+1, n):
                p1=points[i]
                p2=points[j]
                
                # x1==x2 - division by zero
                slope = (p2[1]-p1[1]) / (p2[0]-p1[0]) if p2[0] != p1[0] else 'zero_division'
                
                dic[slope]=1+dic.get(slope, 1)
                
            d=dic.values()
            if d:
                res=max(res, max(d) )
        
        return res

```
