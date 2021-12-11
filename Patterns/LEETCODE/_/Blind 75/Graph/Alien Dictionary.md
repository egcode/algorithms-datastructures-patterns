### [Alien Dictionary](https://leetcode.com/problems/alien-dictionary/) <br>

There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

You are given a list of strings `words` from the alien language's dictionary, where the strings in `words` are **sorted lexicographically** by the rules of this new language.

*Return a string of the unique letters in the new alien language sorted in* **lexicographically increasing order** *by the new language's rules. If there is no solution, return* `""`. *If there are multiple solutions, return* **any of them**.

A string `s` is **lexicographically smaller** than a string `t` if at the first letter where they differ, the letter in `s` comes before the letter in `t` in the alien language. If the first `min(s.length, t.length)` letters are the same, then `s` is smaller if and only if `s.length < t.length`.


#### Example 1:

```
Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"

```

#### Example 2:

```
Input: words = ["z","x"]
Output: "zx"

```

#### Example 3:

```
Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".

```
# Solutions

### Python
```
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        '''
        DFS
        '''
        
        graph={}
        for word in words:
            for c in word:
                graph[c]=set()
                
        # 1. Building graph
        for i in range(len(words)-1):
            cur=words[i]
            nxt=words[i+1]
            shortest=min(len(cur), len(nxt))
            
            for j in range(shortest):
                if cur[:j]==nxt[:j]:  # if j==0 this is always True, and we only compare first letters on next conditional
                    if cur[j] != nxt[j]:   
                        # graph[cur[j]].add(nxt[j])
                        graph[nxt[j]].add(cur[j]) # We point from next word to current
                    
                    
            # Check that second word isn't a prefix of first word.
            if len(cur)>len(nxt) and cur[:len(nxt)]==nxt:
                return ""
            
        # 2. Graph traverse and look for cycles
        res=[]
        vis=set()
        cycle=set()

        def dfs(node):
            if node in vis:
                return True
            if node in cycle:
                return False # Stop on cycle
            
            cycle.add(node)
            for new_node in list(graph[node]):
                if not dfs(new_node):
                    return False # Stop on cycle
                
            cycle.remove(node)
            vis.add(node)
            res.append(node)
            return True

        for nd in graph.keys():
            if not dfs(nd):
                return ""
        
        return "".join(res)

    
    
#     def alienOrder(self, words: List[str]) -> str:
#         '''
#         BFS
#         '''

#         # Part 1 - Creating graph
#         graph={}
#         in_degree = {}             
#         for word in words:
#             for c in word:
#                 graph[c]=set()
#                 in_degree[c]=0
                    
#         for i in range(len(words)-1):
#             cur=words[i]
#             nxt=words[i+1]   
#             longest=max(len(cur), len(nxt))
#             for j in range(longest):
                                    
#                 if j<len(cur) and j<len(nxt):
#                     if cur[:j]==nxt[:j]:
#                         if cur[j] != nxt[j]:
#                             if nxt[j] not in graph[cur[j]]:
#                                 graph[cur[j]].add(nxt[j])
#                                 in_degree[nxt[j]] += 1 # We mark if node is going INTO IT
                            
#                 # Check that second word isn't a prefix of first word.                            
#                 elif j==len(nxt) and len(cur)>len(nxt) and cur[:j]==nxt[:j]:
#                     return ""
                
#         # Step 2: We need to repeatedly pick off nodes with an indegree of 0
#         res=[]
#         queue=collections.deque(res)
#         for k,v in in_degree.items():
#             if v==0:
#                 queue.append(k)
        
#         while len(queue)>0:
#             pop=queue.pop()
#             res.append(pop)
#             for con in graph[pop]:
#                 in_degree[con] -= 1
#                 if in_degree[con] == 0:
#                     queue.appendleft(con)
        
#         if len(res) < len(in_degree):
#             return ""
    
#         return "".join(res)        

```
