/*
g++ map.cpp -std=c++11 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << endl << "-----------------------------Map" << endl; 

    map<int,int>mp; // score, id
    mp[4]=888;
    mp[8]=111;
    mp[1]=888;
    mp[2]=777;
    mp[7]=222;

        cout << "Iterate and print keys \n";
    for( auto & n : mp ) {
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

    return 0;
}
