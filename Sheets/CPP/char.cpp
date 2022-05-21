/*
g++ char.cpp -std=c++11 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    cout << endl << "-----------------------------ALPHABET As Letters" << endl; 
    vector<int>alphabet;
    for(int i=0;i<26;i++){
        alphabet.emplace_back(i);
    }

    cout << endl << "-----------------------------INT to CHARACTER" << endl; 
    //Print Alphabet
    for (int i: alphabet)
        cout << i << "=" << char('a' + i) << " ";
    cout << endl;
    /*
    0=a 1=b 2=c 3=d 4=e 5=f 6=g 7=h 8=i 9=j 10=k 11=l 12=m 13=n 14=o 15=p 16=q 17=r 18=s 19=t 20=u 21=v 22=w 23=x 24=y 25=z
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

    cout << endl << "-----------------------------INT to CHARACTER" << endl;
    char one = '1';
    char five = '5';

    int d1=one-'0';
    int d5=five-'0';

    cout << "one: " << d1 << endl;
    cout << "five: " << d5 << endl;
    cout << "one+five=" << d1+d5 << endl;

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

    cout << endl << "-----------------------------Check if char is Didit" << endl; 
    string wordWithDigit = "1[ab2[xz3g";
    //                      0123456789
    //                      ^   ^   ^  {  0, 4, 8 } - digits
    for(int i=0;i<wordWithDigit.size();i++){
        if (isdigit(wordWithDigit[i])) {
            string ch=string(1, wordWithDigit[i]); // char to string
            int dig = stoi(ch); // string to int
            cout << dig << " - digit char: " << endl;  // 
        }
        if (isalpha(wordWithDigit[i])) {
            cout << wordWithDigit[i] << " - alphabet char: " << endl; //
        }
    }
    cout << endl;
    /*
        1 - digit char: 
        a - alphabet char: 
        b - alphabet char: 
        2 - digit char: 
        x - alphabet char: 
        z - alphabet char: 
        3 - digit char: 
        g - alphabet char:     
    */

    return 0;
}