### [Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/) <br>

Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return *all the possible results. You may return the answer in **any order***.


#### Example 1:

```
Input: s = "()())()"
Output: ["(())()","()()()"]

```

#### Example 2:

```
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

```

#### Example 3:

```
Input: s = ")("
Output: [""]

```



# Solutions

### Python
```
class Solution: 
    def removeInvalidParentheses(self, s: str) -> List[str]:
        
        def is_valid(ss):
            _stack=[]
            for ch in ss:
                if ch=='(':
                    _stack.append(ch)
                elif ch==')':
                    if _stack and _stack[-1]=='(':
                        _stack.pop()
                    else:
                        _stack.append(ch)
            return len(_stack)==0
                    
        
        # Getting invalid Parentheses
        stack=[]
        for ch in s:
            if ch=='(':
                stack.append(ch)
            elif ch==')':
                if stack and stack[-1]=='(':
                    stack.pop()
                else:
                    stack.append(ch)
        
        # Calculate
        res=[]
        vis=set()
        vis.add(s)
        
        def dfs(invalid, path):
            if len(invalid)==0:
                if is_valid(path):
                    res.append(path)
                return
            
            to_delete=invalid[0]
            for i in range(len(path)):
                if path[i]==to_delete:
                    cand=path[:i]+path[i+1:]
                    if cand not in vis:
                        vis.add(cand)
                        dfs(invalid[1:], cand)            
        
        dfs(stack, s)
        return res

```
