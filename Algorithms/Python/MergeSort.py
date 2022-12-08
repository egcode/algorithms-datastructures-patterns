def merge(left, right):
    res=[]
    l=0
    r=0
    while l < len(left) and r < len(right):
        if left[l] < right[r]:
            res.append(left[l])
            l += 1
        else:
            res.append(right[r])
            r += 1
    if l < (len(left)):
        for i in range(l, len(left)):
            res.append(left[i])
    if r < (len(right)):
        for i in range(r,len(right)):
            res.append(right[i])
    return res

def mergeSort(nums):
    '''
    merge sort
    '''
    if len(nums)==1:
        return nums
    midIndex=len(nums)//2
    left_side=mergeSort(nums[midIndex:])
    right_side=mergeSort(nums[:midIndex])
    return merge(left_side, right_side)


nums=[-4,0,7,4,5,-5,2,8,6,1,4,19,-1,0,-7,-1]
print(str(nums)+" - Before")
nums=mergeSort(nums)
print(str(nums)+" - After")
