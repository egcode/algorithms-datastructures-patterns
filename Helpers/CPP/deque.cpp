/*
g++ deque.cpp -std=c++11;./a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    deque<int> dqu = {2, 3, 4};
    dqu.push_front(1);
    dqu.push_back(5);
    for(int x : dqu)
        cout<<x<<" ";
    /*
    1 2 3 4 5
    */
    return 0;
}
