/*
g++ FenwickTree.cpp -std=c++17;./a.out
*/

#include <bits/stdc++.h>
using namespace std;


class BIT {
    vector<int>bit;
public:
    BIT (int n=0) {
        bit.assign(n+1, 0);
    }
    
    void add(int i, int value) { 
        while (i<bit.size()) {
            bit[i] += value;
            i += i & (-i);
        }
    }
    
    int sum(int i) {
        int sum=0;
        while (i>0) {
            sum += bit[i];
            i -= i & (-i);
        }
        return sum;
    }
    
    int sumRange(int start, int end) {
        return sum(end)-sum(start-1); // don't include start
    }
};

// Num array has array that it supports with the help of Binary Indeded Tree
class NumArray {
    vector<int>nums;
    BIT bit;
public:
    NumArray(vector<int>& nums) {
        this->bit = BIT(nums.size());
        this->nums = nums;
        for (int i = 0; i < nums.size(); ++i)
            bit.add(i+1, nums[i]);
    }
    
    void update(int index, int val) {
        int dif=val-nums[index];
        bit.add(index+1, dif);
        nums[index]=val;
    }
    
    int sumRange(int left, int right) {
        return bit.sumRange(left+1, right+1);
    }
};


int main() {

    /*
    Example: 
        Range Sum Query - Mutable   
            problem: https://leetcode.com/problems/range-sum-query-mutable/
            github: https://github.com/egcode/algorithms-datastructures-patterns/blob/main/Patterns/LEETCODE/DataStructures/Tree/Binary%20Indexed%20Tree/Range%20Sum%20Query%20-%20Mutable.md

        Input
        ["NumArray", "sumRange", "update", "sumRange"]
        [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
        Output
        [null, 9, null, 8]
    */

    cout << endl << "-----------------------------" << endl;
    vector<int> nums;
    nums = {1, 3, 5};
    auto numArray = new NumArray(nums);

    cout << "Sum range1: " << numArray->sumRange(0, 2) << endl; // return 1 + 3 + 5 = 9
    numArray->update(1, 2);
    cout << "Sum range2: " << numArray->sumRange(0, 2) << endl; // return 1 + 2 + 5 = 8

    return 0;
}