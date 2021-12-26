/*
g++ vector_2d.cpp -std=c++11;./a.out
*/

#include <bits/stdc++.h>
using namespace std;


int main(){


    int h=3;
    int w=5;

    // 1d Vector
    vector <int> dpOne(w, 23);
    for (int i=0; i<dpOne.size();i++)
        cout << " " << dpOne[i]; 
    /*
     23 23 23 23 23
    */
    cout << endl; 

    // 2d Vector
    vector< vector<int> > dpTwo(h, vector<int>(w, 45));

    for (int i=0; i<dpTwo.size();i++) {
        cout << endl;
        for (int j=0;j<dpTwo[0].size();j++) {
            cout << " " << dpTwo[i][j];
        }
    }
    /*
        45 45 45 45 45
        45 45 45 45 45
        45 45 45 45 45    
    */
    cout << endl;
    return 0;
}
