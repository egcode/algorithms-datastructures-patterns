### [Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/) <br>

A car travels from a starting position to a destination which is `target` miles east of the starting position.

There are gas stations along the way. The gas stations are represented as an array `stations` where stations[i] = [position<sub>i</sub>, fuel<sub>i</sub>] indicates that the i<sup>th</sup> gas station is position<sub>i</sub> miles east of the starting position and has fuel<sub>i</sub> liters of gas.

The car starts with an infinite tank of gas, which initially has `startFuel` liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

Return the `minimum number of refueling stops the car must make in order to reach its destination`. If it cannot reach the destination, return `-1`.

Note that if the car reaches a gas station with `0` fuel left, the car can still refuel there. If the car reaches the destination with `0` fuel left, it is still considered to have arrived.


#### Example 1:
```
Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.

```

#### Example 2:
```
Input: target = 100, startFuel = 1, stations = [[10,100]]
Output: -1
Explanation: We can not reach the target (or even the first gas station).

```

#### Example 3:
```
Input: target = 100, startFuel = 10, stations = [[10,60],[20,30],[30,30],[60,40]]
Output: 2
Explanation: We start with 10 liters of fuel.
We drive to position 10, expending 10 liters of fuel.  We refuel from 0 liters to 60 liters of gas.
Then, we drive from position 10 to position 60 (expending 50 liters of fuel),
and refuel from 10 liters to 50 liters of gas.  We then drive to and reach the target.
We made 2 refueling stops along the way, so we return 2.

```


# Solutions

### Python
```
class Solution:
    def minRefuelStops(self, target, startFuel, s):
        '''
        dp[i][j] = at station i, the farthest distance someone can get            by making j stops." transition function: 
        dp[i][j] = max( dp[i-1][j-1] + station i's fuel, dp[i-1][j]) for j=1 to j=i
        
        Example:
            target = 100
            startFuel = 10
            s = [[10,60],[20,30],[30,30],[60,40]]    
            result = 2
            
            [10, 0, 0, 0, 0]
            [10, 0, 0, 0, 0]
            [10, 0, 0, 0, 0]
            [10, 0, 0, 0, 0]
            [10, 0, 0, 0, 0]

            [10, 0, 0, 0, 0]
            [10, 70, 0, 0, 0]
            [10, 70, 100, 0, 0]
            [10, 70, 100, 130, 0]
            [10, 70, 110, 140, 170]
            
        Example:
            target = 100
            startFuel = 25
            s = [[25,25],[50,25],[75,25]] 
            result: 3
            
            [25, 0, 0, 0]
            [25, 0, 0, 0]
            [25, 0, 0, 0]
            [25, 0, 0, 0]

            [25, 0, 0, 0]
            [25, 50, 0, 0]
            [25, 50, 75, 0]
            [25, 50, 75, 100]            
        '''
        if startFuel >= target:
            return 0
        n = len(s)
        # dp[i][j]: in former i stations, pick j stations to fuel, how far it can mostly reach
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = startFuel
        res = sys.maxsize
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                dp[i][j] = dp[i - 1][j] # assign previous calculations
                if dp[i - 1][j - 1] >= s[i - 1][0]: # if station is reachable
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + s[i - 1][1])
                if dp[i][j] >= target:
                    res = min(res, j)                    
        return res if res != sys.maxsize else -1        
  