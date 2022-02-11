### [Campus Bikes II](https://leetcode.com/problems/campus-bikes-ii/) <br>

On a campus represented as a 2D grid, there are `n` workers and `m` bikes, with `n <= m`. Each worker and bike is a 2D coordinate on this grid.

We assign one unique bike to each worker so that the sum of the **Manhattan distances** between each worker and their assigned bike is minimized.

Return `the minimum possible sum of Manhattan distances between each worker and their assigned bike`.

The **Manhattan distance** between two points `p1` and `p2` is `Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|`.




#### Example 1:
<img src="../../../../../images/1066_example_1_v2.png">

```
Input: workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
Output: 6
Explanation: 
We assign bike 0 to worker 0, bike 1 to worker 1. The Manhattan distance of both assignments is 3, so the output is 6.

```

#### Example 2:
<img src="../../../../../images/1066_example_2_v2.png">

```
Input: workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
Output: 4
Explanation: 
We first assign bike 0 to worker 0, then assign bike 1 to worker 1 or worker 2, bike 2 to worker 2 or worker 1. Both assignments lead to sum of the Manhattan distances as 4.

```

#### Example 3:

```
Input: workers = [[0,0],[1,0],[2,0],[3,0],[4,0]], bikes = [[0,999],[1,999],[2,999],[3,999],[4,999]]
Output: 4995

```



# Solutions

### Python
```
class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        '''
        Memoization
        '''
        n=len(bikes)
        m=len(workers)
        allWorkers=(1<<m)-1
        
        @lru_cache(None)
        def dp(bike, mask):
            if bike==n and mask==allWorkers:
                return 0
            if bike==n:
                return float('inf')
            
            res=dp(bike+1, mask)
            for worker in range(len(workers)):
                if mask & (1<<worker):
                    continue
                b=bikes[bike]
                w=workers[worker]
                dist=abs(b[0]-w[0])+abs(b[1]-w[1])
                res = min(res, dist + dp(bike+1, mask | (1<<worker)))
            return res
            
        return dp(0,0)
            

```
