/*
g++ random.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int randomInteger(int start, int end) {
    // -- Seed
    // auto const seed = 123; // constant seed
    auto const seed = std::random_device{}(); // seed based on device

    // -- Random Engine
    // std::default_random_engine engine(seed); // Random random engine
    mt19937 engine {seed};  // Mersenne Twister random engine:

    // -- Distribution
    // generate random ints ∈ [start, end]
    uniform_int_distribution<int> distr {start, end};
    int const randomNumber = distr(engine);
    return randomNumber;
}


int main(){

    cout << endl << "-----------------------------Random Number1" << endl; 

    int start=10, end=25;
    cout<<"Random numbers generated between  ["<< start << ", "<< end << "] ";
    for (int i=0;i<10;++i) {
        int randomInt = randomInteger(start, end);
        cout << " " << randomInt;
    }
    cout << "\n";

    return 0;
}
