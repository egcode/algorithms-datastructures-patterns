### [Snapshot Array](https://leetcode.com/problems/snapshot-array/) <br>

Implement a SnapshotArray that supports the following interface:

 - `SnapshotArray(int length)` initializes an array-like data structure with the given length.  **Initially, each element equals 0**.
 - `void set(index, val)` sets the element at the given `index` to be equal to `val`.
 - `int snap()` takes a snapshot of the array and returns the `snap_id`: the total number of times we called `snap()` minus `1`.
 - `int get(index, snap_id)` returns the value at the given `index`, at the time we took the snapshot with the given `snap_id`


#### Example 1:

```
Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation: 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5

```


# Solutions

### Python
```
class SnapshotArray:
    '''
    Each snapshot is stored in another dictionary which holds the snap_cnt as a key and the changes as a value.

    When retrieving a value (get(...) method), 
    it will travel back to previous versions until a value for a requested index is found. 
    If value is not found, return a default value 0
    '''

    def __init__(self, length: int):
        self.dic=collections.defaultdict(collections.defaultdict)
        self.snap_id=0

    def set(self, index: int, val: int) -> None:
        self.dic[self.snap_id][index]=val

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id - 1

    
    def get(self, index: int, snap_id: int) -> int:
        cur=snap_id
        
        # Travel back in history to find closest index
        while cur>0 and index not in self.dic[cur]:
            cur -= 1
            
        if index in self.dic[cur].keys():
            return self.dic[cur][index]
            
        return 0

```
