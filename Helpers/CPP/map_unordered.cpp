/*
g++ map_unordered.cpp -std=c++20;./a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_map<char,int> mymap;
    // map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;

        cout << "Iterate and print keys \n";
    for( const pair<char, int>& n : mymap ) {
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

    cout << "Iterate using auto:\n";
    for( const auto& n : mymap ) {
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

    cout << "Iterate using structured binding (since C++17):\n";
    for( const auto& [key, value] : mymap ) {
        cout << "Key:[" << key << "] Value:[" << value << "]\n";
    }

    cout << endl << "-----------------------------" << endl; 

    cout << "\nCheck if 'b' key in map" << endl;

    // Key is not present
    cout << "mymap.count('b'): " << mymap.count('b') << endl;
    if (mymap.count('b')) {        
        cout << "1111'b' key is in the map" << endl;
    } else {
        cout << "1111'b' key is Not in the map" << endl;
    }    
    
    // C++ 20
    if (mymap.contains('b')) {
        cout << "2222'b' key is in the map" << endl;
    } else {
        cout << "2222'b' key is Not in the map" << endl;
    }

    cout << endl << "-----------------------------" << endl; 
    cout << "Counter map:" << endl;
    vector<int> nums;
    unordered_map<int,int>mp;
    nums={1,2,5,3,4,4,4,1,1};

    for (auto num: nums) {
        ++mp[num];
    }

    cout << "Counter map:\n";
    for (auto n: mp){
        cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }
    return 0;
}
