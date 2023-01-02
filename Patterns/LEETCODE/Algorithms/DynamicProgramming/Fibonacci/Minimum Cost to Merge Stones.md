### [Minimum Cost to Merge Stones](https://leetcode.com/problems/minimum-cost-to-merge-stones/) <br>

There are `n` piles of `stones` arranged in a row. The i<sup>th</sup> pile has `stones[i]` stones.

A move consists of merging exactly `k` **consecutive** piles into one pile, and the cost of this move is equal to the total number of stones in these `k` piles.

Return the *minimum cost to merge all piles of stones into one pile*. If it is impossible, return `-1`.

 



#### Example 1:
```
Input: stones = [3,2,4,1], k = 2
Output: 20
Explanation: We start with [3, 2, 4, 1].
We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
We merge [4, 1] for a cost of 5, and we are left with [5, 5].
We merge [5, 5] for a cost of 10, and we are left with [10].
The total cost was 20, and this is the minimum possible.

```

#### Example 2:
```
Input: stones = [3,2,4,1], k = 3
Output: -1
Explanation: After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.

```

#### Example 3:
```
Input: stones = [3,5,1,2,6], k = 3
Output: 25
Explanation: We start with [3, 5, 1, 2, 6].
We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
We merge [3, 8, 6] for a cost of 17, and we are left with [17].
The total cost was 25, and this is the minimum possible.

```


# Solutions


### CPP
```
const int INF = 1e9 + 5;
// 0(N*N*N*K*N) = O(K * N^4)
//https://youtu.be/HK9SskoFEFw?t=2010
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        vector<vector<int>> cost_interval(n, vector<int>(n, INF));
        for (int L = n - 1; L >= 0; --L) {
            for(int R=L; R<n; ++R) {
                if (L==R){
                    cost_interval[L][R]=0;
                    continue;
                }
                vector<vector<int>> dp_frog(n+1, vector<int>(K+1, INF));
                dp_frog[L][0]=0;
                for(int pos=L; pos <= R; pos++) {
                    for(int jumps=0; jumps<K; jumps++){
                        for (int new_pos=pos+1; new_pos<=R+1; ++new_pos) {
                            dp_frog[new_pos][jumps+1]=min(dp_frog[new_pos][jumps+1],
                                                         dp_frog[pos][jumps]+cost_interval[pos][new_pos-1]);
                        }
                    }
                }
                int sum=0;
                for(int i=L; i<=R;++i)
                    sum += stones[i];
                cost_interval[L][R]=dp_frog[R+1][K]+sum;
            }
        }
        if(cost_interval[0][n-1] >= INF)
            return -1;
        return cost_interval[0][n-1];
    }
};
```
