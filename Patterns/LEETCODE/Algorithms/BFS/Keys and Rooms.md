### [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms/) <br>

There are n rooms labeled from `0` to `n - 1` and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of **distinct keys** in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array `rooms` where `rooms[i]` is the set of keys that you can obtain if you visited room `i`, return `true` *if you can visit **all** the rooms, or `false` otherwise*.


#### Example 1:

```
Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation: 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.

```

#### Example 2:

```
Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.

```



# Solutions

### Python
```
class Solution:
#     def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
                
#         def dfs(index, vis):
            
#             for new_ind in rooms[index]:
#                 if new_ind in vis:
#                     continue
#                 vis |= dfs(new_ind, vis | {new_ind})
            
#             return vis
        
        
#         return len(dfs(0, set([0]))) == len(rooms)
        
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        q=collections.deque([0])
        vis = set([0])
        n=len(rooms)
        
        while q:
            indexes = q.pop()
            if len(vis)==n:
                return True
            
            for key in rooms[indexes]:
                if key not in vis:
                    vis.add(key)
                    q.appendleft(key)

            
        return False

```
