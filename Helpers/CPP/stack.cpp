/*
g++ stack.cpp -std=c++11;./a.out
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    stack <string> distros; //Create a stack of strings.

    distros.push("a");  //Pushes elements into the stack.
    distros.push("b");

    cout << "Stack count: " << distros.size() << endl; // Stack count: 2
    cout << "stack last element: " << distros.top() << endl; // stack last element: b

    distros.pop();
    cout << "stack top: " << distros.top() << endl; // stack top: a
    return 0;
}
