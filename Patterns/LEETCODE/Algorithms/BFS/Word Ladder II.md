### [Word Ladder II](https://leetcode.com/problems/word-ladder-ii/) <br>

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words <img src="https://render.githubusercontent.com/render/math?math=beginWord"> -> <img src="https://render.githubusercontent.com/render/math?math=s_1"> -> <img src="https://render.githubusercontent.com/render/math?math=s_2"> -> ... -> <img src="https://render.githubusercontent.com/render/math?math=s_k"> such that:

 - Every adjacent pair of words differs by a single letter.
 - Every <img src="https://render.githubusercontent.com/render/math?math=s_i"> for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
 - <img src="https://render.githubusercontent.com/render/math?math=s_k"> == <img src="https://render.githubusercontent.com/render/math?math=endWord">

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return *all the ***shortest transformation sequences*** from `beginWord` to `endWord`, or an empty list if no such sequence exists*. Each sequence should be returned as a list of the words [<img src="https://render.githubusercontent.com/render/math?math=beginWord">, <img src="https://render.githubusercontent.com/render/math?math=s_1">, <img src="https://render.githubusercontent.com/render/math?math=s_2">, ..., <img src="https://render.githubusercontent.com/render/math?math=s_k">].



#### Example 1:

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

```

#### Example 2:

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

```

# Solutions

### Python
```
class Solution:
#     def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
#         dic=collections.defaultdict(list)
#         n=len(beginWord)
        
#         for word in wordList:
#             for i in range(n):
#                 key=word[:i]+"*"+word[i+1:]
#                 dic[key].append(word)
                
                
#         q=collections.deque([(beginWord, 0, [beginWord])])
#         vis={beginWord:0}
#         res=[]
#         min_level=sys.maxsize
        
#         while len(q)>0:
#             wrd, level, path = q.pop()
            
#             vis[wrd]=level
            
#             if level>min_level:
#                 continue
            
#             if wrd == endWord:
#                 min_level=level                
#                 res.append(path)

                
#             for i in range(n):
#                 key=wrd[:i]+"*"+wrd[i+1:]
#                 if key in dic.keys():
#                     for w in dic[key]:
#                         if w not in vis.keys() or w in vis.keys() and vis[w]>level:
#                             q.appendleft((w, level+1, path + [w])) 
                            
#         return res

    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:

        wordList = set(wordList)
        res = []
        layer = {}
        layer[beginWord] = [[beginWord]]

        while layer:
            newlayer = collections.defaultdict(list)
            for w in layer:
                if w == endWord: 
                    res.extend(k for k in layer[w])
                else:
                    for i in range(len(w)):
                        for c in 'abcdefghijklmnopqrstuvwxyz':
                            neww = w[:i]+c+w[i+1:]
                            if neww in wordList:
                                newlayer[neww]+=[j+[neww] for j in layer[w]]

            wordList -= set(newlayer.keys())
            layer = newlayer

        return res

```
