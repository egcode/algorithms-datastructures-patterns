/*
g++ allSubsetsSubstrings.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
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

void getSubsets(int k, vector<int>& subset) {
        if (k == n) {
           // printing
            for (int& i:subset)
                cout << " "<<i;
            cout<<"\n";
        } else {
           getSubsets(k+1, subset);
           subset.push_back(k);
           getSubsets(k+1, subset);
           subset.pop_back();
    } 
}

void getSubsets2(int k) {
    for (int b = 0; b < (1<<n); b++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
           if (b & (1<<i)) 
               subset.push_back(i);
        }
        // Printing
        for (int& i:subset)
            cout << " "<<i;
        cout<<"\n";        
    }    
}

int main() {
    cout << "---------------------------------- All Subsets" << "\n";
    vector<int>subset;    
    getSubsets(0, subset);
    int subsetsCount = 1 << n;
    //subsetsCount - from 0 to n
    cout <<"subsetsCount: " << subsetsCount-1 <<"\n";    
    getSubsets2(0);    
    
    cout << "---------------------------------- All Substrings" << "\n"; 
    int substringsMethod1 = getSubstringsCount(n);
    int substringsMethod2 = n*(n+1)/2;    
    cout <<"substringsMethod1: " << substringsMethod1 <<"\n";    
    cout <<"substringsMethod2: " << substringsMethod2 <<"\n";    
    return 0;    
    
}