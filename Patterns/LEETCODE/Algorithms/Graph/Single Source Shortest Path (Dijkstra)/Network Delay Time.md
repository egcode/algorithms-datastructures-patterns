### [Network Delay Time](https://leetcode.com/problems/network-delay-time/) <br>

You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges <img src="https://render.githubusercontent.com/render/math?math=times[i]"> = (<img src="https://render.githubusercontent.com/render/math?math=u_i">, <img src="https://render.githubusercontent.com/render/math?math=v_i">, <img src="https://render.githubusercontent.com/render/math?math=w_i">), where <img src="https://render.githubusercontent.com/render/math?math=u_i"> is the source node, <img src="https://render.githubusercontent.com/render/math?math=v_i"> is the target node, and <img src="https://render.githubusercontent.com/render/math?math=w_i"> is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return the time it takes for all the `n` nodes to receive the signal. If it is impossible for all the `n` nodes to receive the signal, return `-1`.



#### Example 1:
<img src="../../../../../images/743_example_1.jpg">

```
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

```

#### Example 2:

```
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

```

#### Example 3:

```
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

```

# Solutions

### Python
```
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        '''
        Dijkstra's Algorithm
        it is BFS with min heap instead of queue
        
        complexity:
        E-total number of edges
        V-total number of vertices
        O(E * logV)
        
        '''
        graph=collections.defaultdict(list)
        
        for src, dest, time in times:
            graph[src].append((time, dest))        
        
        heap=[(0, k)] # time the value for min heap
        vis=set()
        res=0
        
        while heap:
            time, node = heappop(heap)
            if node in vis:
                continue
            vis.add(node)
            res=max(res, time) # Store max path
            
            for time2, child in graph[node]:
                if child not in vis:
                    # Summ time and child's time
                    heappush(heap, (time+time2, child))
        
        if len(vis) != n:
            return -1
        return res
        
#     def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
#         '''
#         Bellman Ford
        
#         '''
#         arr = [float('inf')]*n
#         arr[k-1] = 0  # cost for reaching source is zero
        
#         # Bellmand Ford we usually run it n-1 times
#         for i in range(n-1):
            
#             # we have to use temporary array here
#             # because we have k limitation
#             tmp_arr=arr.copy()
            
#             for s, d, t in times: # s=source d=destination p=price
#                 if tmp_arr[s-1]==float('inf'):
#                     continue
                    
#                 # compare with original time is like we compare with previous step 
#                 if arr[s-1]+t < tmp_arr[d-1]:
#                     tmp_arr[d-1]=arr[s-1]+t
                
#             arr=tmp_arr
            
#         # print(arr)
#         res=max(arr)
#         if res==float('inf'):
#             return -1
#         return res
    
    
    
#     def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
#         '''
#         Bellman Ford
#         Shorter version
        
#         '''
#         arr = [float('inf')]*n
#         arr[k-1] = 0  # cost for reaching source is zero
        
#         # Bellmand Ford we usually run it n-1 times
#         for i in range(n-1):
                        
#             for s, d, t in times: # s=source d=destination p=price
#                 if arr[s-1]==float('inf'):
#                     continue
                    
#                 # compare with original time is like we compare with previous step 
#                 if arr[s-1]+t < arr[d-1]:
#                     arr[d-1]=arr[s-1]+t
                            
#         # print(arr)
#         res=max(arr)
#         if res==float('inf'):
#             return -1
#         return res

```
