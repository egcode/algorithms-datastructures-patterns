### [Maximum Number of Visible Points](https://leetcode.com/problems/maximum-number-of-visible-points/) <br>

You are given an array `points`, an integer `angle`, and your `location`, where <img src="https://render.githubusercontent.com/render/math?math=location"> = [<img src="https://render.githubusercontent.com/render/math?math=pos_x">, <img src="https://render.githubusercontent.com/render/math?math=pos_y">] and <img src="https://render.githubusercontent.com/render/math?math=points[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=x_i">, <img src="https://render.githubusercontent.com/render/math?math=y_i">] both denote **integral coordinates** on the X-Y plane.

Initially, you are facing directly east from your position. You **cannot move** from your position, but you can **rotate**. In other words, <img src="https://render.githubusercontent.com/render/math?math=pos_x"> and <img src="https://render.githubusercontent.com/render/math?math=pos_y"> cannot be changed. Your field of view in **degrees** is represented by `angle`, determining how wide you can see from any given view direction. Let `d` be the amount in degrees that you rotate counterclockwise. Then, your field of view is the **inclusive** range of angles `[d - angle/2, d + angle/2]`.

<video width="400" controls>
  <source src="../../../../../images/1610-angle.mp4" type="video/mp4">
</video>


You can **see** some set of points if, for each point, the **angle** formed by the point, your position, and the immediate east direction from your position is **in your field of view**.

There can be multiple points at one coordinate. There may be points at your location, and you can always see these points regardless of your rotation. Points do not obstruct your vision to other points.

Return *the maximum number of points you can see*.


#### Example 1:
<img src="../../../../../images/1610-89a07e9b-00ab-4967-976a-c723b2aa8656.png">

```
Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
Output: 3
Explanation: The shaded region represents your field of view. All points can be made visible in your field of view, including [3,3] even though [2,2] is in front and in the same line of sight.

```

#### Example 2:

```
Input: points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
Output: 4
Explanation: All points can be made visible in your field of view, including the one at your location.

```

#### Example 3:
<img src="../../../../../images/1610-5010bfd3-86e6-465f-ac64-e9df941d2e49.png">

```
Input: points = [[1,0],[2,1]], angle = 13, location = [1,1]
Output: 1
Explanation: You can only see one of the two points, as shown above.

```



# Solutions

### Python
```
class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        ''' 
        1. convert all coordinates to radians (points to angles) 
        2. sort the array
        3. use sliding window to find the longest window that satisfies arr[r] - arr[l] <= angle.
        Note that we need to go around the circle, so we duplicate the array and offset the second half by 2*pi.
        '''
        
        arr=[]
        same_as_location=0
        
        for x, y in points:
            # if point has same location as out location we will append it to result at the end
            if x==location[0] and y==location[1]:
                same_as_location += 1
                continue
            # converting points to angles, and atan2 converts to radians
            arr.append(math.atan2(y-location[1], x-location[0]))
                
                
        arr.sort()

        # note that we need to go around the circle
        # so we duplicate the array and offset the second half by 2*pi.            
        arr = arr + [x + 2.0 * math.pi for x in arr]


        angle = math.pi * angle / 180
        l=0
        res=0
        # use sliding window to find the longest window that satisfies arr[r] - arr[l] <= angle.
        for r in range(len(arr)):
            while arr[r] - arr[l] > angle: # cut sliding window tail, if not in our view angle
                l += 1
            res = max(res, r - l + 1)
            
        return res + same_as_location

```
