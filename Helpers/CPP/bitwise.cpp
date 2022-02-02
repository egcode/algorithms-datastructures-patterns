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

    cout << endl << "-----------------------------Add/Remove Right Most" << endl;

    int x = 7;
    cout << "  x       " << bitset<8>(x) << endl; //    x      00000111
    
    c = (-x);
    cout << " -x       " << bitset<8>(c) << endl; //   -x      11111001

    c = x & (-x); // keeps rightmost 1-bit and sets all other bits to 0
    cout << "x & (-x)  " << bitset<8>(c) << endl; //  x & (-x) 00000001

    c = x & (x-1); // removes rightmost 1-bit
    cout << "x & (x-1) " << bitset<8>(c) << endl; // x & (x-1) 00000001

    return 0;
}