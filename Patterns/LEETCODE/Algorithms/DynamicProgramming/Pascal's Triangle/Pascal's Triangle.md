### [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) <br>

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.
In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

<img src="../../../../../images/PascalTriangleAnimated2.gif">


#### Example 1:

```
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

```


#### Example 2:

```
Input: numRows = 1
Output: [[1]]

```


# Solutions

### Python
```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        '''
        1 0 0 0 0
        1 1 0 0 0
        1 2 1 0 0
        1 3 3 1 0
        1 4 6 4 1
        '''        
        res=[[1]]
        row=[0]*(numRows+1)
        row[0]=1
        
        for i in range(1, numRows):
            for j in range(1, i+1)[::-1]:
                row[j]=row[j]+row[j-1]
            res.append(row[:i+1])
        
        return res
        
```
