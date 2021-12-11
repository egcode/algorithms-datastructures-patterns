### [Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/) <br>

Given an integer array `nums`, handle multiple queries of the following types:

 - **Update** the value of an element in `nums`.
 - Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.


Implement the `NumArray` class:

 - `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
 - `void update(int index, int val)` **Updates** the value of `nums[index]` to be `val`.
 - `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).


#### Example 1:

```
Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1, 2, 5]
numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
```


# Solutions

### Python
```
class NumArray:
    
    def __init__(self, nums: List[int]):
        '''
        Binary Indexed Tree (Fenwick Tree)
        
        Explanation:
            https://www.youtube.com/watch?v=CWDQJGaN1gY
            
        
        '''
        self.arr=nums
        self.n=len(nums)
        self.arr_BIT = self.initBIT(nums)
        
        
    def update(self, index: int, val: int) -> None:
        self.updateBIT(self.arr_BIT, index, val-self.arr[index])
        self.arr[index]=val
        
    def sumRange(self, left: int, right: int) -> int:
        s=self.getsumBIT(right, self.arr_BIT)-self.getsumBIT(left-1, self.arr_BIT)
        return s
    
    '''
    Binary Indexed Tree Helper functions
    '''
    def initBIT(self, arr):
        
        # Create and initialize arr_BIT[] as 0
        arr_BIT = [0]*(self.n+1)

        # Store the actual values in arr_BIT[] using update()
        for i in range(self.n):
            self.updateBIT(arr_BIT, i, arr[i])

        return arr_BIT
    
    
    def getsumBIT(self,i, arr_BIT):
        s = 0 #initialize result

        # index in arr_BIT[] is 1 more than the index in arr[]
        i = i+1

        # Traverse ancestors of arr_BIT[index]
        while i > 0:

            # Add current element of arr_BIT to sum
            s += arr_BIT[i]

            # Move index to parent node in getSum View
            # 1 - 2's Complement
            # 2 - AND bitwise operator with original number
            # 3 - Substract from original number
            i -= i & (-i)
        return s

    # Updates a node in Binary Index Tree (arr_BIT) at given index
    # in arr_BIT. The given value 'val' is added to arr_BIT[i] and
    # all of its ancestors in tree.
    def updateBIT(self, arr_BIT, i ,v):

        # index in arr_BIT[] is 1 more than the index in arr[]
        i += 1

        # Traverse all ancestors and add 'val'
        while i <= self.n:

            # Add 'val' to current node of BI Tree
            arr_BIT[i] += v

            # Update index to that of parent in update View
            # 1 - 2's Complement
            # 2 - AND bitwise operator with original number
            # 3 - Add to original number            
            i += i & (-i)

```
