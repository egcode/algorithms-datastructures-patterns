### [Number of Ways to Wear Different Hats to Each Other](https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/) <br>

There are `n` people and `40` types of hats labeled from `1` to `40`.

Given a 2D integer array `hats`, where `hats[i]` is a list of all hats preferred by the <img src="https://render.githubusercontent.com/render/math?math=i^{th}"> person.

Return *the number of ways that the n people wear different hats to each other*.

Since the answer may be too large, return it modulo <img src="https://render.githubusercontent.com/render/math?math=10^9"> + <img src="https://render.githubusercontent.com/render/math?math=7">.


#### Example 1:

```
Input: hats = [[3,4],[4,5],[5]]
Output: 1
Explanation: There is only one way to choose hats given the conditions. 
First person choose hat 3, Second person choose hat 4 and last one hat 5.

```

#### Example 2:

```
Input: hats = [[3,5,1],[3,5]]
Output: 4
Explanation: There are 4 ways to choose hats:
(3,5), (5,3), (1,3) and (1,5)

```

#### Example 3:

```
Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
Output: 24
Explanation: Each person can choose hats labeled from 1 to 4.
Number of Permutations of (1,2,3,4) = 24.

```


# Solutions

### Python
```
class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        '''
        Knapsack 0/1 Technique
        
        We have 10 people maximum here, so we use bitmask as a path
        hat1 -> 00100  # hat1 was chosen by person 2
        hat2 -> 01000  # hat2 was chosen by person 3
        
        01100 -> both hat1 and hat2 were chosen by person 2 and 3
        
        for example if we have 5 people final pathMask woud be 00011111
        
        '''
        
        # map persons to hat
        dic=collections.defaultdict(list)
        for person,persons in enumerate(hats):
            for hat in hats[person]:
                dic[hat].append(person)
        allHats=list(dic.keys())
        numPeople = len(hats)
        finalBytes = (1 << numPeople) - 1 # Fill bytes, turn 00000 into 00111
    
        @lru_cache(None)
        def dfs(hatIdx, pathMask):
            if pathMask==finalBytes:
                return 1
            if hatIdx==len(allHats):
                return 0
            
            res=0
            res += dfs(hatIdx+1, pathMask) # skip the hat

            curHat = allHats[hatIdx]
            for person in dic[curHat]:
                if pathMask & (1 << person):  # check if person is used
                    continue 
                res += dfs(hatIdx+1, pathMask | (1 << person))
            
            return res % 1000000007
        
        return dfs(0,0)
        
```
