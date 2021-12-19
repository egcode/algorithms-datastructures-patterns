### [Most Common Word](https://leetcode.com/problems/most-common-word/) <br>

Given a string `paragraph` and a string array of the banned words `banned`, return *the most frequent word that is not banned*. It is **guaranteed** there is **at least one word** that is not banned, and that the answer is **unique**.

The words in `paragraph` are **case-insensitive** and the answer should be returned in **lowercase**.



#### Example 1:

```
Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.

```

#### Example 2:

```
Input: paragraph = "a.", banned = []
Output: "a"

```



# Solutions

### Python
```
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        res=[0, ""]
        n=len(paragraph)
        count={}
        
        def is_letter(l):
            return l>='a' and l<='z'
        
        buffer=[]        
        for i in range(n):
            l=paragraph[i].lower()
        
            if is_letter(l):
                buffer.append(l)
                
            if not is_letter(l) or i==(n-1) and len(buffer)>0:
                word="".join(buffer)
                buffer=[]
                if word != "" and word not in banned:
                    count[word]=1+count.get(word, 0)
                    if count[word]>res[0]:
                        res=[count[word], word]
                    
        return res[1]

```
