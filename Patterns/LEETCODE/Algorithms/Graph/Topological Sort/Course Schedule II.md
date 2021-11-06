### [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) <br>

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where <img src="https://render.githubusercontent.com/render/math?math=prerequisites[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=a_i">, <img src="https://render.githubusercontent.com/render/math?math=b_i">] indicates that you **must** take course <img src="https://render.githubusercontent.com/render/math?math=b_i"> first if you want to take course <img src="https://render.githubusercontent.com/render/math?math=a_i">.

 - For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.
Return *the ordering of courses you should take to finish all courses*. If there are many valid answers, return **any of them**. If it is impossible to finish all courses, return **an empty array**.



#### Example 1:

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

```

#### Example 2:

```
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

```

#### Example 3:

```
Input: numCourses = 1, prerequisites = []
Output: [0]

```


# Solutions

### Python
```
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        '''
        Topological Sort with Kahn's algorithm
        '''
#         # ###############################
#         #
#         #    Topological Sort with Kahn's algorithm (in_degree dictionary)
#         #
#         # ###############################
        
        graph=collections.defaultdict(list)
        in_degree={} # in_degree cound for each node
        
        for pr1, pr2 in prerequisites:
            graph[pr2].append(pr1)
            in_degree[pr1]=1+in_degree.get(pr1, 0)
        
        # Getting leaf nodes, they are not in in_degree dictinary
        q=collections.deque([i for i in range(numCourses) if i not in in_degree.keys()])
    
        res=[]
        while q:
            node = q.pop()
            res.append(node)
            
            for next_node in graph[node]:
                in_degree[next_node] -= 1
                
                if in_degree[next_node] == 0:
                    q.appendleft(next_node)
                    
        # --- WE have cycle --- If if we didn't wen't throuh all nodes
        if len(res) != numCourses:
            return []
        return res
    
    
    
#     def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
#         '''
#         Topological Sort with DFS
#         '''
#         n=len(prerequisites)
        
#         graph={i:[] for i in range(numCourses)}
#         for pr in prerequisites:
#             graph[pr[1]].append(pr[0])
        
        
#         # ###############################
#         #
#         #    Topological Sort with DFS
#         #
#         # ###############################
#         ### Return False if we have cycle
        
#         vis=set()
#         cycle=set()        
#         def dfs(node): 
#             nonlocal res
#             if node in vis:
#                 return True
#             if node in cycle:
#                 return False
#             cycle.add(node)
            
#             for next_node in graph[node]:
#                 if dfs(next_node)==False:
#                     return False
            
#             # We reached the end of that path without cycle
#             cycle.remove(node)            
#             vis.add(node)
#             res.insert(0, node)
#             return True
            
            
#         # print(graph)
#         res=[]
#         for node in range(len(graph)):
#             if dfs(node)==False:
#                 return []
                
#         return res

```
