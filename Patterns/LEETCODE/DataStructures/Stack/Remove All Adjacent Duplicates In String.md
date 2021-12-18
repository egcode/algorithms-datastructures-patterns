### [Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/) <br>

You are given a string `s` consisting of lowercase English letters. A **duplicate removal** consists of choosing two **adjacent** and **equal** letters and removing them.

We repeatedly make **duplicate removals** on `s` until we no longer can.

Return *the final string after all such duplicate removals have been made*. It can be proven that the answer is **unique**.

 



#### Example 1:

```
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

```

#### Example 2:

```
Input: s = "azxxzy"
Output: "ay"

```



# Solutions

### Python
```
class Solution:
#     def removeDuplicates(self, s: str) -> str:
#         '''
#         Recursion. SLOW
#         '''
#         def recurse(string):
            
#             for i in range(1, len(string)):
#                 if string[i]==string[i-1]:
#                     return recurse(string[:i-1]+string[i+1:])
                
#             return string
        
#         return recurse(s)
    
    
    def removeDuplicates(self, s: str) -> str:
        '''
        Stack
        '''
        stack=[]
        for ch in s:
            if stack and ch==stack[-1]:
                stack.pop()
            else:
                stack.append(ch)
        
        return ''.join(stack)
```
