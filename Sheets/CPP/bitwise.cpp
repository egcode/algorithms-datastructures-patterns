/*
g++ bitwise.cpp -std=c++11 -o /tmp/a.out;/tmp/a.out
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
    cout << "x & (x-1) " << bitset<8>(c) << endl; // x & (x-1) 00000110


    cout << endl << "-----------------------------Binary Mask" << endl;

    int m = 0;
    cout << "  m       " << bitset<8>(m) << endl; //    m      00000000

    m |= 1 << 3;
    cout << "  m       " << bitset<8>(m) << endl; //    m      00010000

    if (m & (1 << 3))
        cout << " 3rd bit is set to 1" << endl;

    m = m ^ (1 << 3);
    cout << "  m       " << bitset<8>(m) << endl; //    m      00000000 

    if (!(m & (1 << 3)))
        cout << " 3nd bit is not set to 1" << "\n";

    cout << "\n" << "-----------------------------Fill Mask" << "\n";

    m = 0;
    cout << "empty mask:      m       " << bitset<8>(m) << "\n"; //              empty mask:      m       00000000

    int fill = 5;
    m = (1 << fill) - 1;
    cout << "filled " << fill << " bytes:  m       " << bitset<8>(m) << "\n"; // filled 5 bytes:  m       00011111

    cout << "\n" << "-----------------------------Flip by Mask" << "\n";

    int num  = 0;
    int mask = (1 << 5) - 1;   
    cout << "num         " << bitset<8>(num) << "\n"; //                      num:         00000000
    cout << "mask        " << bitset<8>(mask) << "\n";//                     mask:         00011111

    int flipByMask = ~num & mask;
    cout << "flipByMask  " << bitset<8>(flipByMask) << "\n";//   flipByMask:               00011111

    cout << "\n" << "-----------------------------Hamming Weight" << "\n";
    int hamInteger = 456;
    int hamWeight = 0;
    cout << bitset<16>(hamInteger) << "\n"; // 0000000111001000
    for (int i=0; i<32; i++) {
        hamWeight += (hamInteger & 1);
        hamInteger = hamInteger >> 1;
    }
    cout << "Weight: " << hamWeight << "\n";

    cout << "\n" << "----------------------------- Packing TWO values into ONE Integer for hash" << "\n";
    int row = 111, col = 555;
    cout<<"Coordinates,  row: "<<row<<" col: "<<col<<"\n";
    int packForHash = (row<<16) + col; 
    cout<<"Packed Integer: "<<packForHash<<"\n";
    
    int rowUnpacked = packForHash>>16;
    int colUnpacked = packForHash-(row<<16);
    cout<<"Coordinates,  rowUnpacked: "<<rowUnpacked<<" colUnpacked: "<<colUnpacked<<"\n";
 

    return 0;
}