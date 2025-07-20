### [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) <br>

Given an integer array `nums` and an integer `k`, return the `k` *most frequent elements*. You may return the answer in **any order**.




#### Example 1:

```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

```

#### Example 2:

```
Input: nums = [1], k = 1
Output: [1]

```

# Solutions

### Python
```
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        h={}
        for num in nums:
            if num in h.keys():
                h[num]=h[num]+1
            else:
                h[num]=1
        
        arr=[]
        for (key, val) in h.items():
            arr.append((val, key))
        arr.sort(reverse=True ,key=lambda tup:tup[0])
        
        ans=[]
        for i in range(0, k):
            ans.append(arr[i][1])
        return ans
            
        return arr[:k]


    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        '''
        O(n)
        bucket sort.
        We use array's index as counter of elements
        '''
        n=len(nums)
        mp={}
        buckets = [[] for _ in range(n+1)]
        
        # counting using map
        for num in nums:
            mp[num]=mp.get(num, 0)+1
        
        # filling buckets with map values
        for key,val in mp.items():
            buckets[val].append(key)

        # getting `k` values from bukets
        res = []
        for bucket in reversed(buckets):
            if len(bucket)>0:
                for number in bucket:
                    res.append(number)
            if len(res)>=k:
                return res
        return res


```
