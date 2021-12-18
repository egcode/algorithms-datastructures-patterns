### [Car Fleet II](https://leetcode.com/problems/car-fleet-ii/) <br>

There are `n` cars traveling at different speeds in the same direction along a one-lane road. You are given an array `cars` of length `n`, where <img src="https://render.githubusercontent.com/render/math?math=cars[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=position_i">, <img src="https://render.githubusercontent.com/render/math?math=speed_i">] represents:

 - <img src="https://render.githubusercontent.com/render/math?math=position_i"> is the distance between the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> car and the beginning of the road in meters. It is guaranteed that <img src="https://render.githubusercontent.com/render/math?math=position_i"> < <img src="https://render.githubusercontent.com/render/math?math=position_{i %2B 1}">.
 - <img src="https://render.githubusercontent.com/render/math?math=speed_i"> is the initial speed of the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> car in meters per second.

For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the **slowest** car in the fleet.

Return an array `answer`, where `answer[i]` is the time, in seconds, at which the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> car collides with the next car, or `-1` if the car does not collide with the next car. Answers within <img src="https://render.githubusercontent.com/render/math?math=10^{-5}"> of the actual answers are accepted.


#### Example 1:

```
Input: cars = [[1,2],[2,1],[4,3],[7,2]]
Output: [1.00000,-1.00000,3.00000,-1.00000]
Explanation: After exactly one second, the first car will collide with the second car, and form a car fleet with speed 1 m/s. After exactly 3 seconds, the third car will collide with the fourth car, and form a car fleet with speed 2 m/s.

```

#### Example 2:

```
Input: cars = [[3,4],[5,4],[6,3],[9,1]]
Output: [2.00000,1.00000,1.50000,-1.00000]

```



# Solutions

### Python
```
class Solution:
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        '''
        Collision formula: (x2-x1)/(s1-s2)
        
        '''
        
        res=[]
        
        # we store position, speed, collide_time
        stack=[]
        
        for pos, sp in cars[::-1]:
            
            # if c1 collides with c2 after c2 collides with c3, we can ignore c2 and find collision time of c1 and c3 instead
            # We remove head of stack if:
            #       1) Head stack Car is slower
            #       2) Head stack Car collision time with previous car is After collision of current_car and Head stack Car
            while stack and (sp <= stack[-1][1] or (pos-stack[-1][0])/(stack[-1][1]-sp) >= stack[-1][2]):
                stack.pop()
            
            if stack:
                # we have car to collide with
                collistion_time = (pos-stack[-1][0])/(stack[-1][1]-sp)
                stack.append((pos, sp, collistion_time))
                res.append(collistion_time)
            else:
                # no stack no collistion
                res.append(-1)
                stack.append((pos, sp, sys.maxsize))
            
        return res[::-1]
```
