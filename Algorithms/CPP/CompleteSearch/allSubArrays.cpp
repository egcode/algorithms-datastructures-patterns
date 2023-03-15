/*
g++ allSubArrays.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int n=3;

int getSubArraysCount(int n) {
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
    cout << "---------------------------------- All SubArrays" << "\n"; 
    int subArraysMethod1 = getSubArraysCount(n);
    /*
    0
    1
    2
    0 1
    1 2
    0 1 2
    */    
    int subArraysMethod2 = n*(n+1)/2;    
    cout <<"subArraysMethod1: " << subArraysMethod1 <<"\n"; //subArraysMethod1: 6
    cout <<"subArraysMethod2: " << subArraysMethod2 <<"\n"; //subArraysMethod2: 6
    return 0;    
}
