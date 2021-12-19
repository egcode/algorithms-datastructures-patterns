### [Partition Labels](https://leetcode.com/problems/partition-labels/) <br>

You are given a string `s`. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Return *a list of integers representing the size of these parts*.

 



#### Example 1:

```
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

```

#### Example 2:

```
Input: s = "eccbbbbdec"
Output: [10]

```



# Solutions

### Python
```
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        last={}
        for i, letter in enumerate(S):
            last[letter]=i
            
        res=[]
        end=0
        start=0
        for i in range(len(S)):
            letter=S[i]
            end=max(end, last[letter])
            if end==i:
                res.append((end-start)+1)
                start=i+1
        
        return res
        
```
