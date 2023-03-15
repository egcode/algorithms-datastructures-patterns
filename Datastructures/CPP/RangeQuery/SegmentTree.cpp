/*
g++ SegmentTree.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class SegmentTree {
public:
    SegmentTree(const vector<int>& v) {
        n = v.size();
        tree.resize(4*n);
        build(v, 1, 0, n-1);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

private:
    vector<int> tree;
    int n;

    void build(const vector<int>& v, int node, int left, int right) {
        if (left == right) {
            tree[node] = v[left];
        } else {
            int mid = (left + right) / 2;
            build(v, 2*node, left, mid);
            build(v, 2*node+1, mid+1, right);
            tree[node] = min(tree[2*node], tree[2*node+1]);
        }
    }

    int query(int node, int left, int right, int l, int r) {
        if (r < left || right < l) {
            return INF;
        } else if (l <= left && right <= r) {
            return tree[node];
        } else {
            int mid = (left + right) / 2;
            int left_query = query(2*node, left, mid, l, r);
            int right_query = query(2*node+1, mid+1, right, l, r);
            return min(left_query, right_query);
        }
    }
};

int main() {
    vector<int> v {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    SegmentTree st(v);
    cout << st.query(2, 6) << endl; // Output: 1
    cout << st.query(4, 9) << endl; // Output: 3
    return 0;
}
