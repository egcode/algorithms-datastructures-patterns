/*
g++ set_unordered.cpp -std=c++11;./a.out
*/

#include <bits/stdc++.h>
using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};



int main(){

    cout << endl << "-----------------------------Set" << endl; 

    unordered_set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(-3);
    s.insert(-10);

    // you will find elements in set outputted in ascending order
    // -10 -3 1 5
    for(int x : s) cout<<x<<" ";

    // takes O(logn) time to erase element
    s.erase(1);

    // Using count
    if (s.count(5)) {
        std::cout << "5 in the set" << std::endl; // 5 in the set
    }
    if (s.count(333) == false) {
        std::cout << "333 Not in the set" << std::endl; // 333 Not in the set
    }

    cout << endl << "-----------------------------Set on pair" << endl; 
    unordered_set<pair<int, int>, hash_pair> pairSet;
    pairSet.insert({1, 2});
    pairSet.insert({5, 10});
    pairSet.insert({5, 11});
    pairSet.insert({3, 1});

    // {1, 2}, {3, 1}, {5, 10}, {5, 11}
    for(pair<int, int> x : pairSet)
        cout<<"{"<<x.first<<", "<<x.second<<"}, "; // {1, 2}, {3, 1}, {5, 10}, {5, 11}, 
    cout<<endl;


    cout << endl << "-----------------------------Pop from set" << endl; 
    for(pair<int, int> x : pairSet)
        cout<<"{"<<x.first<<", "<<x.second<<"}, "; // {1, 2}, {3, 1}, {5, 10}, {5, 11}, 
    cout << endl;

    pair<int,int> pop = *pairSet.begin();
    cout << "popped: {" << pop.first << " " << pop.second << "}" << endl;
    pairSet.erase(pairSet.begin());

    cout << "After pop:   ";
    for(pair<int, int> x : pairSet)
        cout<<"{"<<x.first<<", "<<x.second<<"}, "; // After pop:   {3, 1}, {5, 10}, {5, 11}, 
    cout << endl;


    return 0;
}
