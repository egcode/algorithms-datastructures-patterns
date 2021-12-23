/*
g++ vector_sort.cpp -std=c++14;./a.out
*/

#include <bits/stdc++.h>
using namespace std;

bool way_to_sort(int i, int j) { return i > j; }

int main(){

    // The following list type initialization is only supported in versions after C++11
    vector<int> vec = {56, 32, -43, 23, 12, 93, 132, -154};
    
    sort(vec.begin(), vec.end());
    cout << "Sorted "; // Sorted -154 -43 12 23 32 56 93 132 
    for (auto x : vec)
        cout << x << " ";

    cout << endl;

    sort(vec.begin(), vec.end(), way_to_sort);
    cout << "Sorted reverse "; // Sorted reverse 132 93 56 32 23 12 -43 -154
    for (auto x : vec)
        cout << x << " ";


    cout << endl << "-----------------------------INTERVALS" << endl; 
    vector< vector<int> > vv;
    vv={ {55, 100}, {4, 6}, {1, 5} };
    cout << endl << "Intervals Unsorted: "; // Intervals Unsorted: |55 100 |4 6 |1 5
    for (auto x: vv) {
        cout << "|";
        for (auto y: x) {
            cout << y << " ";
        }
    }
    
    // C++ 14
    sort(vv.begin(), vv.end(),[](auto& lhs, auto& rhs )
    {
        return lhs[0] < rhs[0];
    });

    // C++ 11
    // sort( vv.begin( ), vv.end( ), [ ]( const vector<int>& lhs, const vector<int>& rhs )
    // {
    // return lhs[0] < rhs[0];
    // });

    cout << endl << "Intervals Sorted: "; // Intervals Sorted: |1 5 |4 6 |55 100 
    for (auto x: vv) {
        cout << "|";
        for (auto y: x) {
            cout << y << " ";
        }
    }
    cout << endl << "-----------------------------" << endl; 

    return 0;
}
