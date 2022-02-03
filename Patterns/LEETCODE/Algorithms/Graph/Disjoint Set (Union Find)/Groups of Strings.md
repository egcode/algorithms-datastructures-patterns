### [Groups of Strings](https://leetcode.com/problems/groups-of-strings/) <br>

You are given a **0-indexed** array of strings `words`. Each string consists of **lowercase English letters** only. No letter occurs more than once in any string of `words`.

Two strings `s1` and `s2` are said to be **connected** if the set of letters of `s2` can be obtained from the set of letters of `s1` by any **one** of the following operations:

 - Adding exactly one letter to the set of the letters of `s1`.
 - Deleting exactly one letter from the set of the letters of `s1`.
 - Replacing exactly one letter from the set of the letters of `s1` with any letter, **including** itself.

The array `words` can be divided into one or more non-intersecting **groups**. A string belongs to a group if any **one** of the following is true:

 - It is connected to **at least one** other string of the group.
 - It is the **only** string present in the group.

Note that the strings in `words` should be grouped in such a manner that a string belonging to a group cannot be connected to a string present in any other group. It can be proved that such an arrangement is always unique.

Return an array `ans` of size `2` where:

 - `ans[0]` *is the ***total number*** of groups words can be divided into, and*
 - `ans[1]` *is the ***size of the largest*** group*.


#### Example 1:

```
Input: words = ["a","b","ab","cde"]
Output: [2,3]
Explanation:
- words[0] can be used to obtain words[1] (by replacing 'a' with 'b'), and words[2] (by adding 'b'). So words[0] is connected to words[1] and words[2].
- words[1] can be used to obtain words[0] (by replacing 'b' with 'a'), and words[2] (by adding 'a'). So words[1] is connected to words[0] and words[2].
- words[2] can be used to obtain words[0] (by deleting 'b'), and words[1] (by deleting 'a'). So words[2] is connected to words[0] and words[1].
- words[3] is not connected to any string in words.
Thus, words can be divided into 2 groups ["a","b","ab"] and ["cde"]. The size of the largest group is 3.  

```

#### Example 2:

```
Input: words = ["a","ab","abc"]
Output: [1,3]
Explanation:
- words[0] is connected to words[1].
- words[1] is connected to words[0] and words[2].
- words[2] is connected to words[1].
Since all strings are connected to each other, they should be grouped together.
Thus, the size of the largest group is 3.

```



# Solutions

### CPP
```
class DisjointSet {
    int count;
    vector<int>roots;
    vector<int>rates;
    
    public:
    DisjointSet(int n) {
        count = n;
        rates.assign(n,1);
        roots.assign(n,0);
        iota(begin(roots), end(roots), 0);        
    }
    
    int find(int x) {        
        if (x==roots[x])
            return roots[x];
        roots[x]=find(roots[x]);
        return roots[x];
    }
    void unioN(int x, int y) {
        int rootX=find(x);
        int rootY=find(y);
        if (rootX != rootY) {
            if (rates[rootX]>rates[rootY]) {
                roots[rootY]=rootX;
            } else if (rates[rootX]<rates[rootY]) {
                roots[rootX]=rootY;
            } else {
                rates[rootX]++;
                roots[rootY]=rootX;
            }
        --count;            
        }
    }
    
    int getCount() { return count; }
};

class Solution {
public:

    vector<int> groupStrings(vector<string>& words) {
        int N = words.size();
        DisjointSet ds(N);
        unordered_map<int, int> getIndex; // map from hash to index
		// getIndex.reserve(N);
        for (int i = 0; i < N; ++i) {
            int mask = 0;
            for (char ch : words[i])
                mask |= 1 << (ch - 'a'); // `h` is the bitmask representation of `words[i]`
            
            for (int j = 0; j < 26; ++j) {
                if (mask & (1 << j)) { // if `h`'s j-th bit is 1
                    
                    int del = mask ^ (1 << j); // `del` is the bitmask after deleting the `j`-th bit
                    
                    if (getIndex.count(del)) 
                        ds.unioN(i, getIndex[del]); // Connect `words[i]` with its deletion variant
                    for (int k = 0; k < 26; ++k) { // we replace `j`-th bit with `k`-th bit
                        int rep = del | (1 << k); // `rep` is the bitmask after replacing `j`-th bit with `k`-th bit.                        
                        if (rep != del && getIndex.count(rep))
                            ds.unioN(i, getIndex[rep]);
                    }
                } else {
                    int add = mask | (1 << j); // `add` is the bitmask after adding `j`-th bit
                    if (getIndex.count(add))
                        ds.unioN(i, getIndex[add]);
                }
            }
            getIndex[mask] = i;
        }        
        
        int largest=0; // first-node , second-count
        unordered_map<int,int>mp;
        for (int i=0;i<N; i++) {
            int root = ds.find(i);
            mp[root]++;
            largest = max(largest, mp[root]);
        }
        return {ds.getCount(), largest};
    }
    
};

```
