/*
g++ set.cpp -std=c++11;./a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    cout << endl << "-----------------------------Set" << endl; 

    set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(-3);
    s.insert(-10);

    // you will find elements in set outputted in ascending order
    // -10 -3 1 5
    for(int x : s) cout<<x<<" ";

    // takes O(logn) time to erase element
    s.erase(1);

    auto it = s.find(-3);

    if(it == s.end()) cout<<"element not in set"<<endl;
    else cout<<*it<<" element is found"<<endl; // -10 -3 1 5 -3 element is found

    auto it1 = s.upper_bound(-3);
    cout<<"found element just greater than -3 "<<*it1<<endl; // found element just greater than -3 5

    auto it3 = s.upper_bound(5);

    if(it3 == s.end()) cout<<"not found"<<endl; // not found
    else cout<<"found upper bound"<<endl;

    // Using count
    if (s.count(5)) {
        std::cout << "5 in the set" << std::endl; // 5 in the set
    }
    if (s.count(333) == false) {
        std::cout << "333 Not in the set" << std::endl; // 333 Not in the set
    }

    cout << endl << "-----------------------------Set on pair" << endl; 
    set<pair<int, int>> pairSet;
    pairSet.insert({1, 2});
    pairSet.insert({5, 10});
    pairSet.insert({5, 11});
    pairSet.insert({3, 1});

    // {1, 2}, {3, 1}, {5, 10}, {5, 11}
    for(pair<int, int> x : pairSet)
        cout<<"{"<<x.first<<", "<<x.second<<"}, "; // {1, 2}, {3, 1}, {5, 10}, {5, 11}, 

    cout<<endl;

    set<pair<int, int>> sp = {{5, 10}, {14, 20}, {50, 100}, {75, 125}, {8, 16}};

    // sp = {{5, 10}, {8, 16}, {14, 20}, {50, 100}, {75, 125}};
    sp.lower_bound({4, 10}); // {5, 10}
    sp.lower_bound({5, 8}); // {5, 10}
    sp.lower_bound({5, 10}); // {5, 10}
    sp.lower_bound({5, 11}); // {8, 16}

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
