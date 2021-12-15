### [Next Closest Time](https://leetcode.com/problems/next-closest-time/) <br>

Given a `time` represented in the format `"HH:MM"`, form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, `"01:34"`, `"12:09"` are all valid. `"1:34"`, `"12:9"` are all invalid.



#### Example 1:

```
Input: time = "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.
It is not 19:33, because this occurs 23 hours and 59 minutes later.

```

#### Example 2:

```
Input: time = "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

```



# Solutions

### Python
```
class Solution:
    def nextClosestTime(self, time: str) -> str:
        hours, minutes = time.split(":")
        
        all_digits=sorted(set(hours+minutes))
        all_combinations=[]
        for a in all_digits:
            for b in all_digits:
                all_combinations.append(a+b)
        
        # Check if we can have date within hour
        i=all_combinations.index(minutes)
        if i+1 < len(all_combinations) and all_combinations[i+1] < "60":
            return hours + ":" + all_combinations[i+1]
        
        # Check if we have date within a day
        i=all_combinations.index(hours)
        if i+1 < len(all_combinations) and all_combinations[i+1] < "24":
            return all_combinations[i+1] + ":" + all_combinations[0]
        
        # Find smallest digits for next day
        return all_combinations[0] + ":" + all_combinations[0]

```
