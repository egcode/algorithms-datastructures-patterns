/*
g++ pair.cpp -std=c++17;./a.out
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

    cout << endl << "-----------------------------Basic Pair" << endl; 

    pair<int, int> p1 = { 2, 3 };
    pair<int, char> p2 = make_pair(2, 'a');
    cout<<"pair p1 : "<<p1.first<<" "<<p1.second<<endl; // pair p1 : 2 3
    cout<<"pair p2 : "<<p2.first<<" "<<p2.second<<endl; // pair p2 : 2 a

    // or your can make pair of pair
    pair<int, pair<int, char> > p3 = { 1, {2, 'a'}};
    cout<<"pair p3 : "<<p3.first<<" "<<p3.second.first<<" "<<p3.second.second<<endl; // pair p3 : 1 2 a


    cout << endl << "-----------------------------Pair with Vector" << endl; 
    vector< pair< int, string> > vec = { {2, "blah"}, {5, "foo"}};

    for (auto pp: vec) {
        cout << " first: " << pp.first << " second: "<< pp.second << endl;
    }
    cout << endl;
    /*
    first: 2 second: blah
    first: 5 second: foo    
    */

    cout << endl << "-----------------------------Pair as Key in Map" << endl; 
    unordered_map < pair<int, string>, int, hash_pair> mymap;

    pair<int, string> pp1(32, "thirtytwo");
    pair<int, string> pp2(8, "eight");
    pair<int, string> pp3(5, "five");


    mymap[pp1]=1111;
    mymap[pp2]=22222;
    mymap[pp3]=3333;

    cout << "Iterate using structured binding (since C++17):" << endl;
    for( const auto& [key, value] : mymap ) {
        cout << "KeyFirst: " << key.first << " KeySecond: "<< key.second << "  Value: " << value << endl;
    }
    /*
        KeyFirst: 5 KeySecond: five  Value: 3333
        KeyFirst: 8 KeySecond: eight  Value: 22222
        KeyFirst: 32 KeySecond: thirtytwo  Value: 1111    
    */

    cout << endl << "-----------------------------Pair with Stack" << endl; 
    stack<pair<string, string>> st;
    st.push({ "s one", "s two"});
    st.push({ "ss one", "ss two"});
    st.push({ "sss one", "sss two"});

    while (!st.empty()) {
        auto [odin, dva] = st.top(); 
        cout << " odin: " << odin;
        cout << " dva: " << dva << endl;
        st.pop();
    }
    /*
        odin: sss one dva: sss two
        odin: ss one dva: ss two
        odin: s one dva: s two    
    */


    cout << endl << "-----------------------------Pair with Priority Queue {max heap}" << endl; 

    // Max heap
    priority_queue < pair<int, char> > pq1; 
    pq1.push({32, 'a'});
    pq1.push({3, 'c'});
    pq1.push({1, 'b'});

    while (!pq1.empty()) {
        cout << "{" << pq1.top().first << "} "; // 
        pq1.pop();
    }
    cout << endl << "-----------------------------Pair with Priority Queue {min heap}" << endl; 

    // Min heap
    typedef pair<int, char> pi;
    priority_queue<pi, vector<pi>, greater<pi> > pq2;

    // priority_queue < pair<int, char> > pq2; 
    pq2.push({32, 'a'});
    pq2.push({3, 'c'});
    pq2.push({1, 'b'});

    while (!pq2.empty()) {
        cout << "{" << pq2.top().first << "} "; // 
        pq2.pop();
    }

    return 0;
}