/*
g++ allPermutations.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

void permute(vector<int>& v, int start, int end) {
    if (start == end) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    } else {
        for (int i = start; i <= end; i++) {
            int tmp = v[i];
            v[i] = v[start];
            v[start] = tmp;
            permute(v, start+1, end);
            tmp = v[i];
            v[i] = v[start];
            v[start] = tmp;
        }
    }
}

int main() {
    cout << "---------------------------------- All Permutations" << "\n";
    vector<int> v {1, 2, 3};
    permute(v, 0, v.size()-1);
    /*
        1 2 3 
        1 3 2 
        2 1 3 
        2 3 1 
        3 2 1 
        3 1 2 
    */
    return 0;
}