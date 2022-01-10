class DisjointSet:
    def __init__(self, n):
        self.roots=[i for i in range(n)]
        self.ranks=[0]*n

    def find(self, x):
        if x == self.roots[x]:
            return x
        self.roots[x] = self.find(self.roots[x])
        return self.roots[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.ranks[rootX] > self.ranks[rootY]:
                self.roots[rootY] = rootX
            elif self.ranks[rootX] < self.ranks[rootY]:
                self.roots[rootX] = rootY
            else:
                self.roots[rootY] = rootX
                self.ranks[rootX] += 1    

###### Example: ######
## Number of Connected Components in an Undirected Graph   
'''
problem: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
github: https://github.com/egcode/algorithms-datastructures-patterns/blob/main/Patterns/LEETCODE/Algorithms/Graph/Disjoint%20Set%20(Union%20Find)/Number%20of%20Connected%20Components%20in%20an%20Undirected%20Graph.md
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
'''
n=5
edges = [[0,1],[1,2],[3,4]]

ds=DisjointSet(n)
print(30*"="+"Init:")
print("roots: "+str(ds.roots))

for edge in edges:
    ds.union(edge[0], edge[1])

# get results
res=set()
for i in range(n):
    res.add(ds.find(i))

print("\n"+30*"="+"Result:")
print("roots: "+str(ds.roots))
print("res: "+str(res))
