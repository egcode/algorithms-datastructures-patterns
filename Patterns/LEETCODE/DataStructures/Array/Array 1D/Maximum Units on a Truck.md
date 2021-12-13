### [Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/) <br>

You are assigned to put some amount of boxes onto **one truck**. You are given a 2D array `boxTypes`, where `boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]`:

 - <img src="https://render.githubusercontent.com/render/math?math=numberOfBoxes_i"> is the number of boxes of type <img src="https://render.githubusercontent.com/render/math?math=i">.
 - <img src="https://render.githubusercontent.com/render/math?math=numberOfUnitsPerBox_i"> is the number of units in each box of the type <img src="https://render.githubusercontent.com/render/math?math=i">.


You are also given an integer `truckSize`, which is the **maximum** number of **boxes** that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed `truckSize`.

*Return the ***maximum*** total number of ***units*** that can be put on the truck*.



#### Example 1:

```
Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

```

#### Example 2:

```
Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91

```

# Solutions

### Python
```
class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        
        boxTypes.sort(reverse=True, key=lambda x: x[1]) # sort by numberOfUnitsPerBox
        res=0
        for numBoxes, numUnitsPerBox in boxTypes:
            if truckSize-numBoxes >= 0:
                res += numBoxes*numUnitsPerBox
                truckSize -= numBoxes
            else:
                res += truckSize*numUnitsPerBox
                truckSize=0
        
        return res

```
