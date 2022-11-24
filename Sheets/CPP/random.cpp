/*
g++ random.cpp -std=c++20 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
#include <random>
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

    cout << endl << "-----------------------------Random number in Range" << "\n"; 

    int start=10, end=25;
    cout<<"Random numbers generated between  ["<< start << ", "<< end << "] ";
    for (int i=0;i<10;++i) {
        int randomInt = randomInteger(start, end);
        cout << " " << randomInt;
    }
    cout << "\n";


    cout << endl << "-----------------------------Random numbers between 1 and 10" << "\n";
    srand((unsigned) time(0));
    for (int i=0;i<5;++i) {
        int randomNumber = (rand() % 10)+1;
        cout << " " << randomNumber;
    }
    cout << "\n";

    cout << endl << "-----------------------------Random numbers between 0 and 1" << "\n";
    srand((unsigned) time(NULL));
    for (int i = 0; i < 5; i++) {
        cout << (float) rand() / RAND_MAX << "  ";
    }
    cout << "\n";


    cout << endl << "-----------------------------Generate either 0 or 1" << "\n";
    srand(time(NULL));
    cout << rand() % 2;
    cout << "\n";

    cout << endl << "-----------------------------Generate Random Word" << "\n";
	random_device rd;
	const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string code;
    for (int i = 0; i < 6; i++)
       code.push_back(charset[rd() % charset.size()]);

    cout << "Random Word: " << code << "\n"; // Random Word: XdxPbU

    return 0;
}
