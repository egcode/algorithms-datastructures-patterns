### [The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) <br>


A city's **skyline** is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the **skyline** *formed by these buildings collectively*.

The geometric information of each building is given in the array `buildings` where <img src="https://render.githubusercontent.com/render/math?math=buildings[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=left_i">, <img src="https://render.githubusercontent.com/render/math?math=right_i">, <img src="https://render.githubusercontent.com/render/math?math=height_i">]:

 - <img src="https://render.githubusercontent.com/render/math?math=left_i"> is the x coordinate of the left edge of the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> building.
 - <img src="https://render.githubusercontent.com/render/math?math=right_i"> is the x coordinate of the right edge of the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> building.
 - <img src="https://render.githubusercontent.com/render/math?math=height_i"> is the height of the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> building.

You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height `0`.

The **skyline** should be represented as a list of "key points" **sorted by their x-coordinate** in the form [[<img src="https://render.githubusercontent.com/render/math?math=x_1">,<img src="https://render.githubusercontent.com/render/math?math=y_1">],[<img src="https://render.githubusercontent.com/render/math?math=x_2">,<img src="https://render.githubusercontent.com/render/math?math=y_2">],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate `0` and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

**Note:** There must be no consecutive horizontal lines of equal height in the output skyline. For instance, `[...,[2 3],[4 5],[7 5],[11 5],[12 7],...]` is not acceptable; the three lines of height 5 should be merged into one in the final output as such: `[...,[2 3],[4 5],[12 7],...]`



#### Example 1:
<img src="../../../../../images/218merged.jpg">

```
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.

```

#### Example 2:

```
Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]

```



# Solutions

### Python
```
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        
        # add start-building events
        # also add end-building events(acts as buildings with 0 height)
        # and sort the events in left -> right order
        events = [(L, -H, R) for L, R, H in buildings]          # Starts
        events += list({(R, 0, 0) for _, R, _ in buildings})    # ENDS (ENDS has 0 height)
        events.sort()

        res = [[0, 0]] # [x, height]
        heap = [(0, sys.maxsize)] # [-height, END]
        
        for pos, negH, R in events:
            while heap[0][1] <= pos: # Pop ended buildings
                heappop(heap)
                
            # if it's the start-building event, make the building alive by pushing to heap
            # We skip negH if its END. (ENDS has 0 height)
            if negH: 
                heappush(heap, (negH, R))
                
            # if previous keypoint height != current highest height, append the result
            if res[-1][1] != -heap[0][0]: 
                res.append([pos, -heap[0][0] ])
                
        return res[1:]

```
