def leftBisect(nums, target) -> int:
    l, r = 0, len(nums)
    while l < r :
        # m = (l + r) // 2;
        m=l+(r-l)//2
        if nums[m] < target:
            l = m + 1;
        else: 
            r = m;
    return l;

#      0  1  2  3  4  5  6  7   8   9   10  11  12  13  14
arr = [1, 2, 3, 3, 3, 6, 9, 10, 11, 12, 12, 12, 12, 18, 20]
print(30*"-")
print("check whether the target exists")
i=leftBisect(arr, 2) # 2
if i<len(arr) and arr[i]==2:
    print("2 exists")
else:
    print("2 does not exists")
    
print(30*"-")    
print("find the leftmost index of the target if it exists")
print(leftBisect(arr, 3)) # 2
print(leftBisect(arr, 12)) # 9
print(leftBisect(arr, 9)) # 6

print(30*"-")    
print("find the rightmost index of the target if it exists")
rightToFind=3
print(leftBisect(arr, rightToFind+1)-1) # 4
rightToFind=12
print(leftBisect(arr, rightToFind+1)-1) # 12


print(30*"-")
print("find the index of where the target should be if it doesn't exist")
print(leftBisect(arr, 4)) # 5
print(leftBisect(arr, -5)) # 0
print(leftBisect(arr, 100)) # 15