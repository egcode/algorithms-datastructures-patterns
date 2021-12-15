### [Bus Routes](https://leetcode.com/problems/bus-routes/) <br>

You are given an array routes representing bus routes where `routes[i]` is a bus route that the <img src="https://render.githubusercontent.com/render/math?math=i^th"> bus repeats forever.

 - For example, if `routes[0] = [1, 5, 7]`, this means that the <img src="https://render.githubusercontent.com/render/math?math=0^th"> bus travels in the sequence `1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ...` forever.

You will start at the bus stop `source` (You are not on any bus initially), and you want to go to the bus stop `target`. You can travel between bus stops by buses only.

Return *the least number of buses you must take to travel from `source` to `target`*. Return `-1` if it is not possible.




#### Example 1:

```
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

```

#### Example 2:

```
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1

```

# Solutions

### Python
```
class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        '''
        # For this problem:
        # 1. The level is each time to take bus.
        # 2. The position is all of the stops you can reach for taking one time of bus.
        # 3. Using a queue to record all of the stops can be arrived for each time you take buses.
        
        Example:
        [[1,2,7],[3,6,7]]
        source = 1
        target = 6
        
        '''
        if source==target: return 0
        
        graph = collections.defaultdict(list)
        for bus, stops in enumerate(routes):
            for stop in stops:
                graph[stop].append(bus)

        vis=set() # store buses
        q=collections.deque([source]) # starting with source stop
        
        res = 0
        while q:
            res += 1
            size = len(q)
            while size>0:
                
                current_stop = q.pop()
                for bus in graph[current_stop]: 
                    if bus not in vis:
                        vis.add(bus) # Record bus
                        for stop in routes[bus]: 
                            if stop == target:
                                return res
                            q.appendleft(stop)
                
                size -= 1
                
        return -1

```
