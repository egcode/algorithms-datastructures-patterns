/*
g++ deque.cpp -std=c++11 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    deque<int> dqu = {2, 3, 4};
    dqu.push_front(1);
    dqu.push_back(5);
    for(int x : dqu)
        cout<<x<<" ";
    cout << endl;
    /*
    1 2 3 4 5
    */

    cout << endl << "-----------------------------Pop Back" << endl; 
    dqu.pop_back();
    for(int x : dqu)
        cout<<x<<" ";
    cout << endl;
    /*
    1 2 3 4 5
    */
    cout << endl << "-----------------------------Pop Front" << endl; 
    dqu.pop_front();
    for(int x : dqu)
        cout<<x<<" ";
    cout << endl;
    /*
    1 2 3 4 5
    */


    return 0;
}