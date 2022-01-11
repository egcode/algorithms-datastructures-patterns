class BIT:
    def __init__(self, n):
        self.bit=[0]*(n+1) # Get sum in range [1..idx], 1-based indexing

    def add(self, i, value): # pass 1 indexed index
        while i<len(self.bit):
            self.bit[i] += value
            i += i & (-i)
            
    def summ(self, i): # pass 1 indexed index
        summ=0
        while i>0:
            summ += self.bit[i]
            i -= i & (-i)
        return summ
    
    def summ_range(self, start, end): # pass 1 indexed index
        return self.summ(end)-self.summ(start-1) # excluding start


'''
    Example: 
        Range Sum Query - Mutable   
            problem: https://leetcode.com/problems/range-sum-query-mutable/
            github: https://github.com/egcode/algorithms-datastructures-patterns/blob/main/Patterns/LEETCODE/DataStructures/Tree/Binary%20Indexed%20Tree/Range%20Sum%20Query%20-%20Mutable.md

        Input
        ["NumArray", "sumRange", "update", "sumRange"]
        [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
        Output
        [null, 9, null, 8]
'''


class NumArray:
    
    def __init__(self, nums):
        '''
        Binary Indexed Tree (Fenwick Tree)            
        '''
        self.nums=nums
        self.bit=BIT(len(nums))
        for i in range(len(nums)):
            self.bit.add(i+1, nums[i])  # Fenwick is 1-indexed
        
    def update(self, index: int, val: int) -> None:
        diff=val-self.nums[index]
        self.bit.add(index+1, diff) # Fenwick is 1-indexed
        self.nums[index]=val
        
    def sumRange(self, left: int, right: int) -> int:
        return self.bit.summ_range(left+1, right+1) # Fenwick is 1-indexed


numArray = NumArray([1, 3, 5])
print("Sum range: "+str(numArray.sumRange(0, 2))) # return 1 + 3 + 5 = 9
numArray.update(1, 2);   # nums = [1, 2, 5]
print("Sum range: "+str(numArray.sumRange(0, 2))) # return 1 + 2 + 5 = 8
