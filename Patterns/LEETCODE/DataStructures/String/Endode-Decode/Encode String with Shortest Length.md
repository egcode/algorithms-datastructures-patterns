### [Encode String with Shortest Length](https://leetcode.com/problems/encode-string-with-shortest-length/) <br>

Given a string `s`, encode the string such that its encoded length is the shortest.

The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is being repeated exactly `k` times. `k` should be a positive integer.

If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return **any of them**.

 



#### Example 1:

```
Input: s = "aaa"
Output: "aaa"
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.

```

#### Example 2:

```
Input: s = "aaaaa"
Output: "5[a]"
Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
```

#### Example 3:

```
Input: s = "aaaaaaaaaa"
Output: "10[a]"
Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".

```

#### Example 4:

```
Input: s = "aabcaabcd"
Output: "2[aabc]d"

```


# Solutions

### CPP
```
class Solution {
    unordered_map<string,string> memo;

    int numRepetition(string &s, string &t) {
        int cnt=0,i=0;
        while(i<s.length()) {
            if(s.substr(i,t.length())!=t) break;
            cnt++;
            i+=t.length();
        }
        return cnt;
    }
public:
    string encode(string s) {
        if(s.length() < 4) 
            return s;
        if(memo.count(s)) 
            return memo[s];
        
        string res = s;
        for(int i=0; i<s.length(); i++) {
            string s1 = s.substr(0,i+1);
            int repetitions = numRepetition(s,s1);
            string cur;  
            for(int k=1;k<=repetitions;k++) {
                if (k==1) {
                    cur = s1 + encode(s.substr(i+1));
                } else {
                    cur = to_string(k) + "["+encode(s1)+"]"+encode(s.substr(k*s1.length()));
                }
                if (cur.length()<res.length()) {
                    res=cur;            
                }
            }
        }
        memo[s]=res;
        return res;        
    }
};

```
