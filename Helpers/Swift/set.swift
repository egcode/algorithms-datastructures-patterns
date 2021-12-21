// SETS
// Check if sets intersect
let set1: Set = [1, 2, 3, 4]
let set2: Set = [4, 5, 6]
if set1.isDisjoint(with:set2) {
    print("set1 does not intersects with set2")
} else {
    print("set1 intersects with set2")
}

// Find sets intersections or union
let set1: Set = [1, 2, 3, 4]
let set2: Set = [4, 5, 6]
let intersection=set1.intersection(set2)
let union=set1.union(set2)
print("Sets intersection: \(intersection)")
print("Sets union: \(union)")

