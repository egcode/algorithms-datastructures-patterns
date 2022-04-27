/*
g++ lambdas.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int main(){


    cout << endl << "-----------------------------Variable Capturing" << endl; 
    /*

    [=] (...) {...}   - capture all by value
    [&] (...) {...}   - capture all by reference
    [x, &y] (...) {...}  - captures `x` by value and `y` by reference
    [=, &y] (...) {...}  - captures all except `y` by value

    */

   vector<int> vec1 = {1,2,3,4,5};
   int i = 2;
   transform(begin(vec1), end(vec1), begin(vec1),
                    [&] (int x){  
                        // without this [&] `i` variable would not be visible inside closure, 
                        // if [=] - variable would be visible but immutable
                        ++i;
                        return (x * i);
                    });
    cout << "Transformed Vector Captured by Reference: ";
    for (auto & v:vec1) cout << " " << v; // 3 8 15 24 35
    cout << "\ni: "<< i <<"\n"; // 7


    cout << endl << "-----------------------------Partition Example" << endl; 
    vector<int> vecp = {5,8,9,122,123,124,1011,1012,1013};
    auto part1 = partition(vecp.begin(), vecp.end(),
                            [] (int x) {    return x >= 100 and x <= 200;   });

    cout << "Partitioned Vector: ";
    for (auto & v:vecp) cout << " " << v; // 124 123 122 9 8 5 1011 1012 1013
                                          //             ^ 

    cout << "\npartition end: " << *part1 << "    index after that is other partition\n";





    return 0;
}