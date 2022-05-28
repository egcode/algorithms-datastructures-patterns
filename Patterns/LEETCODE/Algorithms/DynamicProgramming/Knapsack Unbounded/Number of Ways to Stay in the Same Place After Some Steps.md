### [Number of Ways to Stay in the Same Place After Some Steps](https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/) <br>

You have a pointer at index `0` in an array of size `arrLen`. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers `steps` and `arrLen`, return the number of ways such that your pointer still at index `0` after **exactly** steps steps. Since the answer may be too large, return it **modulo** <img src="https://render.githubusercontent.com/render/math?math=10^9"> + <img src="https://render.githubusercontent.com/render/math?math=7">.



#### Example 1:

```
Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

```

#### Example 2:

```
Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay

```

#### Example 3:

```
Input: steps = 4, arrLen = 2
Output: 8

```



# Solutions

### Python
```
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        mod=10**9+7;
    
        @lru_cache(None)
        def dp(i, stepsCount):
            if stepsCount==0 and i==0:
                return 1
            if stepsCount==0 or i>=arrLen:
                return 0
            if i>stepsCount or i<0:
                return 0     

            res=0
            res += dp(i, stepsCount-1)
            res += dp(i-1, stepsCount-1)
            res += dp(i+1, stepsCount-1)
                
            return res % mod
        return dp(0, steps)
        
    def numWays(self, steps: int, arrLen: int) -> int:
        mod=10**9+7;
        sz = min(arrLen, steps//2+1)
        dp=[[0]*(sz+2) for _ in range(steps+1)]
        dp[0][1]=1
        
        for i in range(1, steps+1):
            for j in range(1, sz+1):
                dp[i][j]=((dp[i-1][j]+dp[i-1][j-1]) % mod + dp[i-1][j+1]) % mod
                
        return dp[steps][1]

```

### CPP
```
class Solution {
public:
    vector<vector<int>>memo;
    int mod=1e9+7;
    int arlen;
    
    int dp(int i, int steps) {
        
        if (steps==0 and i==0) // Base
            return 1;
        
        if (steps==0 or i>=arlen or i>steps or i<0) // Pruning
            return 0;   
        
        if (memo[i][steps] != -1)
            return memo[i][steps];

        int res=0;
        res += dp(i, steps-1);
        res %= mod;
        res += dp(i-1, steps-1);
        res %= mod;       
        res += dp(i+1, steps-1);
        res %= mod;

        memo[i][steps]=res % mod;
        return memo[i][steps];
    }
    
    int numWays(int steps, int arrLen) {
        /*
        We can now use memoization to cache all our answers, 
        the only thing we need to  worry about is memory which can 
        be solved by using the observation i>steps will return 0 which 
        means i will never exceed steps/2 due to pruning.        
        */
        memo.resize(steps/2+1, vector<int>(steps+1, -1));
        arlen=arrLen;
        int res=dp(0, steps);
        return res;
    }
};

class Solution {
public:
    
    int numWays(int steps, int arrLen) {
        int mod=1e9+7;
        int sz = min(arrLen, steps/2+1);
        vector<int> dp1(sz+2), dp2(sz+2);
        dp1[1]=1;
        
        while (steps--) {
            for (int i=1; i<=sz; ++i)
                dp2[i]= ((dp1[i]+dp1[i-1])%mod + dp1[i+1]) % mod;            
                
            swap(dp1, dp2);
        }
        
        return dp1[1];
    }
};

```
