### [Task Scheduler](https://leetcode.com/problems/task-scheduler/) <br>

Given a characters array `tasks`, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer `n` that represents the cooldown period between two **same tasks** (the same letter in the array), that is that there must be at least `n` units of time between any two same tasks.

Return *the least number of units of times that the CPU will take to finish all the given tasks*.



#### Example 1:

```
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.

```

#### Example 2:

```
Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.

```

#### Example 3:

```
Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A

```



# Solutions

### Python
```
Solution:
        
#     def leastInterval(self, tasks: List[str], n: int) -> int:
#         '''
#         Using Heap
#         '''
#         counts=collections.Counter(tasks)
#         h=[]
#         for v, t in counts.items():
#             heapq.heappush(h, (-1*t, v))
            
#         current_time=0
        
#         while h:
#             tmp=[]
#             i=n
#             while i>=0:
#                 current_time += 1
#                 if h:
#                     freq, letter = heapq.heappop(h)
#                     if freq != -1:
#                         tmp.append((freq+1, letter))
#                 if not h and not tmp:
#                     break
#                 i -= 1   
                      
#             for fr in tmp:
#                 heapq.heappush(h, fr)

#         return current_time
    
    
    def leastInterval(self, tasks: List[str], n: int) -> int:
        '''
        Cooldowns count * chunk_length + biggest_count
        '''
        
        counts=list(collections.Counter(tasks).values())
        biggest=max(counts)
        biggest_count=counts.count(biggest) # count of biggest ones in array
        
        cooldowns_count=biggest-1      #  __ in (A__A__A)
        chunk_length_with_cooldown=n+1 #  A__  in (A__A__A)
        
        res=cooldowns_count * chunk_length_with_cooldown + biggest_count
        
        return max(len(tasks), res)
        
```
