### [Sort Items by Groups Respecting Dependencies](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/) <br>


There are n items each belonging to zero or one of `m` groups where `group[i]` is the group that the `i`-th item belongs to and it's equal to `-1` if the `i`-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.

Return a sorted list of the items such that:

- The items that belong to the same group are next to each other in the sorted list.
- There are some relations between these items where `beforeItems[i]` is a list containing all the items that should come before the `i`-th item in the sorted array (to the left of the `i`-th item).

Return any solution if there is more than one solution and return an **empty list** if there is no solution.



#### Example 1:
<img src="../../../../../images/1203_ex1.png">

```
Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
Output: [6,3,4,1,5,2,0,7]

```

#### Example 2:

```
Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
Output: []
Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.

```



# Solutions

### CPP
```
class Solution {
public:
    
    vector<int>topoSort(vector<int>& nodes, unordered_map<int, vector<int>>&graph, unordered_map<int,int>in_degree) {
        vector<int>res;
        deque<int>d;
        for (int& node:nodes){
            if (not in_degree.count(node)) {
                d.push_front(node);
            }
        }
        while (not d.empty()) {
            int node=d.back(); d.pop_back();
            res.push_back(node);
            for (int & neighbor:graph[node]){
                in_degree[neighbor]--;
                if (in_degree[neighbor]==0)
                    d.push_front(neighbor);
            }
        }
        return res;
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        /*
            - Group items
            - Build graph for Each group
            - Topologically sort within each group

            - Build Group Graph
            - Topologically sort groups itself
        */
        vector<int>res;
        unordered_map<int,vector<int>>groupNodes; // node, {groupNeighbors}
        int groupID=m;
        for (int i=0;i<n;++i){
            if (group[i]==-1){
                group[i]=groupID++;
            } 
            groupNodes[group[i]].push_back(i);
        }
        
        // Build graph for Each group
        unordered_map<int, vector<int>>items_graph;
        unordered_map<int,int>items_indegree;
        for (int i=0;i<n;++i){
            for (int j=0;j<beforeItems[i].size();++j){
                int bef = beforeItems[i][j];
                if (group[i]==group[bef]) { // Don't connect if not same group
                    items_graph[bef].push_back(i);
                    items_indegree[i]++;
                }   
            }
        }
        
        
        unordered_set<int>groupsSet;
        
        // Topologically sort within each group
        unordered_map<int, vector<int>>sortedGroupNodes; // node, {groupNeighbors - Topologically sorted}        
        for (auto & pair: groupNodes) {
            int groupID=pair.first;
            groupsSet.insert(groupID);   
            sortedGroupNodes[groupID]=topoSort(groupNodes[groupID], items_graph, items_indegree);
            if (sortedGroupNodes[groupID].size() != groupNodes[groupID].size()) 
                return res;
        }
        
        // Build Group Graph
        unordered_map<int,vector<int>>groupGraph; // groupID, {neigborGroupID}
        unordered_map<int,int>in_degree_groups;
        for (int i=0;i<n;++i){
            int toGroup = group[i];
            for (int j=0;j<beforeItems[i].size();++j) {
                int fromGrp = group[beforeItems[i][j]];
                if (toGroup != fromGrp) {
                    groupGraph[fromGrp].push_back(toGroup);
                    in_degree_groups[toGroup]++;
                }
            }
        }
        
        // Topologically sort groups itself
        vector<int>allGroups;
        for (auto gr:groupsSet) allGroups.push_back(gr);
        auto sorted_groups=topoSort(allGroups, groupGraph, in_degree_groups);
        if (sorted_groups.size() != allGroups.size())
            return res;
        
        // Generate result from sorted groups and sorted nodes within a groups
        for (int & groupID: sorted_groups) {
            for (int & node: sortedGroupNodes[groupID]) {
                res.push_back(node);
            }
        }
        
        return res;
        
        
    }
};
```
