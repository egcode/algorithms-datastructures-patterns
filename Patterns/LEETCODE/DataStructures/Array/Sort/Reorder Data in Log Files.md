### [Reorder Data in Log Files](https://leetcode.com/problems/reorder-data-in-log-files/) <br>

You are given an array of `logs`. Each log is a space-delimited string of words, where the first word is the **identifier**.

There are two types of logs:

 - **Letter-logs**: All words (except the identifier) consist of lowercase English letters.
 - **Digit-logs**: All words (except the identifier) consist of digits.


Reorder these logs so that:

 1. The **letter-logs** come before all **digit-logs**.
 2. The **letter-logs** are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
 3. The **digit-logs** maintain their relative ordering.


Return *the final order of the logs*.


#### Example 1:

```
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".

```

#### Example 2:

```
Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]

```

# Solutions

### Python
```
class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        '''
        Bubble Sort
        '''
        digit_logs=[]
        letter_logs=[]
        
        for log in logs:
            arr=log.split(" ")
            if '0'<=arr[1][0]<='9':
                digit_logs.append(log)
            else:
                # (id, contents, original_log)
                letter_logs.append((arr[0], " ".join(arr[1:]), log))
        print(digit_logs)
        print(letter_logs)
        
        dl=len(letter_logs)
        for i in range(dl):
            for j in range(1, dl-i):
                l1=letter_logs[j-1]
                l2=letter_logs[j]
                if l1[1]>l2[1] or l1[1]==l2[1] and l1[0]>l2[0]:
                    letter_logs[j], letter_logs[j-1] = letter_logs[j-1], letter_logs[j]
            
        res=[]
        for ll in letter_logs:
            res.append(ll[2])
        
        return res+digit_logs

```
