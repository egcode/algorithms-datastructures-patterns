/*
g++ bitwise.cpp -std=c++11;./a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int a = 60; 
    int b = 13;
    cout << bitset<8>(a) << endl; // 00111100
    cout << bitset<8>(b) << endl; // 00001101

    cout << endl << "-----------------------------Basic" << endl;
    int c = 0;

    c = a & b;
    cout << "& operator: " << bitset<8>(c) << endl; // & operator: 00001100 - AND

    c = a | b;
    cout << "| operator: " << bitset<8>(c) << endl; // | operator: 00111101 - OR

    c = a ^ b;
    cout << "^ operator: " << bitset<8>(c) << endl; // ^ operator: 00110001 - XOR

    c = ~a;
    cout << "~ operator: " << bitset<8>(c) << endl; // ~ operator: 11000011 - One's Complement

    c = a << 2;
    cout << "<< operator: " << bitset<8>(c) << endl; // << operator: 11110000 - Left Shift

    c = a >> 2;
    cout << ">> operator: " << bitset<8>(c) << endl; // >> operator: 00001111 - Right Shift

    cout << endl << "-----------------------------Complement" << endl;

     

    return 0;
}