### [Car Fleet](https://leetcode.com/problems/car-fleet/) <br>

There are `n` cars going to the same destination along a one-lane road. The destination is `target` miles away.

You are given two integer array `position` and `speed`, both of length `n`, where `position[i]` is the position of the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> car and `speed[i]` is the speed of the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper **at the same speed**. The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are assumed to have the same position).

A **car fleet** is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

Return *the ***number of car fleets*** that will arrive at the destination*.



#### Example 1:

```
Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 and 8 become a fleet, meeting each other at 12.
The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 3) and 3 (speed 1) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
Note that no other cars meet these fleets before the destination, so the answer is 3.

```

#### Example 2:

```
Input: target = 10, position = [3], speed = [3]
Output: 1
Explanation: There is only one car, hence there is only one fleet.

```


#### Example 3:

```
Input: target = 100, position = [0,2,4], speed = [4,2,1]
Output: 1
Explanation:
The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The fleet moves at speed 2.
Then, the fleet (speed 2) and the car starting at 4 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.

```


# Solutions

### Python
```
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        '''  
        Example1:
        target = 12, position = [10,7,3,1], speed = [1,1,1,1]
        Sort cars by POSITION in REVERSE order we get:
        ----------------------- Finish Line - 12
        car1 🚘                10 (2 units to finish) speed 1
        car2    🚘             7  (5 units to finish) speed 1
        car3       🚘          3  (9 units to finish) speed 1
        car4           🚘      1  (11 units to finish) speed 1

        If all cars are moving with the same speed, every car would be separate car fleet.
        
        
        Example2:
        target = 12, position = [10,7,3,1], speed = [1,5,1,1]
        
        Sort cars by POSITION in REVERSE order same way.
        But speed here is different, and some cars could stuck with cars that they catched up with.
        
        ----------------------- Finish Line - 12
        car1 🚘                10 (2 units to finish) speed 1
        car2    🚘             7  (5 units to finish) speed 5
        car3       🚘          3  (9 units to finish) speed 1
        car4           🚘      1  (11 units to finish) speed 1
        
        car2 will catch up with car1 and they will form single car fleet.
        But here on the image below we can see that car2 finished earlier.
        In our implementation if we count car1 as a fleet we can ignore car2 and don't count it at all.
        
        --------🚘-------------- Finish Line - 12        
        car1 🚘                 10 (2 units to finish) speed 1
        car2                    7  (5 units to finish) speed 5
        car3       🚘           3  (9 units to finish) speed 1
        car4           🚘       1  (11 units to finish) speed 1
        
        FinishTime = FinishLine - Position / speed
        car1 finish time = 12-10/1 = 2
        car2 finish time = 12-7/5 = 1 
        
        car2 finish time < car1 finish time
        That means that car2 will finish earlier than car1. We can count car1 and car2 as single fleet.
        Overall in this example we have 3 car fleet since we ignored car 2.
        
        
        In our code we store car1 finish time and if next car finish time earlier than car1 we ignore that car.
        
        '''
        cars=[]
        for pos,speed in zip(position, speed):
            cars.append((pos, speed))
        
        # sort by position in reverse
        cars.sort(reverse=True, key=lambda x: x[0])
        
        res=0
        last_finish_time=-sys.maxsize
        for pos,speed in cars:
            finish_time=(target-pos)/speed
            
            # If car finish time later than last_finish_time we form new fleet 
            if finish_time > last_finish_time:
                res += 1
                last_finish_time=finish_time
                
                
        return res

```


