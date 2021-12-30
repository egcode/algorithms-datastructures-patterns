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

    cout << endl << "-----------------------------Slicing" << endl; 
    string ws = "yobanavagu";
    //           0123456789
    //             ^   ^  2-6 bana - NOT INCLUSIVE at the end
    cout << " word: "<< ws << endl; // word: yobanavagu  
    string wordSlice = string(ws.begin()+2, ws.begin()+6);
    cout << " wordSlice: "<< wordSlice << endl;  // wordSlice: bana


    cout << endl << "-----------------------------Reverse" << endl; 
    string wrd = "zalupa";
    cout << " original word: "<< wrd << endl; // original word: zalupa

    string wordReversed(wrd);
    reverse(wordReversed.begin(), wordReversed.end());
    cout << " word reversed: "<< wordReversed << endl; // word reversed: apulaz

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