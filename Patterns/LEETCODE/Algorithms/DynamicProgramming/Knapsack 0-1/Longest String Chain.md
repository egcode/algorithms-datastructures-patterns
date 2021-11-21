### [Longest String Chain](https://leetcode.com/problems/longest-string-chain/) <br>

You are given an array of `words` where each word consists of lowercase English letters.

<img src="https://render.githubusercontent.com/render/math?math=word_A"> is a **predecessor** of <img src="https://render.githubusercontent.com/render/math?math=word_B"> if and only if we can insert **exactly one** letter anywhere in <img src="https://render.githubusercontent.com/render/math?math=word_A"> **without changing the order of the other characters** to make it equal to <img src="https://render.githubusercontent.com/render/math?math=word_B">.

 - For example, `"abc"` is a predecessor of `"abac"`, while `"cba"` is not a **predecessor** of `"bcad"`.


A **word chain** is a sequence of words [<img src="https://render.githubusercontent.com/render/math?math=word_1">, <img src="https://render.githubusercontent.com/render/math?math=word_2">, ..., <img src="https://render.githubusercontent.com/render/math?math=word_k">] with `k >= 1`, where <img src="https://render.githubusercontent.com/render/math?math=word_1"> is a **predecessor** of <img src="https://render.githubusercontent.com/render/math?math=word_2">, <img src="https://render.githubusercontent.com/render/math?math=word_2"> is a **predecessor** of <img src="https://render.githubusercontent.com/render/math?math=word_3">, and so on. A single word is trivially a **word chain** with `k == 1`.

*Return the* **length** *of the* **longest possible word chain** *with words chosen from the given list of* `words`.



#### Example 1:

```
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

```

#### Example 2:

```
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

```

#### Example 3:

```
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

```

# Solutions

### Python
```
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        '''
        1) Sort by length
        2) Group by length, also store index in the dictionary
        3) Loop through words starting from longest one.
        4) Remove one letter from long word and compare with each word in group length-1
        5) If prefecessor store max value in dp array
        
        '''
        
        # sort by length            
        words.sort(key=len)
        
        # group by length
        groups=collections.defaultdict(list)
        for i in range(len(words)):
            groups[len(words[i])].append((words[i], i))
        
        
        def is_predec(cand, wrd)                                     :
            for i in range(len(wrd)):
                w=wrd[:i]+wrd[i+1:]
                if cand == w:
                    return True
            return False
        
        n=len(words)
        dp=[1]*n
        
        # starting from longest words
        for i in range(n)[::-1]:
            if (len(words[i])-1) not in groups.keys():
                continue
            for cand_wrd, index in groups[len(words[i])-1]:
                if is_predec(cand_wrd, words[i]):
                    
                    # Using max here, not just adding since we can have multiple paths running from same word.
                    dp[index] = max(dp[index], dp[i]+1)
        
        return max(dp)

```
