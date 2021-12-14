### [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) <br>

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

 - Open brackets must be closed by the same type of brackets.
 - Open brackets must be closed in the correct order.


#### Example 1:

```
Input: s = "()"
Output: true

```

#### Example 2:

```
Input: s = "()[]{}"
Output: true

```


#### Example 3:

```
Input: s = "(]"
Output: false

```


#### Example 4:

```
Input: s = "([)]"
Output: false

```


#### Example 5:

```
Input: s = "{[]}"
Output: true

```


# Solutions

### Python
```
class Solution:
    def isValid(self, s: str) -> bool:
        stack=[]
        
        for i in range(len(s)):
            b=s[i]
            if b=="(" or b=="{" or b=="[":
                stack.append(s[i])
            else:
                if len(stack)==0:
                    return False
                if stack[-1]=="(" and b==")" or stack[-1]=="{" and b=="}" or stack[-1]=="[" and b=="]":
                    p=stack.pop()
                else:
                    return False
                
        return len(stack)==0
```
