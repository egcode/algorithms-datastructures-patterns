/*
g++ vector_1d.cpp -std=c++11 -o /tmp/a.out;/tmp/a.out

begin() — Returns an iterator to the first element in the vector
end() — Returns an iterator to a location past last element in the vector
size() — Returns the number of elements in the vector.
resize() — Resizes the container.
empty() — Returns whether the container is empty.
front() — Returns a reference to the first element in the vector
back() — Returns a reference to the last element in the vector
pop_back() — It is used to pop or remove elements from a vector from the back.
insert() — It inserts new elements before the element at the specified position
erase() — It is used to remove elements from a container from the specified position or range.
clear() — It is used to remove all the elements of the vector container

push_back() — It push the elements into a vector from the back
emplace_back() - Faster version push the elements into a vector from the back
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    cout << "\n" << "-----------------------------Vector Creation" << "\n"; 

    // V1
    cout<<"\nV1: "; // V1: 0 0 0 0 0
    int n = 5;
    vector<int> vect(n, 0);
    for (int x : vect)
        cout << x << " ";

    // V2
    cout<<"\nV2: ";   // V2: 5 5 5 5 5 5 5 5 5 5 
    vector<int> vect1(10);
    int value = 5;
    fill(vect1.begin(), vect1.end(), value);
    for (int x : vect1)
        cout << x << " ";


    // V3
    vector <int> numbers;
    if (numbers.empty()) { 
        cout << "The vector is empty :(" << "\n"; // The vector is empty :(
    }
    for(int i=0; i<100; i+=10) { 
        numbers.push_back(i);
        numbers.emplace_back(i+1);
    }

    cout << "\n" << "-----------------------------Vector Looping" << "\n"; 
    // Looping: 
    // V1
    vector <int>::iterator it;
    cout<<"\nV1: "; // V1:  0 1 10 11 20 21 30 31 40 41 50 51 60 61 70 71 80 81 90 91
    for (it=numbers.begin(); it!=numbers.end(); it++) {
        cout << " " << *it;
    }
    // V2
    cout<<"\nV2: "; // V2:  0 1 10 11 20 21 30 31 40 41 50 51 60 61 70 71 80 81 90 91
    for(int i=0;i<numbers.size();i++){
        cout << " " << numbers[i];
    }
    // V3
    cout<<"\nV3: "; // V3:  0 1 10 11 20 21 30 31 40 41 50 51 60 61 70 71 80 81 90 91
    for(int num : numbers)
        cout << " " << num;

    cout << "vector front: " << numbers.front() << "\n"; // vector front: 0
    cout << "vector back: " << numbers.back() << "\n"; // vector back: 91

    cout << "\n" << "-----------------------------Modify Vector" << "\n"; 
    /////// Modify Vector

    int position = 5;
    cout<<"\nVector at position "<<position<<" contains "<<numbers.at(position)<<"\n"; // Vector at position 5 contains 21

    numbers.erase(numbers.begin() + position);
    cout<<"Vector at position "<<position<<" contains "<<numbers.at(position)<<"\n"; // Vector at position 5 contains 30

    // deleting a range of elements, first two elements
    // index 2 is not inclusive.
    numbers.erase(numbers.begin(), numbers.begin()+2);
    cout << "The vector contains: "; // The vector contains:   10  11  20  30  31  40  41  50  51  60  61  70  71  80  81  90  91
    for (it=numbers.begin(); it!=numbers.end(); it++) {
        cout << "  " << *it;
    }


    numbers.clear();
    if (numbers.empty()){
        cout << "\nThe vector is now empty again :("; // The vector is now empty again :(
    }
    
    cout << "\n\nVector of pairs vefore modification: "<<"\n";
    vector <pair<int, int>> vec;
    vec={{1, 2}, { 3, 4}};
    for (auto p: vec)
        cout<<"      "<<p.first<<" "<<p.second;
    cout<<"\n"; //       1 2      3 4

    // Modifing values
    for (auto &p: vec)
        p.first *= 100;

    cout << "\nVector of pairs after modification: "<<"\n";
    for (auto p: vec)
        cout<<"      "<<p.first<<" "<<p.second;
    cout<<"\n"; //       100 2      300 4


    cout << "\n" << "-----------------------------Vector Slicing" << "\n"; 

    vector <int> nums;
    nums={1, 2, 3, 4, 5, 6};
    cout << "Original Vector: "; // Original Vector:  1 2 3 4 5 6
    for ( auto num: nums)
        cout << " " << num;
    cout << "\n";

    vector<int> cop1=vector<int>(nums.begin(), nums.begin()+2);
    cout << "1 Copied Vector: "; // 1 Copied Vector:  1 2
    for (auto cop: cop1)
        cout << " " << cop;
    cout << "\n";

    // nums:    1, 2, 3, 4, 5, 6
    // indexes  0  1  2  3  4  5
    // copy           ^     ^    - result {3, 4} - not inclusive at the end. Just like python slicing
    vector<int> cop2=vector<int>(nums.begin()+2, nums.begin()+4);
    cout << "2 Copied Vector: "; // 2 Copied Vector:  3 4
    for (auto cop1: cop2)
        cout << " " << cop1;
    cout << "\n";


    cout << "\n" << "-----------------------------Vector Insert at Index" << "\n"; 
    vector<int>insVec={1, 2, 3, 4};
    insVec.insert(insVec.begin()+1, 444);
    for (auto i : insVec)
        cout << " " << i; //  1 444 2 3 4
    cout << "\n";

    cout << "\n" << "-----------------------------Vector Concatenate" << "\n"; 
    vector <int> conc1, conc2;    
    conc1={1, 2, 3};
    conc2={15, 16, 17};

    // Inserting
    conc1.insert(conc1.end(), conc2.begin(), conc2.end());

    for (auto i : conc1)
        cout << " " << i; // 1 2 3 15 16 17
    cout << "\n";

    cout << "\n" << "----------------------------- set_union" << "\n"; 
    vector<int> s1 {0,1,2,2,4,4,5};
    vector<int> s2 {1,1,3,4,5};
    // make sure output could fit all elements
    vector<int> out;
    out.resize(s1.size() + s2.size());
    auto e = set_union(begin(s1), end(s1), begin(s2), end(s2), begin(out));
    // shrink output to fit
    out.erase(e, end(out));
    for (int x : out) { cout << x << ' '; }  // 0 1 1 2 2 3 4 4 5
    cout << '\n';
    


    return 0;
}
