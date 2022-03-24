/*
g++ string.cpp -std=c++11 -o /tmp/a.out;/tmp/a.out
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

    cout << "--------------- Replace one char in string" << endl;        
    // replace character
    string s = "yobana";
    s[0]='r';
    s[3]='H';
    cout << s << endl; // robana
    
    cout << "--------------- Replace Part of the string" << endl;    
    // replace part of string
    // EXAMPLE: str.replace(start_pos, from.length(), to);
    
    // Replaced one letter with string
    string s1 = "Trabana";
    s1.replace(0,1,"ddd");
    cout << s1 << endl; // dddrabana

    // Replaced three letters with one char
    string s2 = "oneTwoThree";
    s2.replace(0,3,"Z");
    cout << s2 << endl; // ZTwoThree


    cout << "--------------- Remove one char from word" << endl;
    string someDigitWord = "123456";
    cout << someDigitWord<<" - original"<<"\n";
    for (int i=0; i<someDigitWord.size(); i++) {
        string wordPrefix = someDigitWord.substr(0, i); 
        string wordSuffix = someDigitWord.substr(i+1, someDigitWord.size());
        cout << wordPrefix << " " << wordSuffix << "\n";
    }
    /*
        --------------- Remove char
         23456
        1 3456
        12 456
        123 56
        1234 6
        12345    
    */


    // Split string to words
    cout << "--------------- Split string to words `Stringstream` (Prefered)" << endl;
    /*
    Stringstream object can be initialized using a string object, it automatically tokenizes strings on space char. Just like “cin” stream stringstream allows you to read a string as a stream of words.

    Some of the Most Common used functions of StringStream.
    clear() — flushes the stream 
    str() —  converts a stream of words into a C++ string object.
    operator << — pushes a string object into the stream.
    operator >> — extracts a word from the stream.
    The code below demonstrates it. 
    */    
    string someString = "How do you do!";
    // Takes only space separated C++ strings.
    stringstream ss(someString);
    string wordBuffer;
    while (ss >> wordBuffer) {
        cout << wordBuffer << endl;
    }
    /*
        How
        do
        you
        do!    
    */
    
    
    cout << "--------------- Split string to words `find() and substr()`" << endl;

    string someString2 = "Hi$%do$%you$%do$%!";
    string del = "$%";

    int start = 0;
    int end = someString2.find(del, start);
    cout << " end: " << end << endl; // 2
    while (end != -1) {
        cout << someString2.substr(start, end - start) << endl;
        start = end + del.size();
        end = someString2.find(del, start);
    }
    cout << someString2.substr(start, end - start);
    cout << endl;

    cout << "--------------- Cut string before symbol" << endl;

    string someStr3 = "JAck;Susan;Blah; ...";
    string one, two;

    stringstream ss2(someStr3);
    
    getline(ss2, one, ';');
    cout << "one: " << one << endl;
    
    getline(ss2, two, ';');
    cout << "two: " << two << endl;

    
    cout << "--------------- Cut string before symbol loop" << endl;
    
    string someStr4 = "JAck;Susan;Blah; ...";
    stringstream ss3(someStr4);
    while(ss3.good()) {
        string substr;
        getline(ss3, substr, ';'); //get first string delimited by semicolon
        cout << " " << substr << endl;
    }
    

    return 0;
}