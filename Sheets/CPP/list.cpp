/*
g++ list.cpp -std=c++20 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    cout << endl << "-----------------------------Doubly Linked List Init" << endl; 
    list<int> lst = {3,6,9};
    lst.push_back(2); // 3 6 9 2
    lst.push_front(1); // 1 3 6 9 2

    // print 
    for (auto &el : lst ) {
        cout << " " << el; // 1 3 6 9 2
    }
    cout << "\n";

    cout << endl << "-----------------------------Splice" << endl; 

    // initializing lists
    list<int> l1 = { 1, 2, 3 };
 
    // transfer all the elements of l2 after second element
    auto it=l1.begin();
    advance(it, 2);
    l1.splice(it, list<int>{ 4, 5 });
 
    // add 
    cout << "merge { 4, 5 } list to { 1, 2, 3 } list after second element" << endl;
    for (auto x : l1) cout << x << " "; // 1 2 4 5 3
    cout << "\n";
    

    cout << endl << "-----------------------------FORWARD LIST" << endl; 
    forward_list<int> fl {1,2,3};
    cout << "insert_after begin 5" << "\n"; 
    fl.insert_after(fl.begin(), 5);
    for (auto x : fl) cout << x << " "; // 1 5 2 3 
    cout << "\n";

    cout << "insert_after before_begin 88" << "\n";
    fl.insert_after(fl.before_begin(), 88);
    for (auto x : fl) cout << x << " "; // 88 1 5 2 3
    cout << "\n";

    cout << "erase_after begin" << "\n";
    fl.erase_after(fl.begin());
    for (auto x : fl) cout << x << " "; // 88 5 2 3
    cout << "\n";

    return 0;
}