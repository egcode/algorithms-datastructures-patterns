/*
g++ char.cpp -std=c++11;./a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    cout << endl << "-----------------------------ALPHABET As Letters" << endl; 
    vector<int>alphabet;
    for(int i=0;i<26;i++){
        alphabet.emplace_back(i);
    }

    //Print Alphabet
    for (int ch: alphabet)
        cout << ch << " ";
    cout << endl;
    /*
    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
    a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
    */

    cout << endl << "-----------------------------CHARACTER to INT" << endl; 
    string alphString = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0; i<alphString.size();i++){
        int charAsInt = alphString[i]-'a';
        cout << alphString[i] << "=" << charAsInt << " " ;
    }
    cout << endl;
    /*
    a=0 b=1 c=2 d=3 e=4 f=5 g=6 h=7 i=8 j=9 k=10 l=11 m=12 n=13 o=14 p=15 q=16 r=17 s=18 t=19 u=20 v=21 w=22 x=23 y=24 z=25
    */

    cout << endl << "-----------------------------CHARACTERS Count" << endl; 
    int cnt[26] = {};
    string s = "aababab";
    cout << "String: " << s << endl; // String: aababab

    for (char c : s) 
        cnt[c - 'a']++;

    cout << "Array Alphabet: ";
    for (int i : cnt)
        cout << " " << i; // Array Alphabet:  4 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    cout << endl;

    string newString = "";
    for (int i=25;i>=0;i--){
        if (cnt[i]>0) {
            for (int j=0;j<cnt[i];j++)
                newString += 'a'+ i;
        }
    }
    cout << "new String: " << newString << endl; // new String: bbbaaaa
    return 0;
}