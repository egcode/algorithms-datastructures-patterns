/*
g++ string.cpp -std=c++11;./a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    cout << endl << "-----------------------------SUBSTRINGS" << endl; 
    string word = "yobana";
    cout << " word: "<< word << endl; // word: yobana  

    string firstSeconChars = word.substr(0, 2);
    string lastChars = word.substr(2, word.size());
    cout << " firstSeconChars: "<< firstSeconChars << endl; // firstSeconChars: yo  
    cout << " lastChars: "<< lastChars << endl; // lastChars: bana

    string combined = lastChars + firstSeconChars;
    cout << " combined: "<< combined << endl;  // combined: banayo

    cout << endl << "-----------------------------" << endl; 

    return 0;
}
