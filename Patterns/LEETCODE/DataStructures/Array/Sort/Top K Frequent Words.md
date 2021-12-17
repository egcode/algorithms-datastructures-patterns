### [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/) <br>

Given an array of strings `words` and an integer `k`, return *the* `k` *most frequent strings*.

Return the answer **sorted** by **the frequency** from highest to lowest. Sort the words with the same frequency by their **lexicographical order**.



#### Example 1:

```
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

```

#### Example 2:

```
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

```



# Solutions

### Python
```
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:  
        '''
        Input:                  ["i", "love", "leetcode", "i", "love", "coding"]

        Frequency:              {"i": 2, "love": 2, "leetcode": 1, "coding": 1}

        Group by frequency:     { 1: ["leetcode", "coding"], 2: ["i", "love"] }

        '''
        # Count Frequency:              {"i": 2, "love": 2, "leetcode": 1, "coding": 1}
        counter=collections.Counter(words)
        
        # Group by frequency:     { 1: ["leetcode", "coding"], 2: ["i", "love"] }        
        biggest=-sys.maxsize
        freq=collections.defaultdict(list)
        for key, val in counter.items():
            freq[val].append(key)
            biggest=max(biggest, val)
            
            
        # Sort Frequency Groups and contatenate to result            
        res=[]
        i=biggest
        while len(res)<k and i>=0:
            if i in freq.keys():
                freq[i].sort()
                res += freq[i]
            i -= 1
        
        return res[:k]

```
