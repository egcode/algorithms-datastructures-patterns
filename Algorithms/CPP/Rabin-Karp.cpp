/*
g++ Rabin-Karp.cpp -std=c++17;./a.out
*/

#include <bits/stdc++.h>
using namespace std;

int findPattern(string s, string pattern, int power, int modulo) {
    /*
    Rolling hash. 
    
    Example from problem 2156 in leetcode.
    hash(s, p, m) = (val(s[0]) * p^0 + val(s[1]) * p^1 + ... + val(s[k-1]) * p^k-1) mod m.


    The idea here is to do sliding window.
    Tricky part is that we should slide window from beginning
    because we need p^0 + p^1 + ... + p^k-1
    1. if we do that from the beginning we need to add p^k-1 at the end 
    of the window and divide whole window to p
    2. if we loop from the end - we always add val(s[i]) * p^0 where p^0 always 1,
    and we need to multiply whole window to p.
    
    Multiplication here is better than division.
    */

    // Calculating pattern hash value
    int k=pattern.size();
    int hashValue=0;
    for (int i=0;i<k;i++){
        hashValue += ((int)(pattern[i]-'a'+1) * (int)pow(power,i)) % modulo;
    }
    hashValue %= modulo;
    cout << "Pattern Hash Value: " << hashValue << endl;

    // Searching pattern
    long long win = 0;
    long long res = 0; 
    long long pk = 1;
    long long n = s.size();
    for (int i=n-1;i>=0;i--) {
        win = (win * power + (s[i]-'a'+1)) % modulo;
        // cout << " " << win;

        if (i+k >= n)
            pk = pk * power % modulo; // accumulation pk by hand
        else

            // remove s[i+k] value.
            // Note: But "win - (pk*(s[i+k]-'a'+1))%mod" could be negative, so +mod and %mod
            win = (win - (s[i+k]-'a'+1) * pk % modulo + modulo) % modulo;
        if (win == hashValue)
            res = i;
    }

    cout << pattern << " was found on index: " << res << endl;
    cout << "final pattern found: " << s.substr(res, k) << endl;
    return res;
}

int main() {
    cout << endl << "-----------------------------Rabin-Karp" << endl; 
    findPattern("onetwothree", "two", 31, 100);
    // findPattern("fbxzaad", "fbx", 31, 100);
    return 0;
}