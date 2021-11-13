### [Group Anagrams](https://leetcode.com/problems/group-anagrams/) <br>

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


#### Example 1:

```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

```

#### Example 2:

```
Input: strs = [""]
Output: [[""]]

```


#### Example 3:

```
Input: strs = ["a"]
Output: [["a"]]

```



# Solutions

### Python
```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups=collections.defaultdict(list)
        
        for st in strs:
            arr=list(st)
            arr.sort()
            key="".join(arr)
            groups[key].append(st)
            
        return list(groups.values())
        
```
