### [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/) <br>

You are given two lists of closed intervals, firstList and secondList, where <img src="https://render.githubusercontent.com/render/math?math=firstList[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=start_i">, <img src="https://render.githubusercontent.com/render/math?math=end_i">] and <img src="https://render.githubusercontent.com/render/math?math=secondList[j]"> = [<img src="https://render.githubusercontent.com/render/math?math=start_j">, <img src="https://render.githubusercontent.com/render/math?math=end_j">]. Each list of intervals is pairwise disjoint and in sorted order.

Return *the intersection of these two interval lists*.

A **closed interval** `[a, b]` (with `a <= b`) denotes the set of real numbers `x` with `a <= x <= b`.

The **intersection** of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of `[1, 3]` and `[2, 4]` is `[2, 3]`.



#### Example 1:
<img src="../../../../../images/986interval1.png">

```
Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

```

#### Example 2:

```
Input: firstList = [[1,3],[5,9]], secondList = []
Output: []

```

#### Example 3:

```
Input: firstList = [], secondList = [[4,8],[10,12]]
Output: []

```

#### Example 4:

```
Input: firstList = [[1,7]], secondList = [[3,10]]
Output: [[3,7]]

```


# Solutions

### Python
```
class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        '''
        After comparing skip interval with smallest endpoint
        '''
    
        p1=0
        p2=0
        res=[]
        while p1<len(firstList) and p2<len(secondList):
            i1=firstList[p1]
            i2=secondList[p2]
            
            start=max(i1[0], i2[0])
            end=min(i1[1], i2[1])
            prod = start-end
            
            if prod <= 0:
                res.append([start, end])
                
            if i1[1]>i2[1]:
                p2 += 1
            else:
                p1 +=1
                
        return res

```
