/*
g++ allSubsets.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int n=3;

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
    /*
        2
        1
        1 2
        0
        0 2
        0 1
        0 1 2    
    */
    int subsetsCount = 1 << n;
    //subsetsCount - from 0 to n
    cout <<"subsetsCount: " << subsetsCount-1 <<"\n";// subsetsCount: 7
    getSubsets2(0);
    /*
        0
        1
        0 1
        2
        0 2
        1 2
        0 1 2    
    */
}