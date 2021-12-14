### [Word Ladder](https://leetcode.com/problems/word-ladder/) <br>

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words <img src="https://render.githubusercontent.com/render/math?math=beginWord"> -> <img src="https://render.githubusercontent.com/render/math?math=s_1"> -> <img src="https://render.githubusercontent.com/render/math?math=s_2"> -> ... -> <img src="https://render.githubusercontent.com/render/math?math=s_k"> such that:

 - Every adjacent pair of words differs by a single letter.
 - Every <img src="https://render.githubusercontent.com/render/math?math=s_i"> for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
 - <img src="https://render.githubusercontent.com/render/math?math=s_k"> == <img src="https://render.githubusercontent.com/render/math?math=endWord">


Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return *the ***number of words*** in the ***shortest transformation sequence*** from `beginWord` to `endWord`, or `0` if no such sequence exists*.



#### Example 1:

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

```

#### Example 2:

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

```


# Solutions

### Python
```
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        '''
        BFS
        '''
        l=len(beginWord) # All words has same length
        dic=collections.defaultdict(list)
        
        for word in wordList:
            for i in range(l):
                cand=word[:i]+"*"+word[i+1:]
                dic[cand].append(word)
                
        q=collections.deque([(beginWord, 1)])
        vis={beginWord}
        
        while q:
            wrd, path=q.pop()
            
            if wrd==endWord:
                return path
            
            for i in range(l):
                cand=wrd[:i]+"*"+wrd[i+1:]
                if cand in dic.keys():
                    for word in dic[cand]:
                        if word in vis: continue
                        vis.add(word)
                        q.appendleft((word, path+1))
                    
        return 0

```
