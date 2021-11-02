### [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/) <br>

Given an integer `rowIndex`, return the `rowIndexth`-th (**0-indexed**) row of the **Pascal's triangle**.
In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:


<img src="../../../../../images/PascalTriangleAnimated2.gif">


#### Example 1:

```
Input: rowIndex = 3
Output: [1,3,3,1]

```


#### Example 2:

```
Input: rowIndex = 0
Output: [1]

```

#### Example 3:

```
Input: rowIndex = 1
Output: [1,1]
```


# Solutions

### Python
```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        '''
        1 0 0 0 0
        1 1 0 0 0
        1 2 1 0 0
        1 3 3 1 0
        1 4 6 4 1
        '''
        res=[0]*(rowIndex+1)
        res[0]=1
        
        for i in range(1, rowIndex+1):
            for j in range(1, i+1)[::-1]:
                res[j]=res[j]+res[j-1]
            
        return res
```
