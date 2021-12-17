### [Valid Square](https://leetcode.com/problems/valid-square/) <br>

Given the coordinates of four points in 2D space `p1`, `p2`, `p3` and `p4`, return `true` *if the four points construct a square*.

The coordinate of a point <img src="https://render.githubusercontent.com/render/math?math=p_i"> is represented as [<img src="https://render.githubusercontent.com/render/math?math=x_i">, <img src="https://render.githubusercontent.com/render/math?math=y_i">]. The input is **not** given in any order.

A **valid square** has four equal sides with positive length and four equal angles (90-degree angles).



#### Example 1:

```
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true

```

#### Example 2:

```
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false

```

#### Example 3:

```
Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
Output: true

```


# Solutions

### Python
```
class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        '''
        Distance between points formula:  (x2-x1)^2 + (y2-y1)^2
        
        p1   p2
        
        p3   p4
        
        '''
        
        def dist(pt1, pt2):
            return (pt2[1] - pt1[1])**2 + (pt2[0] - pt1[0])**2
        
        arr = [
        dist(p1,p2), # p1 compare with all next points, some of them could be diagonals
        dist(p1,p3),
        dist(p1,p4),
        dist(p2,p3), # p2 compare with all next points, some of them could be diagonals
        dist(p2,p4),
        dist(p3,p4)  # p3 compare with only one next point p4
        ]
        # After sort, first four members of array are - SIDES, last two - DIAGONALS
        arr.sort()
        return 0<arr[0]==arr[1]==arr[2]==arr[3] and arr[4]==arr[5]
                

```
