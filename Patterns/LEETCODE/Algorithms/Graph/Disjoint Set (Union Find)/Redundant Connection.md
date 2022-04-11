### [Redundant Connection](https://leetcode.com/problems/redundant-connection/) <br>

In this problem, a tree is an **undirected graph** that is connected and has no cycles.

You are given a graph that started as a tree with `n` nodes labeled from `1` to `n`, with one additional edge added. The added edge has two **different** vertices chosen from `1` to `n`, and was not an edge that already existed. The graph is represented as an array `edges` of length `n` where <img src="https://render.githubusercontent.com/render/math?math=edges[i]"> = [<img src="https://render.githubusercontent.com/render/math?math=a_i">, <img src="https://render.githubusercontent.com/render/math?math=b_i">] indicates that there is an edge between nodes <img src="https://render.githubusercontent.com/render/math?math=a_i"> and <img src="https://render.githubusercontent.com/render/math?math=b_i"> in the graph.

*Return an edge that can be removed so that the resulting graph is a tree of `n` nodes*. If there are multiple answers, return the answer that occurs last in the input.



#### Example 1:
<img src="../../../../../images/684_reduntant1-1-graph.jpg">

```
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
```

#### Example 2:
<img src="../../../../../images/684_reduntant1-2-graph.jpg">

```
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
```


# Solutions

### CPP
```
class DisjointSet {
    public:
    vector<int>roots;
    vector<int>ranks;
    
    DisjointSet(int n) {
        for(int i=0;i<=n;i++){
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
    
    bool unioN(int x, int y) {
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
            // Edge is not yet connected to a group
            return true;
        } else {
            // Edge is already connected to a group - Cycle found
            return false;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /*
        Loop through edges, if both nodes of an
        edge are already connected 
        that means it's redundant
        */
        auto ds = new DisjointSet(1001); // 1000 is max,and +1 because its 1..n
        for (int i=0; i<edges.size(); ++i) {
            if (not ds->unioN(edges[i][0],edges[i][1]))
                return edges[i];
        }
        return {};
    }
};
```
