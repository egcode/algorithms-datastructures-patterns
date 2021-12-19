### [Word Squares](https://leetcode.com/problems/word-squares/) <br>

Given an array of **unique** strings `words`, return all the [word squares](https://en.wikipedia.org/wiki/Word_square) *you can build from* `words`. The same word from `words` can be used **multiple times**. You can return the answer in **any order**.

A sequence of strings forms a valid **word square** if the kth row and column read the same string, where `0 <= k < max(numRows, numColumns)`.

 - For example, the word sequence `["ball","area","lead","lady"]` forms a word square because each word reads the same both horizontally and vertically.
 



#### Example 1:

```
Input: words = ["area","lead","wall","lady","ball"]
Output: [["ball","area","lead","lady"],["wall","area","lead","lady"]]
Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

```

#### Example 2:

```
Input: words = ["abat","baba","atan","atal"]
Output: [["baba","abat","baba","atal"],["baba","abat","baba","atan"]]
Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

```



# Solutions

### Python
```
class Solution:
    def wordSquares(self, words: List[str]) -> List[List[str]]:
        '''
        b a l l 
        a r e a
        l e a d
        l a d y
        
        - In `dfs` function we add word to word_squares array and check if `prefix_from_vertical` is in `prefixHashTable`
        - if Yes loop through all words in that hash map
                
        '''
        N = len(words[0])
        res = []
                
        
        def dfs(step, word_squares):
            if step == N:
                res.append(word_squares[:])
                return
            
            letters=[word[step] for word in word_squares]
            prefix_from_vertical = ''.join(letters)
            for candidate in prefixHashTable[prefix_from_vertical]:
                dfs(step+1, word_squares + [candidate])
        

        # build prefix hashtable
        # eg: {'a': {'area'}, 'ar': {'area'}, 'are': {'area'}, 'l': {'lead', 'lady'}, 'le': {'lead'}, 'lea': {'lead'}, 'w': {'wall'}, 'wa': {'wall'}, 'wal': {'wall'}, 'la': {'lady'}, 'lad': {'lady'}, 'b': {'ball'}, 'ba': {'ball'}, 'bal': {'ball'}}
        prefixHashTable = collections.defaultdict(set)
        for word in words:
            for i in range(1, len(word)):
                prefixHashTable[word[:i]].add(word)
                
        word_squares = []
        for word in words:
            word_squares = [word]
            dfs(1, word_squares) # Start from 1 here because first word is same that goes vertical and horizontal
            
        return res


#     def wordSquares(self, words: List[str]) -> List[List[str]]:
#         '''
#         DFS Time Limit Exceeded                
#         '''

        
#         N = len(words[0])
#         res = []
                
        
#         def dfs(step, word_squares):
#             if step == N:
#                 res.append(word_squares[:])
#                 return

#             prefix_from_vertical = ''.join([word[step] for word in word_squares])
#             for candidate in words:
#                 if candidate.startswith(prefix_from_vertical):
#                     dfs(step+1, word_squares + [candidate])
        

#         word_squares = []
#         for word in words:
#             word_squares = [word]
#             dfs(1, word_squares)
            
#         return res

```
