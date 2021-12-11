### [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) <br>

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` *if it is a* **palindrome**, *or* `false` *otherwise*.



#### Example 1:

```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

```

#### Example 2:

```
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

```


#### Example 3:

```
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

```


# Solutions

### Python
```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        arr=[]
        # clean
        for l in s:
            ch=l.lower()
            if ch >= 'a' and ch <= 'z' or ch >= '0' and ch <= '9':
                arr.append(ch)
        
        word="".join(arr)
        n=len(word)             
        left=0
        right=n-1
        
        while left<right:
            l1=word[left]
            l2=word[right]
            
            if l1 != l2:
                return False
            left += 1
            right -= 1
            
        return True

```
