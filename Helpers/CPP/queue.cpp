/*
g++ queue.cpp -std=c++11 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;


int main(){

    queue<int> q;

    // push an element at the end of queue
    q.push(1); // {1}
    q.push(2); // {2, 1}
    q.push(3); // {3, 2, 1}
    q.push(4); // {4, 3, 2, 1}

    // iterate till queue is not empty
    while (!q.empty()){
        // get the front element of queue
        cout<<q.front()<<" ";
        // remove the front element of queue
        q.pop();
    }
    /*
    1 2 3 4
    */

    return 0;
}
