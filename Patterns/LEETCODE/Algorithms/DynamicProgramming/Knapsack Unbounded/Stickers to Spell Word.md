### [Stickers to Spell Word](https://leetcode.com/problems/stickers-to-spell-word/) <br>

We are given `n` different types of `stickers`. Each sticker has a lowercase English word on it.

You would like to spell out the given string `target` by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

*Return the minimum number of `stickers` that you need to spell out `target`*. If the task is impossible, return `-1`.

Note: In all test cases, all words were chosen randomly from the `1000` most common US English words, and `target` was chosen as a concatenation of two random words.



#### Example 1:

```
Input: stickers = ["with","example","science"], target = "thehat"
Output: 3
Explanation:
We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.

```

#### Example 2:

```
Input: stickers = ["notice","possible"], target = "basicbasic"
Output: -1
Explanation:
We cannot form the target "basicbasic" from cutting letters from the given stickers.

```


# Solutions

### Python
```
class Solution:    
    def minStickers(self, stickers: List[str], target: str) -> int:
        stickCount=[]
        for i,st in enumerate(stickers):
            stickCount.append({})
            for ch in st:
                stickCount[i][ch] = 1 + stickCount[i].get(ch, 0)
                
        dp = {} # key = subsequence of target | val = min num of stickers
        def dfs(path, last):
            if path in dp:
                return dp[path]
            res = 1 if last else 0
            
            remain=""
            for ch in path:
                if ch in last and last[ch]>0:
                    last[ch] -= 1                    
                else:
                    remain += ch
                    
            if remain:
                out = float("inf")
                for stick in stickCount:
                    if remain[0] not in stick:
                        continue
                    out = min(out, dfs(remain, stick.copy()))
                dp[remain]=out
                res += out
            return res
        
        res = dfs(target, {})
        return res if res != float("inf") else -1
```

