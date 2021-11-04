### [Best Sightseeing Pair](https://leetcode.com/problems/best-sightseeing-pair/) <br>

You are given an integer array `values` where `values[i]` represents the value of the `i`-th sightseeing spot. Two sightseeing spots `i` and `j` have a **distance** `j - i` between them.

The score of a pair (`i < j`) of sightseeing spots is `values[i] + values[j] + i - j`: the sum of the values of the sightseeing spots, minus the distance between them.

Return the **maximum score of a pair of sightseeing spots**.

#### Example 1:

```
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

```

#### Example 2:

```
Input: values = [1,2]
Output: 2

```

# Solutions

### Python
```
class Solution:
#     def maxScoreSightseeingPair(self, values: List[int]) -> int:
#         '''
#         Time Limit Exceeded
#         '''
#         res=-sys.maxsize
#         n=len(values)
        
#         for i in range(n):
#             for j in range(n):
#                 if i==j: continue
#                 res=max(res, values[i]+values[j]+min(i,j)-max(i,j))
        
#         return res
        
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        '''
        Kadane's Algorithm
                
        1.We maintain the maximum of A[i] + i for all previous visited spots
        2.We sum the maximum of A[i] + i with current spot A[j],
        which is A[i] + i + A[j] - j]. 
        We also maintain this value, 
        which will become the final max score after iteration over the entire array.        
        
        '''
        res = 0
        cur_max = 0
        
        for i in range(len(values)):
            res=max(res, cur_max + values[i]-i)
            cur_max=max(cur_max, values[i]+i)
        return res

```
