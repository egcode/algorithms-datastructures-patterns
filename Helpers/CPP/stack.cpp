/*
g++ stack.cpp -std=c++11;./a.out
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    stack <string> distros; //Create a stack of strings.

    distros.push("a");  //Pushes elements into the stack.
    distros.push("b");

    cout << "Stack count: " << distros.size() << endl;
    cout << "stack last element: " << distros.top() << endl;

    distros.pop();
    cout << "stack top: " << distros.top() << endl;
    return 0;
}
