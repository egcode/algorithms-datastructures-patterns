### [Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/) <br>

Given a string s of `'('` , `')'` and lowercase English characters.

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting *parentheses string* is valid and return **any** valid string.

Formally, a *parentheses string* is valid if and only if:

 - It is the empty string, contains only lowercase characters, or
 - It can be written as `AB` (`A` concatenated with `B`), where `A` and `B`are valid strings, or
 - It can be written as `(A)`, where `A` is a valid string.



#### Example 1:

```
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

```

#### Example 2:

```
Input: s = "a)b(c)d"
Output: "ab(c)d"

```

#### Example 3:

```
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

```

#### Example 4:

```
Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"

```


# Solutions

### Python
```
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack=[]
        
        for i,ch in enumerate(s):
            if ch=='(':
                stack.append((ch, i))
            elif ch==')':
                if stack and stack[-1][0]=='(':
                    stack.pop()
                else:
                    stack.append((ch, i))
                                    
        # Deleting from end to start
        while stack:
            _, i = stack.pop()
            s=s[:i]+s[i+1:]
            
        return s

```
