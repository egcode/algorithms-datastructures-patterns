/*
g++ vector.cpp -std=c++11;./a.out

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

// used c+++ stl iterator
void displayVector(const vector<int> & v){
    for(vector<int>::const_iterator it = v.begin(); it != v.end() ; it++)
        cout<<*it<<" ";
}

// c++ auto feature
void autoVector(const vector<int> & v){
    for(auto it = v.begin(); it != v.end() ; it++)
        cout<<*it<<" ";
}

// shorthand notation
void shorthand(const vector<int> & v){
    for(int x : v)
        cout<<x<<" ";
}


int main(){

    vector <int> numbers;
    if (numbers.empty()) { 
        cout << "The vector is empty :(" << endl;
    }

    for(int i=0; i<100; i+=10) { 
        numbers.push_back(i);
        numbers.emplace_back(i+1);
    }

    cout << "vector front: " << numbers.front() << endl;
    cout << "vector back: " << numbers.back() << endl;

    vector <int>::iterator it;
    cout<<"\nAAA";
    for (it=numbers.begin(); it!=numbers.end(); it++) {
        cout << " " << *it;
    }

    cout<<"\nBBB";
    for(int i=0;i<numbers.size();i++){
        cout << " " << numbers[i];
    }

    cout<<"\nCCC";
    for(int num : numbers)
        cout << " " << num;


    int position = 5;
    cout<<"\nVector at position "<<position<<" contains "<<numbers.at(position)<<endl;

    numbers.erase(numbers.begin() + position);
    cout<<"Vector at position "<<position<<" contains "<<numbers.at(position)<<endl;

    // deleting a range of elements, first two elements
    // index 2 is not inclusive.
    numbers.erase(numbers.begin(), numbers.begin()+2);
    cout << "The vector contains: ";
    for (it=numbers.begin(); it!=numbers.end(); it++) {
        cout << "  " << *it;
    }


    numbers.clear();
    if (numbers.empty()){
        cout << "\nThe vector is now empty again :(";
    }
    

    /////// Modify Vector

    cout << "\n\nVector of pairs vefore modification: "<<endl;
    vector <pair<int, int>> vec;
    vec={{1, 2}, { 3, 4}};
    for (auto p: vec)
        cout<<"      "<<p.first<<" "<<p.second;
    cout<<"\n";

    // Modifing values
    for (auto &p: vec)
        p.first *= 100;

    cout << "\nVector of pairs after modification: "<<endl;
    for (auto p: vec)
        cout<<"      "<<p.first<<" "<<p.second;
    cout<<"\n";


    return 0;
}
