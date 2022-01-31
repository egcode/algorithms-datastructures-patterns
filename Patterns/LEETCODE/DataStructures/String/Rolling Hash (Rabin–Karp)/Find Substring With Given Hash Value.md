### [Find Substring With Given Hash Value](https://leetcode.com/problems/find-substring-with-given-hash-value/) <br>

The hash of a **0-indexed** string `s` of length `k`, given integers `p` and `m`, is computed using the following function:

 - <img src="https://render.githubusercontent.com/render/math?math=hash(s, p, m)"> = (<img src="https://render.githubusercontent.com/render/math?math=val(s[0])"> * <img src="https://render.githubusercontent.com/render/math?math=p^0"> + <img src="https://render.githubusercontent.com/render/math?math=val(s[1])"> * <img src="https://render.githubusercontent.com/render/math?math=p^1"> + ... + <img src="https://render.githubusercontent.com/render/math?math=val(s[k-1]">) * <img src="https://render.githubusercontent.com/render/math?math=p^{k-1}">) <img src="https://render.githubusercontent.com/render/math?math=mod m">.


Where `val(s[i])` represents the index of `s[i]` in the alphabet from `val('a') = 1` to `val('z') = 26`.

You are given a string `s` and the integers `power`, `modulo`, `k`, and `hashValue`. Return `sub`, *the* ***first substring*** *of* `s` *of length* `k` *such that* `hash(sub, power, modulo) == hashValue`.

The test cases will be generated such that an answer always **exists**.

A **substring** is a contiguous non-empty sequence of characters within a string.




#### Example 1:

```
Input: s = "leetcode", power = 7, modulo = 20, k = 2, hashValue = 0
Output: "ee"
Explanation: The hash of "ee" can be computed to be hash("ee", 7, 20) = (5 * 1 + 5 * 7) mod 20 = 40 mod 20 = 0. 
"ee" is the first substring of length 2 with hashValue 0. Hence, we return "ee".

```

#### Example 2:

```
Input: s = "fbxzaad", power = 31, modulo = 100, k = 3, hashValue = 32
Output: "fbx"
Explanation: The hash of "fbx" can be computed to be hash("fbx", 31, 100) = (6 * 1 + 2 * 31 + 24 * 312) mod 100 = 23132 mod 100 = 32. 
The hash of "bxz" can be computed to be hash("bxz", 31, 100) = (2 * 1 + 24 * 31 + 26 * 312) mod 100 = 25732 mod 100 = 32. 
"fbx" is the first substring of length 3 with hashValue 32. Hence, we return "fbx".
Note that "bxz" also has a hash of 32 but it appears later than "fbx".

```



# Solutions

### Python
```
class Solution:
    def subStrHash(self, s: str, power: int, modulo: int, k: int, hashValue: int) -> str:
        '''
        Rolling hash.
        The idea here is to do sliding window.
        Tricky part is that we should slide window from beginning
        because we need p^0 + p^1 + ... + p^k-1
        1. if we do that from the beginning we need to add p^k-1 at the end 
        of the window and divide whole window to p
        2. if we loop from the end - we always add val(s[i]) * p^0 where p^0 always 1,
        and we need to multiply whole window to p.
        
        Multiplication here is better than division.

        '''
        
        def val(ch):
            return (ord(ch)-ord('a')+1)           
        n=len(s)
        
        pk=pow(power,k)
        res=n
        win=0
        for i in range(n-1,-1,-1):
            # win*power=mult power to prev window
            # val(s[0]) * p^0 
            win = (win*power + val(s[i])) % modulo              
            
            if i+k<n:
                win = (win - val(s[i+k]) * pk) % modulo
                
            if win==hashValue:
                res=i
        
        # since we looped from the end we take last one
        return s[res:res+k]    

```
