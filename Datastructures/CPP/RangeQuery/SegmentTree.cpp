/*
g++ SegmentTree.cpp -std=c++17 -o /tmp/a.out;/tmp/a.out
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Node {
    int min_val, max_val, sum;

    Node() {
        min_val = INT_MAX;
        max_val = INT_MIN;
        sum = 0;
    }

    Node(int val) {
        min_val = max_val = sum = val;
    }
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(nums[start]);
        } else {
            int mid = start + (end - start) / 2;
            build(nums, 2 * node, start, mid);
            build(nums, 2 * node + 1, mid + 1, end);
            tree[node].min_val = min(tree[2 * node].min_val, tree[2 * node + 1].min_val);
            tree[node].max_val = max(tree[2 * node].max_val, tree[2 * node + 1].max_val);
            tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
        }
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return Node();
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        Node left = query(2 * node, start, mid, l, r);
        Node right = query(2 * node + 1, mid + 1, end, l, r);
        Node res;
        res.min_val = min(left.min_val, right.min_val);
        res.max_val = max(left.max_val, right.max_val);
        res.sum = left.sum + right.sum;
        return res;
    }

public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    int query_min(int l, int r) {
        return query(1, 0, n - 1, l, r).min_val;
    }

    int query_max(int l, int r) {
        return query(1, 0, n - 1, l, r).max_val;
    }

    int query_sum(int l, int r) {
        return query(1, 0, n - 1, l, r).sum;
    }
};



int main() {

    cout << endl << "-----------------------------Segment Tree Min Query" << endl;
    //ind:         0  1  2  3  4  5  6  7  8  9  10
    vector<int> v {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    cout << "ind: ";
    for (int i=0;i<v.size();++i)
        cout << " " << i;
    cout << "\n";
    cout << "num: ";
    for (int & e:v) 
        cout << " " << e;
    cout << "\n";

    SegmentTree st(v);

    cout << "Min query: [2, 6] -> ";
    cout << st.query_min(2, 6) << "\n"; // Min query: [2, 6] -> 1
    cout << "Min query: [4, 9] -> ";
    cout << st.query_min(4, 9) << "\n"; // Min query: [4, 9] -> 2
    cout << "\n";

    cout << "Max query: [2, 6] -> ";
    cout << st.query_max(2, 6) << "\n"; // Max query: [2, 6] -> 9
    cout << "Max query: [6, 9] -> ";
    cout << st.query_max(6, 9) << "\n"; // Max query: [6, 9] -> 6
    cout << "\n";

    cout << "Sum query: [2, 6] -> ";
    cout << st.query_sum(2, 6) << "\n"; // Sum query: [2, 6] -> 21
    cout << "Sum query: [4, 9] -> ";
    cout << st.query_sum(4, 9) << "\n"; // Sum query: [4, 9] -> 30
    cout << "\n";

    return 0;
}
