### [Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/) <br>

Give a binary string `s`, return the number of non-empty substrings that have the same number of `0`'s and `1`'s, and all the `0`'s and all the `1`'s in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

 


#### Example 1:

```
Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

```

#### Example 2:

```
Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.

```

# Solutions

### Python
```
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        '''        
        An intuitive approach will be to group the binary string into chunks of 0s and 1s (sort of like             compressing). The answer will be simply to sum the min of length of neighboring chunks together.

        Here are some examples:

            '00001111' => [4, 4] => min(4, 4) => 4
            '00110' => [2, 2, 1] => min(2, 2) + min(2, 1) => 3
            '10101' => [1, 1, 1, 1, 1] => 4
        '''
        res=0
        consecutive=1
        arr=[]
        
        for i in range(1,len(s)):
            if s[i-1]==s[i]:
                consecutive += 1
            else:
                arr.append(consecutive)
                consecutive=1
        arr.append(consecutive)

        for i in range(1, len(arr)):
            res += min(arr[i-1], arr[i])
            
        return res
        
    
#     def countBinarySubstrings(self, s: str) -> int:
#         '''
#         Linear Scan
#         '''
#         n=len(s)
#         res=0
#         for i in range(1,n):
#             ch1=s[i-1]
#             ch2=s[i]
            
#             if ch1 != ch2:
#                 res += 1
#                 p1=i-1
#                 p2=i
#                 # print(s[p1:p2+1])
#                 while p1-1>=0 and p2+1<n and s[p1-1] == ch1 and s[p2+1] == ch2:
#                     res += 1
#                     p1 -= 1
#                     p2 += 1
#                     # print(s[p1:p2+1])
#         return res

```
