### [Valid Number](https://leetcode.com/problems/valid-number/) <br>

A **valid number** can be split up into these components (in order):

 1. A **decimal number** or an **integer**.
 2. (Optional) An `'e'` or `'E'`, followed by an **integer**.
 
A **decimal number** can be split up into these components (in order):

 1. (Optional) A sign character (either `'+'` or `'-'`).
 2. One of the following formats:
    - One or more digits, followed by a dot `'.'`.
    - One or more digits, followed by a dot `'.'`, followed by one or more digits.
    - A dot `'.'`, followed by one or more digits.

An **integer** can be split up into these components (in order):

(Optional) A sign character (either `'+'` or `'-'`).
One or more digits.
For example, all the following are valid numbers: `["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]`, while the following are not valid numbers: [`"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]`.

Given a string `s`, return `true` *if* `s` *is a* ***valid number***.
 

#### Example 1:

```
Input: s = "0"
Output: true

```

#### Example 2:

```
Input: s = "e"
Output: false

```

#### Example 3:

```
Input: s = "."
Output: false

```

#### Example 4:

```
Input: s = ".1"
Output: true

```


# Solutions

### Python
```
class Solution:
    def isNumber(self, s: str) -> bool:
        '''
        With conditions
        '''
        
        met_num=False
        met_dot=False
        met_e=False
        
        s = s.strip()
        for i in range(len(s)):
            l=s[i]
            
            if l in ['+', '-']:
                if i>0 and s[i-1] != 'e':
                    return False
            elif l=='.':
                if met_dot or met_e:
                    return False
                met_dot=True
            elif l=='e' or l=='E':
                if met_e or met_num==False:
                    return False
                met_num=False
                met_e=True
            elif l.isdigit():
                met_num=True
            else:
                return False
        
        return met_num

```
