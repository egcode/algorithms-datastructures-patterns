### [Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/) <br>

We can shift a string by shifting each of its letters to its successive letter.

 - For example, `"abc"` can be shifted to be `"bcd"`.

We can keep shifting the string to form a sequence.
 - For example, we can keep shifting `"abc"` to form the sequence: `"abc" -> "bcd" -> ... -> "xyz"`.

Given an array of strings `strings`, group all `strings[i]` that belong to the same shifting sequence. You may return the answer in **any order**.

 


#### Example 1:

```
Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]

```

#### Example 2:

```
Input: strings = ["a"]
Output: [["a"]]

```



# Solutions

### Python
```
class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:        
        '''
        
        - We need to watch out for the "wraparound" case - for example, 'az' and 'ba' should map to the same "shift group" as           a + 1 = b and z + 1 = a. Given the above point, the respective tuples would be (25,) (122 - 97) and (-1,) (79 - 80)             and az and ba would map to different groups. This is incorrect.
        
        - To account for this case, we mod difference % 26  (122 - 97)=(25,) and (79 - 80)=(-1,) 
        (25,) % 26 = (25,)
        (-1,) % 26 = (25,)
        '''
        
        dic=collections.defaultdict(list)
        
        for string in strings:
            
            # Key Group
            arr=[]
            for i in range(1, len(string)):
                ch1=string[i]
                ch2=string[i-1]
                
                dif=ord(ch2)-ord(ch1)
                dif %= 26
                arr.append(str(dif))
            
            
            key="".join(arr)
            dic[key].append(string)
            
            
        return dic.values()
```
