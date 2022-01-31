def majorityElement(nums) -> int:
    '''
    Boyer-Moore Voting Algorithm
     Example from 169. Majority Element problem.
    '''
    count = 0
    candidate = None

    for num in nums:
        if count == 0:
            candidate = num
            
        add=-1
        if num==candidate:
            add=1
        count += add

    return candidate        


nums = [2,2,1,1,1,2,2]
print("Majority element in array: "+str(nums)+"   is: "+ str(majorityElement(nums)))