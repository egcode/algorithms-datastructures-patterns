### [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/) <br>

You are given a list of airline `tickets` where <img src="https://render.githubusercontent.com/render/math?math=tickets[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=from_i">, <img src="https://render.githubusercontent.com/render/math?math=to_i">] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from `"JFK"`, thus, the itinerary must begin with `"JFK"`. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

 - For example, the itinerary `["JFK", "LGA"]` has a smaller lexical order than `["JFK", "LGB"]`.

You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.



#### Example 1:
<img src="../../../../../images/332itinerary1-graph.jpg">

```
Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]

```

#### Example 2:
<img src="../../../../../images/332itinerary2-graph.jpg">

```
Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

```

# Solutions

### Python
```
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        '''
        DFS with seen mask
        '''
        graph=collections.defaultdict(list)
        seen={}
        n=len(tickets)
        
        for t in tickets:
            graph[t[0]].append(t[1])
            
        for orig, dest in graph.items():
            dest.sort()
            seen[orig]=[False]*len(dest)
            
        res=[]
        def backtrack(node, path, seen):
            nonlocal res
            if len(path)==n+1:
                res=path
                return True
            
            for i in range(len(graph[node])):
                if not seen[node][i]:
                    seen[node][i]=True
                    
                    child = graph[node][i]
                    if backtrack(child, path+[child], seen)==True:
                        return True
                    
                    # backtrack
                    seen[node][i]=False
                    
            return False
        
        backtrack('JFK',['JFK'], seen)
                
        return res
    
#     def findItinerary(self, tickets: List[List[str]]) -> List[str]:
#         '''
#         DFS with graph
#         '''
#         graph=collections.defaultdict(list)
        
#         for t in tickets:
#             graph[t[0]].append(t[1])
        
#         # Sort parths for each point
#         for k,v in graph.items():
#             v.sort()
            
#         n=len(tickets)
#         res=[]
        
#         def backtrack(node, path, graph):
#             nonlocal res
#             if len(path)==n+1:
#                 res=path
#                 return True
            
#             for i in range(len(graph[node])):
#                 child = graph[node][i]
                
#                 arr_old = graph[node]
#                 arr_new = arr_old[:i] + arr_old[i+1:]
#                 if not arr_new:
#                     del graph[node]
#                 else:
#                     graph[node] = arr_new
                
#                 if backtrack(child, path+[child], graph)==True:
#                     return True
                
#                 # backtrack
#                 graph[node] = arr_old
                
#             return False
        
#         backtrack('JFK',['JFK'], graph)
                
#         return res

```
