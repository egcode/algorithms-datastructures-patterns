/*
g++ allSubstrings.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int n=3;

int getSubstringsCount(int n) {
    int count = 0;
    for (int len = 1; len <= n; len++) { // Pick starting point
        for (int i = 0; i <= n - len; i++) { // Pick ending point
            int j = i + len - 1;
            count++;
            for (int k = i; k <= j; k++) // Loop range
                cout << " " << k;
            cout << "\n";
        }
    }
    return count;
}

int main() {    
    cout << "---------------------------------- All Substrings" << "\n"; 
    int substringsMethod1 = getSubstringsCount(n);
    int substringsMethod2 = n*(n+1)/2;    
    cout <<"substringsMethod1: " << substringsMethod1 <<"\n";    
    cout <<"substringsMethod2: " << substringsMethod2 <<"\n";
    return 0;    
}