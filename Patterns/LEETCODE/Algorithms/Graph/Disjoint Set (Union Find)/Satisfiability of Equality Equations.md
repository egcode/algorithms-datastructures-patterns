### [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/) <br>

You are given an array of strings `equations` that represent relationships between variables where each string `equations[i]` is of length `4` and takes one of two different forms: "<img src="https://render.githubusercontent.com/render/math?math=x_i==y_i">" or "<img src="https://render.githubusercontent.com/render/math?math=x_i!=y_i">".Here, <img src="https://render.githubusercontent.com/render/math?math=x_i"> and <img src="https://render.githubusercontent.com/render/math?math=y_i"> are lowercase letters (not necessarily different) that represent one-letter variable names.

Return `true` *if it is possible to assign integers to variable names so as to satisfy all the given equations, or `false` otherwise*.


#### Example 1:

```
Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

```

#### Example 2:

```
Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

```



# Solutions

### Python
```
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        '''
        Union Find
        
        store letters as integers of from 0 to 25
        '''
        root=[i for i in range(26)]
    
        def find(x):
            if x == root[x]:
                return x
            root[x] = find(root[x])
            return root[x]

        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX != rootY:
                root[rootY] = rootX
                 
        for eq in equations:
            if eq[1]=='=':
                union(ord(eq[0])-ord('a'), ord(eq[3])-ord('a'))
                
        for eq in equations:
            if eq[1]=='!':
                if find(ord(eq[0])-ord('a')) == find(ord(eq[3])-ord('a')):
                    return False
                
        return True

```
