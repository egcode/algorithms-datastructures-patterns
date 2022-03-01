/*
g++ multiset.cpp -std=c++17;./a.out
*/

#include <bits/stdc++.h>
using namespace std;


int main(){

    cout << endl << "-----------------------------Multiset" << endl; 

    multiset<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(5);
    s.insert(7);
    s.insert(5);
    s.insert(-3);
    s.insert(-10);

    // you will find elements in set outputted in ascending order with duplicates
    for(int x : s) cout << x << " "; // -10 -3 1 5 5 5


    cout << endl << "-----------------------------First/Last" << endl; 
    cout << "First: " << *s.begin() << endl;
    cout << "Last: " << *s.rbegin() << endl;

    return 0;
}
