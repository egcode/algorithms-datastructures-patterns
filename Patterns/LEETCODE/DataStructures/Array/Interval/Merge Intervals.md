### [Merge Intervals](https://leetcode.com/problems/merge-intervals/) <br>

Given an array of `intervals` where <img src="https://render.githubusercontent.com/render/math?math=intervals[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=start_i">, <img src="https://render.githubusercontent.com/render/math?math=end_i">], merge all overlapping intervals, and return *an array of the non-overlapping intervals that cover all the intervals in the input*.




#### Example 1:

```
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

```

#### Example 2:

```
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

```

# Solutions

### Python
```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res=[]
        
        intervals.sort(key=lambda tup:tup[0])
        
        for inter in intervals:
            if res:
                i1=res[-1]
                i2=inter
                
                prod=max(i1[0], i2[0])-min(i1[1], i2[1])
                if prod <= 0:
                    # intersect
                    res[-1]=[min(i1[0], i1[0]), max(i1[1], i2[1])]
                else:
                    # not intersect
                    res.append(inter)
            else:
                res.append(inter)
                
        return res
```
