/*
g++ array.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main(){


    cout << endl << "-----------------------------Initlalize array" << endl; 
    int dp[5][5];
    memset(dp, -1, sizeof(dp));

    for (auto& subarr: dp) {
        for (auto& el: subarr) {
            cout << " " << el;
        }
        cout << "\n";
    }

    return 0;
}