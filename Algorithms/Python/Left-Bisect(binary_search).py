def leftBisect(nums: List[int], target: int) -> int:
    l, r = 0, len(nums)
    while l < r :
        m = (l + r) // 2;
        if nums[m] < target:
            l = m + 1;
        else: 
            r = m;
    return l;

#      0  1  2  3  4  5  6
arr = [1, 2, 3, 3, 3, 6, 9]
# check whether the target exists. 
print(arr[leftBisect(arr, 2)]) # 2

#  find the leftmost index of the target if it exists. 
print(leftBisect(arr, 3)) # 2
print(leftBisect(arr, 9)) # 6

#  find the index of where the target should be if it doesn't exist. 
print(leftBisect(arr, 4)) # 5
print(leftBisect(arr, -5)) # 0
print(leftBisect(arr, 100)) # 7