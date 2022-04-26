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
    list<int> l2 = { 4, 5 };
    list<int> l3 = { 6, 7, 8 };
 
    // transfer all the elements of l2
    l1.splice(l1.begin(), l2);
 
    // at the beginning of l1
    cout << "list l1 after splice operation" << endl;
    for (auto x : l1)
        cout << x << " "; // 4 5 1 2 3
 
    // transfer all the elements of l1
    l3.splice(l3.end(), l1);
 
    // at the end of l3
    cout << "\nlist l3 after splice operation" << endl;
    for (auto x : l3)
        cout << x << " "; // 6 7 8 4 5 1 2 3

    return 0;
}