### [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) <br>

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

<img src="../../../../../images/17Telephone-keypad2.png">



#### Example 1:

```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

```

#### Example 2:

```
Input: digits = ""
Output: []

```


#### Example 3:

```
Input: digits = "2"
Output: ["a","b","c"]

```


# Solutions

### Python
```
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dic={}
        dic["2"]=["a", "b", "c"]
        dic["3"]=["d", "e", "f"]
        dic["4"]=["g", "h", "i"]
        dic["5"]=["j", "k", "l"]
        dic["6"]=["m", "n", "o"]
        dic["7"]=["p", "q", "r", "s"]
        dic["8"]=["t", "u", "v"]
        dic["9"]=["w", "x", "y", "z"]   
        
        n=len(digits)
        if n==0: return []
        res=[]
        
        def dfs(index, path):
            if len(path)==n:
                res.append("".join(path))
                return
            if index==n:
                return
            
            digit=digits[index]
            for ch in dic[digit]:
                dfs(index+1, path+[ch])
                
                
        dfs(0, [])
        
        return res
```
