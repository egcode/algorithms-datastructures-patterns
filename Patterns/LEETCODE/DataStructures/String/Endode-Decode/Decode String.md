### [Decode String](https://leetcode.com/problems/decode-string/) <br>

Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, `k`. For example, there won't be input like `3a` or `2[4]`.

 



#### Example 1:

```
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

```

#### Example 2:

```
Input: s = "3[a2[c]]"
Output: "accaccacc"

```

#### Example 3:

```
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

```

#### Example 4:

```
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"

```



# Solutions

### Python
```
class Solution:
#     def decodeString(self, s: str) -> str:
#         res=""
        
#         def dfs(s, count):            
#             out=""
#             ind=0
#             digit=""            
#             for _ in range(0, count):
#                 i=0
#                 while i<len(s):
#                     l=s[i]
#                     if l >= "0" and l <= "9":
#                         digit += l
#                     elif l >= "a" and l <= "z":
#                         out += l
#                     elif l == "[" and digit != "":
                        
#                         fast=i+2
#                         dph=0
#                         run=True
#                         while run:
#                             ll=s[fast]
#                             if ll=="]":
#                                 if dph==0:
#                                     break
#                                 dph -= 1
#                             elif ll=="[":
#                                 dph += 1
#                             fast += 1
                        
#                         ss=s[i+1:fast]
#                         out += dfs(ss, int(digit))
#                         digit=""
#                         i=fast
#                         continue
#                     i += 1
#             return out
        
#         res = dfs(s, 1)
#         return res
    
    
    def decodeString(self, s: str) -> str:
        '''
        Using stack
        
        With example:
            "1[ab2[xz4[y]]]"
            
        first time  when we meet ']' character we have:
        stack=["",1,"ab",2,"xz",4]
        cur_string=y
        
        digit from stack should be multiplied with `cur_string` and appended to string before that digit:
        eg:
          cur_string = 'xz' + 4*cur_string
        
        '''
        
        stack=[]
        cur_string=''
        cur_num=0
        
        for c in s:
            if c.isdigit():
                cur_num = cur_num*10 + int(c)
            elif c=='[':
                stack.append(cur_string)
                stack.append(cur_num)
                cur_string=''
                cur_num=0
            elif c==']':
                num=stack.pop() # num from stack should be multiply with cur_string
                prev_string=stack.pop()
                cur_string = prev_string + num*cur_string
            else:
                cur_string += c
                
        return cur_string

```
