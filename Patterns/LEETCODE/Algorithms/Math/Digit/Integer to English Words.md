### [Integer to English Words](https://leetcode.com/problems/integer-to-english-words/) <br>

Convert a non-negative integer `num` to its English words representation.



#### Example 1:

```
Input: num = 123
Output: "One Hundred Twenty Three"

```

#### Example 2:

```
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

```

#### Example 3:

```
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

```

#### Example 4:

```
Input: num = 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

```


# Solutions

### Python
```
class Solution:
    def numberToWords(self, num: int) -> str:
        to19="One Two Three Four Five Six Seven Eight Nine Ten Eleven Twelve Thirteen Fourteen Fifteen Sixteen Seventeen Eighteen Nineteen".split()
        tens="Twenty Thirty Forty Fifty Sixty Seventy Eighty Ninety".split()
        
        bigs={1000000000: "Billion", 1000000: "Million", 1000: "Thousand"}
        
        def word(num):
            if num<20:
                return to19[num-1:num]
            if num<100:
                return [tens[(num//10)-2]] + word(num%10)
            if num<1000:
                return word(num//100) + ["Hundred"] + word(num%100)
            
            else:
                for big in [1000000000, 1000000, 1000]:
                    if num//big>0:
                        return word(num//big) + [bigs[big]] + word(num%big)
            
        return " ".join(word(num)) or "Zero"

```
