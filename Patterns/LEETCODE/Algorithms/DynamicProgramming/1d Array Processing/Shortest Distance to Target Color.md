### [Shortest Distance to Target Color](https://leetcode.com/problems/shortest-distance-to-target-color/) <br>

You are given an array `colors`, in which there are three colors: `1`, `2` and `3`.

You are also given some queries. Each query consists of two integers `i` and `c`, return the shortest distance between the given index `i` and the target color `c`. If there is no solution return `-1`.



#### Example 1:

```
Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
Output: [3,0,3]
Explanation: 
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).

```


#### Example 2:

```
Input: colors = [1,2], queries = [[0,3]]
Output: [-1]
Explanation: There is no 3 in the array.

```


# Solutions

### Python
```
class Solution:
    def shortestDistanceColor(self, colors: List[int], queries: List[List[int]]) -> List[int]:
        '''
        Create distances array for each color for every index.
        
        For instance create distances for color 2 in array 
        arr-    [1   1    2   1   3   2   2   3   3  ] - original colors input
        
        index    0   1    2   3   4   5   6   7   8
        
        right-  [inf inf  2   2   2   5   6   6   6   ] - find closest `2` color index from right
        left -  [2   2    2   5   5   5   6   inf inf ] - find closest `2` color index from left
        dist -  [2   1    0   1   1   0   0   1   2   ] - distance=abs(index-min(index-right, index-left))
        
        '''
        
        vis=set(colors)            
        n=len(colors)
        res=[]
        
        def distances(color):
            dist=[0]*n
            left=[float('inf')]*n
            right=[float('inf')]*n
            
            ind=None
            for i in range(n):
                if colors[i]==color:
                    ind=i
                if ind != None:   
                    right[i]=ind
            ind=None
            for i in range(n)[::-1]:
                if colors[i]==color:
                    ind=i
                if ind != None:                       
                    left[i]=ind
                
            for i in range(n):
                d=min(abs(i-left[i]), abs(i-right[i]))
                dist[i]=d      
            return dist
        
        dic={}
        for col in [1, 2, 3]:
            if col in vis:
                dic[col]=distances(col)
        
        # print(dic)
        
        for q in queries:
            i, c = q[0], q[1]
            if c in vis:
                res.append(dic[c][i])
            else:
                res.append(-1)
        
        return res
```
