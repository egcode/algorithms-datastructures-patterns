/*
g++ Knuth–Morris–Pratt.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int findPattern(string text, string pattern) {
    /*
    Knuth–Morris–Pratt Algorithm
     28. Implement strStr()
    */
    if (pattern == "") return 0;
    
    // Setup Longest Prefix Suffix array
    vector<int>lps(pattern.size(), 0);
    int prevLPS = 0;
    int i = 1;
    
    while (i<pattern.size()) {
        if (pattern[i]==pattern[prevLPS]) {
            lps[i] = prevLPS + 1;
            prevLPS++;
            i++;
            
        } else if (prevLPS==0) {
            lps[i] = 0;
            i++;
        } else {
            prevLPS = lps[prevLPS-1];
        }
    }
    
    // Search pattern in the text
    i = 0; // pointer for the text
    int j = 0; // pointer for the pattern
    while (i<text.size()) {
        if (text[i]==pattern[j]) {
            i++;
            j++;
        } else {
            if (j==0) {
                i++;
            } else {
                j=lps[j-1];
            }
        }
        if (j==pattern.size()) 
            return i-pattern.size();
    }
    return -1;
}

int main() {
    cout << endl << "-----------------------------Knuth–Morris–Pratt" << endl; 
    string patt = "abcxxxabcy";
    string text = "----abcxxxabcy---------";
    int index = findPattern(text, patt);
    if (index != -1) {
        cout << "Pattern: "<< patt << " found at: `" << index << "`" <<  " in text: `" << text << "`" << "\n"; // Pattern: abcxxxabcy found at: `4` in text: `----abcxxxabcy---------`
    } else {
        cout << "Pattern: "<< patt << " not found in text: `" << text << "`" <<endl;
    }

    return 0;
}