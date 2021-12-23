/*
g++ vector_1d.cpp -std=c++11;./a.out

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

    cout << endl << "Vector Creation-----------------------------" << endl; 

    vector <int> numbers;
    if (numbers.empty()) { 
        cout << "The vector is empty :(" << endl; // The vector is empty :(
    }

    for(int i=0; i<100; i+=10) { 
        numbers.push_back(i);
        numbers.emplace_back(i+1);
    }
    vector <int>::iterator it;
    cout<<"\nAAA"; // AAA 0 1 10 11 20 21 30 31 40 41 50 51 60 61 70 71 80 81 90 91
    for (it=numbers.begin(); it!=numbers.end(); it++) {
        cout << " " << *it;
    }

    cout<<"\nBBB"; // BBB 0 1 10 11 20 21 30 31 40 41 50 51 60 61 70 71 80 81 90 91
    for(int i=0;i<numbers.size();i++){
        cout << " " << numbers[i];
    }

    cout<<"\nCCC"; // CCC 0 1 10 11 20 21 30 31 40 41 50 51 60 61 70 71 80 81 90 91
    for(int num : numbers)
        cout << " " << num;

    cout << "vector front: " << numbers.front() << endl; // vector front: 0
    cout << "vector back: " << numbers.back() << endl; // vector back: 91


    cout << endl << "Modify Vector-----------------------------" << endl; 
    /////// Modify Vector

    int position = 5;
    cout<<"\nVector at position "<<position<<" contains "<<numbers.at(position)<<endl; // Vector at position 5 contains 21

    numbers.erase(numbers.begin() + position);
    cout<<"Vector at position "<<position<<" contains "<<numbers.at(position)<<endl; // Vector at position 5 contains 30

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
    
    cout << "\n\nVector of pairs vefore modification: "<<endl;
    vector <pair<int, int>> vec;
    vec={{1, 2}, { 3, 4}};
    for (auto p: vec)
        cout<<"      "<<p.first<<" "<<p.second;
    cout<<"\n"; //       1 2      3 4

    // Modifing values
    for (auto &p: vec)
        p.first *= 100;

    cout << "\nVector of pairs after modification: "<<endl;
    for (auto p: vec)
        cout<<"      "<<p.first<<" "<<p.second;
    cout<<"\n"; //       100 2      300 4
    cout << endl << "-----------------------------" << endl; 

    return 0;
}
