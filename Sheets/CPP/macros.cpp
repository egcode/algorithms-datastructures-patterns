#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1<<15;
int dp[SIZE];
void update(int &x,int v){
    if(x==-1||x>v)x=v;
}
class Solution {
public:

    // Macros example
    int minStickers(vector<string>& stickers, string target) {
        MS1(dp);
        dp[0]=0;
        int n=SZ(target);
        int N=1<<n;
        REP(i,N){
            if(dp[i]==-1)continue;
            REP(j,SZ(stickers)){
                int now=i;
                REP(k,SZ(stickers[j])){
                    REP(r,n){
                        if((now>>r)&1)continue;
                        if(target[r]==stickers[j][k]){
                            now|=1<<r;
                            break;
                        }
                    }
                }
                update(dp[now],dp[i]+1);
            }
        }
        return dp[N-1];
    }

// Non Macros example
int minStickers(vector<string>& stickers, string target) {
    int n = target.size(), N = 1 << n;
    vector<uint> dp(N, -1);
    dp[0] = 0;
    for (int i = 0; i < N; i++) if (dp[i] != -1) {
        for (string& s : stickers) {
            int now = i;
            for (char c : s) {
                for (int r = 0; r < n; r++) {
                    if (target[r] == c && !((now >> r) & 1)) {
                        now |= 1 << r;
                        break;
                    }
                }
            }
            dp[now] = min(dp[now], dp[i] + 1);
        }
    }
    return dp[N-1];
}


};

