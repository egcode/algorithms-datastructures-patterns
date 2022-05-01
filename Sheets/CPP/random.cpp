/*
g++ random.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;


int main(){

    cout << endl << "-----------------------------Random Number1" << endl; 

    // -- Seed
    // auto const seed = 123; // constant seed
    auto const seed = std::random_device{}(); // seed based on device

    // -- Random Engine
    std::default_random_engine engine(seed); // Random random engine
    // mt19937 engine {seed};  // Mersenne Twister random engine:

    // -- Distribution
    // generate random ints ∈ [1,20]
    uniform_int_distribution<int> distr1 {1, 20};
    auto const value1 = distr1(engine);
    cout << "random number n range [1, 20]: "<< value1 << "\n";




    return 0;
}
