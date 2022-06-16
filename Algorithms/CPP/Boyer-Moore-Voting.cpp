/*
g++ Boyer-Moore-Voting.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> nums) {
    /*
    Boyer-Moore Voting Algorithm
     Example from 169. Majority Element problem.
    */
    int count = 0;
    int candidate=INT_MIN;
    for (auto num: nums) {
        if (count == 0)
            candidate=num;

        int add=-1;
        if (num==candidate)
            add=1;
        count += add;
        return candidate;
    }
    return 0;
}

int main() {
    cout << endl << "-----------------------------Boyer-Moore-Voting" << endl; 
    vector<int> nums = {2,2,1,1,1,2,2};
    int maj = majorityElement(nums);


    cout << "Majority element in array: ";
    for (auto num: nums)
        cout << " " << num;
    cout << " is: " << maj << endl; // Majority element in array:  2 2 1 1 1 2 2 is: 2
    return 0;
}