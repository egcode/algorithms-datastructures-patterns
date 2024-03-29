/*
g++ DisjointSet.cpp -std=c++17;./a.out
*/

#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
    public:
    vector<int>roots;
    vector<int>ranks;
    
    DisjointSet(int n) {
        for(int i=0;i<n;i++){
            roots.emplace_back(i);
            ranks.emplace_back(0);
        }        
    }
    
    int find(int x) {
        if (x==roots[x])
            return x;
        roots[x]=find(roots[x]);
        return roots[x];
    }
    
    void unioN(int x, int y) {
        int rootX=find(x);
        int rootY=find(y);
        if (rootX != rootY) {
            if (ranks[rootX]>ranks[rootY]) {
                roots[rootY]=rootX;
            } else if (ranks[rootX]<ranks[rootY]) {
                roots[rootX]=rootY;
            } else {
                roots[rootY]=rootX;
                ++ranks[rootX];
            }
        }
    }
};

/*
Example with Groups Members count:

class DisjointSet {
  public:
    vector<int>root;
    vector<int>rate;
    int groupCount;
    unordered_map<int,int>sizes;
    DisjointSet (int n) {
        groupCount=n;
        for (int i=0;i<n;++i) {
            root.push_back(i);
            rate.push_back(1);
            sizes[i]=1;
        }
    }
    int find(int x) {
        if (x==root[x])
            return x;
        root[x]=find(root[x]);
        return root[x];
    }
    void unionSet(int x, int y) {
        int rootX=find(x);
        int rootY=find(y);
        if (rootX != rootY) {
            if (rate[rootX]>rate[rootY]){
                root[rootY]=rootX;
                
                sizes[rootX] += sizes[rootY];
                sizes[rootY] = 0;
            } else if (rate[rootX]<rate[rootY]) {
                root[rootX]=rootY;
                
                sizes[rootY] += sizes[rootX];
                sizes[rootX] = 0;
            } else {
                root[rootY]=rootX;
                rate[rootX]++;
                
                sizes[rootX] += sizes[rootY];
                sizes[rootY] = 0;
            }
            groupCount--;
        }
    }
    int getGroupSize(int groupID) {
        return sizes[groupID];
    }
};
*/


int main() {

    /*
    Example: 
        Number of Connected Components in an Undirected Graph   
            problem: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
            github: https://github.com/egcode/algorithms-datastructures-patterns/blob/main/Patterns/LEETCODE/Algorithms/Graph/Disjoint%20Set%20(Union%20Find)/Number%20of%20Connected%20Components%20in%20an%20Undirected%20Graph.md

    Input: n = 5, edges = [[0,1],[1,2],[3,4]]
    Output: 2
    */

    cout << endl << "-----------------------------" << endl; 

    int n=5;
    vector<vector<int>> edges;
    edges = {{0,1}, {1,2}, {3,4}};

    auto ds = new DisjointSet(n);
    // Print
    cout << "Init: ";
    for(auto i: ds->roots)
        cout << " " << i; // 0 1 2 3 4
    cout << endl;

    for (int i=0;i<edges.size();i++) {
        ds->unioN(edges[i][0], edges[i][1]);
    }

    unordered_set<int>res;
    for (int i=0;i<n;i++) {
        res.insert(ds->find(ds->roots[i]));
    }

    // Print
    cout << "Rooted: ";
    for(auto i: ds->roots)
        cout << " " << i; // 0 0 0 3 3
    cout << endl;
    cout << "Set: ";
    for(auto i: res)
        cout << " " << i; // 3 0
    cout << endl;

    return 0;
}