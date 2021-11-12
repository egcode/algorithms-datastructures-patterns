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

```
