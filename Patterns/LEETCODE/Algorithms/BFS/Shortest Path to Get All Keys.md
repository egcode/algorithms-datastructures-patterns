### [Shortest Path to Get All Keys](https://leetcode.com/problems/shortest-path-to-get-all-keys/) <br>

You are given an `m x n` grid `grid` where:

 - `'.'` is an empty cell.
 - `'#'` is a wall.
 - `'@'` is the starting point.
 - Lowercase letters represent keys.
 - Uppercase letters represent locks.

You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some `1 <= k <= 6`, there is exactly one lowercase and one uppercase letter of the first `k` letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return *the lowest number of moves to acquire all keys*. If it is impossible, return `-1`.



#### Example 1:
<img src="../../../../images/864lc-keys2.jpg">

```
Input: grid = ["@.a.#","###.#","b.A.B"]
Output: 8
Explanation: Note that the goal is to obtain all the keys not to open all the locks.

```

#### Example 2:
<img src="../../../../images/864lc-key2.jpg">

```
Input: grid = ["@..aA","..B#.","....b"]
Output: 6

```

#### Example 3:
<img src="../../../../images/864lc-keys3.jpg">

```
Input: grid = ["@Aa"]
Output: -1

```



# Solutions

### Python
```
class Solution:
#     def shortestPathAllKeys(self, grid: List[str]) -> int:
#         '''
#         The key here is to revisit cells with new state after we collect new keys.
        
#         Note: My previous mistake was to use string instead of tuple in the `vis` set. 
#         The thing is that sting has an order, we don't need order here in vis.
        
#         '''

#         if not grid: return -1
#         keys={'a','b','c','d','e','f'}
#         locks={'A','B','C','D','E','F'}
#         indexes={'A':0,'B':1,'C':2,'D':3,'E':4,'F':5}
#         h=len(grid)
#         w=len(grid[0])
        
#         total_keys=0
#         startX, startY = 0,0
#         for i in range(h):
#             for j in range(w):
#                 if grid[i][j]=='@':
#                     startX, startY = i, j
#                 if grid[i][j] in keys:
#                     total_keys += 1
                    
#         keysTuple=tuple([0]*total_keys)
#         q=collections.deque([(startX,startY,0, keysTuple)])        
#         vis=set([(0,0,keysTuple)]) # tuple helps to get keys that we have without order
        
        
#         while q:
#             row,col,path, keysTuple = q.pop()

#             if all(keysTuple):
#                 return path

#             for d in [[0,1],[0,-1],[1,0],[-1,0]]:
#                 r=d[0]+row
#                 c=d[1]+col
#                 if 0<=r<h and 0<=c<w and (r,c,keysTuple) not in vis and grid[r][c] != '#':
#                     ch=grid[r][c]
                    
                    
#                     if ch in locks:
#                         index=indexes[ch]
#                         # Stop if no key for lock
#                         if keysTuple[index]==0:
#                             continue
                                        
#                     nKeysTuple=keysTuple
#                     if ch in keys:
#                         # Adding new key
#                         index=indexes[ch.upper()]
#                         nkeys=list(keysTuple)
#                         nkeys[index]=1
#                         nKeysTuple=tuple(nkeys)
                            
#                     vis.add((r,c,nKeysTuple))                    
#                     q.appendleft((r,c,path+1, nKeysTuple))
                    
#         return -1

    def shortestPathAllKeys(self, grid: List[str]) -> int:
        '''
        The key here is to revisit cells with new state after we collect new keys.
        here we are using bit mask as hashmap
        
        '''
        def setKthBit(mask, k):
            mask |= 1<<k
            return mask
        def isKthBitSet(mask, k):
            if (mask & (1 << k)):
                return True
            return False

        if not grid: return -1
        keys={'a','b','c','d','e','f'}
        locks={'A','B','C','D','E','F'}
        indexes={'A':0,'B':1,'C':2,'D':3,'E':4,'F':5}
        h=len(grid)
        w=len(grid[0])
        
        total_keys=0
        all_bits_set=0
        startX, startY = 0,0
        for i in range(h):
            for j in range(w):
                if grid[i][j]=='@':
                    startX, startY = i, j
                if grid[i][j] in keys:
                    all_bits_set = setKthBit(all_bits_set, total_keys)
                    total_keys += 1
                    
        q=collections.deque([(startX,startY,0,0)])
        vis=set([(0,0,0)]) # tuple helps to get keys that we have without order
        
        
        while q:
            row,col,path, keysHash = q.pop()
            
            if keysHash==all_bits_set:
                return path

            for d in [[0,1],[0,-1],[1,0],[-1,0]]:
                r=d[0]+row
                c=d[1]+col
                if 0<=r<h and 0<=c<w and (r,c,keysHash) not in vis and grid[r][c] != '#':
                    ch=grid[r][c]
                    
                    if ch in locks:
                        index=indexes[ch]
                        # Stop if no key for lock
                        if isKthBitSet(keysHash, index)==False:
                            continue
                                        
                    nKeysHash=keysHash
                    if ch in keys:
                        # Adding new key
                        index=indexes[ch.upper()]
                        nKeysHash=setKthBit(keysHash, index)
                            
                    vis.add((r,c,nKeysHash))
                    q.appendleft((r,c,path+1, nKeysHash))
                    
        return -1

```
