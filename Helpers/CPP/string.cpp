/*
g++ string.cpp -std=c++11;./a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    string word = "blah";
    cout << " word: "<< word << endl;      

    string firstSeconChars = word.substr(0, 2);
    string lastChars = word.substr(2, word.size());
    cout << " firstSeconChars: "<< firstSeconChars << endl;      
    cout << " lastChars: "<< lastChars << endl;      

    string combined = lastChars + firstSeconChars;
    cout << " combined: "<< combined << endl;      

    return 0;
}
