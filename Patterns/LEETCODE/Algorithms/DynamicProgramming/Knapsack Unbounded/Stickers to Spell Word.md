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

### CPP
```
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size(), m = 1 << n; // if target has n chars, there will be m=2^n-1 subset of characters in target
        vector<uint> dp(m, -1); // use index 0 - 2^n-1 as bitmaps to represent each subset of all chars of target
        dp[0] = 0; // first thing we know is : dp[empty set] requires 0 stickers,
        for (int i = 0; i < m; i++) { // for every subset i, start from 00000...(emptyset) to 111111...(the target)
            if (dp[i] == -1) continue;
            for (string& s : stickers) { // try use each sticker as an char provider to populate a super-set of i,
                int sup = i;
                for (char c : s) { // to do that, for each char in the sticker, 
                    for (int r = 0; r < n; r++) {
                        if (target[r] == c && !((sup >> r) & 1)) { // try apply it on a missing char in the subset of target
                            sup |= 1 << r;
                            break;
                        }
                    }
                }
               // after you apply all possible chars in a sticker, you get an superset that take 1 extra sticker than subset
               // would take, so you can try to update the superset's minsticker number with dp[sub]+1;
                dp[sup] = min(dp[sup], dp[i] + 1); 
            }
        }
        return dp[m - 1]; // and the ultimate result
    }
};
```


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

