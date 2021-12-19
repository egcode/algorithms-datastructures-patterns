### [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/) <br>

Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.



#### Example 1:

```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

```

#### Example 2:

```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

```

#### Example 3:

```
Input: s = ""
Output: 0

```


# Solutions

### Python
```
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack=[]
        ind_set=set()
        for i,l in enumerate(s):
            if stack and stack[-1][0]=='(' and l==')':
                letter, index = stack.pop()
                ind_set.remove(index)
                continue
            stack.append((l, i))
            ind_set.add(i)
    
        if len(ind_set)==0:
            return len(s)
        
        
        ind_arr=list(ind_set)
        ind_arr.sort()
        # Add borders
        ind_arr.insert(0, -1)
        ind_arr.append(len(s))
            
        res=0
        for i in range(1,len(ind_arr)):
            res=max(res, ind_arr[i]-ind_arr[i-1]-1)
        return res

```
