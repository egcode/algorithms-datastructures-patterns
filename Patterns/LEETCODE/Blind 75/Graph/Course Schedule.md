### [Course Schedule](https://leetcode.com/problems/course-schedule/) <br>

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where <img src="https://render.githubusercontent.com/render/math?math=prerequisites[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=a_i">, <img src="https://render.githubusercontent.com/render/math?math=b_i">] indicates that you **must** take course <img src="https://render.githubusercontent.com/render/math?math=b_i"> first if you want to take course <img src="https://render.githubusercontent.com/render/math?math=a_i">.

 - For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.





#### Example 1:

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

```

#### Example 2:

```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

```

# Solutions

### Python
```
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        '''
        Topological Sort with Kahn's algorithm
        '''
#         # ###############################
#         #
#         #    Topological Sort with Kahn's algorithm (in_degree dictionary)
#         #
#         # ###############################

        graph=collections.defaultdict(list)
        in_degree={} # count leaf nodes
        
        for pr1, pr2 in prerequisites:
            graph[pr2].append(pr1)
            in_degree[pr1]=1+in_degree.get(pr1, 0)
        
        res=[]
        # adding nodes without leafes into q
        q=collections.deque([i for i in range(numCourses) if i not in in_degree.keys()])
               
        while q:
            node=q.pop()
            res.append(node)
            for child in graph[node]:
                
                in_degree[child] -= 1
            
                if in_degree[child] == 0:
                    q.append(child)
        
        return len(res)==numCourses # check if we have cycle
                
                
                

#     def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
#         n=len(prerequisites)
#         if n==0: return True
# #         # ###############################
# #         #
# #         #    Topological Sort with DFS
# #         #
# #         # ###############################

#         graph=[[] for _ in range(numCourses)]
#         for i in range(n):
#             pr=prerequisites[i]
#             graph[pr[1]].append(pr[0])

            
#         def dfs(node, vis, cycle):
#             if node in vis:
#                 return True
#             if node in cycle:
#                 return False
#             cycle.add(node)
#             for next_node in graph[node]:
#                 if next_node not in vis:
#                     if not dfs(next_node, vis, cycle):
#                         return False
#             vis.add(node)
#             cycle.remove(node)
#             return True
            

#         for node in range(len(graph)):
#             cycle=set()
#             vis=set()            
#             if dfs(node, vis, cycle)==False:
#                 return False
            
#         return True

```
