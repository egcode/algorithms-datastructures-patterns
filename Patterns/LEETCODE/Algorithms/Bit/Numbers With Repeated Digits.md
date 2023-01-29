### [Numbers With Repeated Digits](https://leetcode.com/problems/numbers-with-repeated-digits/) <br>

Given an integer `n`, return *the number of positive integers in the range* `[1, n]` *that have at **least one** repeated digit*.




#### Example 1:
```
Input: n = 20
Output: 1
Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.

```

#### Example 2:
```
Input: n = 100
Output: 10
Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.

```

#### Example 3:

```
Input: n = 1000
Output: 262

```

# Solutions

### CPP
```
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
class Solution {
public:
	int n, res;
	void go(ll val, int mask) {
        // cout<<"val: "<<val<<"  mask:"<<bitset<10>(mask)<<"\n";
		if (val <= n) {
            ++res;
        }
		if (val * 10 > n) return;
		for (int i = 0; i <= 9; ++i) {
			if (!mask && i == 0) continue; // no 0 for first digit
			if (mask & (1 << i)) continue;
            ll val1=val*10+i;
            int mask1=mask | (1<<i);
            // cout<<"res  "<<res<<" val1: "<<val1<<"  mask1:"<<bitset<10>(mask1)<<"\n";            
			go(val1, mask1);
		}
	}
  int numDupDigitsAtMostN(int N) {
  	res = 0;
  	n = N;
  	go(0, 0);
  	return N + 1 - res;
  }
};
```
