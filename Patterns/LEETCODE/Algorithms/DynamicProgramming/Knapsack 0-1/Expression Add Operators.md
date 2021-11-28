### [Expression Add Operators](https://leetcode.com/problems/expression-add-operators/) <br>

Given a string `num` that contains only digits and an integer target, return **all possibilities** *to insert the binary operators* `'+'`, `'-'`, *and/or* `'*'` *between the digits of* `num` *so that the resultant expression evaluates to the* `target` *value*.

Note that operands in the returned expressions **should not** contain leading zeros.




#### Example 1:

```
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

```

#### Example 2:

```
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.

```

#### Example 3:

```
Input: num = "105", target = 5
Output: ["1*0+5","10-5"]
Explanation: Both "1*0+5" and "10-5" evaluate to 5.
Note that "1-05" is not a valid expression because the 5 has a leading zero.

```

#### Example 4:

```
Input: num = "00", target = 0
Output: ["0*0","0+0","0-0"]
Explanation: "0*0", "0+0", and "0-0" all evaluate to 0.
Note that "00" is not a valid expression because the 0 has a leading zero.

```

#### Example 5:

```
Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.

```


# Solutions

### Python
```
class Solution:
#     def addOperators(self, num: str, target: int) -> List[str]:
#         N = len(num)
#         answers = []
#         def recurse(index, prev_operand, current_operand, value, string):

#             # Done processing all the digits in num
#             if index == N:

#                 # If the final value == target expected AND
#                 # no operand is left unprocessed
#                 if value == target and current_operand == 0:
#                     answers.append("".join(string[1:]))
#                     # answers.append("".join(string))
                    
#                 return

#             # Extending the current operand by one digit
#             current_operand = current_operand*10 + int(num[index])
#             str_op = str(current_operand)

#             # To avoid cases where we have 1 + 05 or 1 * 05 since 05 won't be a
#             # valid operand. Hence this check
#             if current_operand > 0:

#                 # NO OP recursion
#                 recurse(index + 1, prev_operand, current_operand, value, string)

#             # ADDITION
#             string.append('+')
#             string.append(str_op)
#             recurse(index + 1, current_operand, 0, value + current_operand, string)
#             string.pop()
#             string.pop()

#             # Can subtract or multiply only if there are some previous operands
#             if string:

#                 # SUBTRACTION
#                 string.append('-')
#                 string.append(str_op)
#                 recurse(index + 1, -current_operand, 0, value - current_operand, string)
#                 string.pop()
#                 string.pop()

#                 # MULTIPLICATION
#                 string.append('*')
#                 string.append(str_op)
#                 recurse(index + 1, current_operand * prev_operand, 0, value - prev_operand + (current_operand * prev_operand), string)
#                 string.pop()
#                 string.pop()
#         recurse(0, 0, 0, 0, [])    
#         return answers


    def addOperators(self, num: str, target: int) -> List[str]:
        res=[]
        n=len(num)
        def dfs(cand, i, total, prev_add):

            if i==n and total==target:
                res.append(cand)
                return
            
            for j in range(i+1, n+1):
                s=num[i:j]
                d=int(s)
                
                if num[i]=='0' and s != '0':
                    continue
                
                if cand=='':
                    dfs(s,  j, d, d)
                else:
                    dfs(cand+'+'+s, j, total+d, d)
                    dfs(cand+'-'+s, j, total-d, -d)
                    dfs(cand+'*'+s, j, total - prev_add + prev_add*d, prev_add*d)
        
        dfs('',0,0,0)
        return res

```
