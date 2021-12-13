### [Verifying an Alien Dictionary](https://leetcode.com/problems/verifying-an-alien-dictionary/) <br>

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different `order`. The `order` of the alphabet is some permutation of lowercase letters.

Given a sequence of `words` written in the alien language, and the `order` of the alphabet, return `true` if and only if the given `words` are sorted lexicographically in this alien language.




#### Example 1:

```
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

```

#### Example 2:

```
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

```


#### Example 3:

```
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

```


# Solutions

### Python
```
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        alphabet={}
        for i,ch in enumerate(order):
            alphabet[ch]=i
        
        for i in range(1, len(words)):
            w1=words[i-1]
            w2=words[i]
            
            shortest=min(len(w1), len(w2))
            for i in range(shortest):
                if w1[:i]==w2[:i]: # if i==0 we compare ""=="", so it's true
                    if alphabet[w1[i]] > alphabet[w2[i]]:
                        return False
                    
            if len(w1)>len(w2) and w2==w1[:len(w2)]:
                return False
        
        return True

```
