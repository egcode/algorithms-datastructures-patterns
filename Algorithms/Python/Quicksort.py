    
def qsort(nums, l, h):
    if l<h:
        p=partition(nums, l, h)
        qsort(nums, l, p-1)
        qsort(nums, p+1, h)
    return nums
    
def partition(nums, l, h):
    pivot=nums[h]
    i=l
    for j in range(l, h):
        if nums[j] < pivot:
            nums[j], nums[i] = nums[i], nums[j]
            i += 1
    nums[h], nums[i] = nums[i], nums[h]
    return i


nums=[-4,0,7,4,5,-5,2,8,6,1,4,19,-1,0,-7,-1]
print(str(nums)+" - Before")
qsort(nums, 0, len(nums)-1)
print(str(nums)+" - After")
