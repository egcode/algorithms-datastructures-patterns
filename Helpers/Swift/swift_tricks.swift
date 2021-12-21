
// String from array
let array = ["Andrew", "Ben", "John", "Paul", "Peter", "Laura"]
let joined = array.joined(separator: ", ")
print("String from Array: \(joined)")

// Array From String
var str = "super String with awesome TExt"
var arr = str.components(separatedBy: " ")
print("Array from string: \(arr)")

// Sort String
var some_str = "defbgca"
var str_sorted = String(Array(some_str).sorted())
print("Sorted string: \(str_sorted)")


// Sort Tuple
var t=[(4,5),(1,4),(0,1)]
t=t.sorted(by: { $0.0 < $1.0})
print("Sorted Tuple: \(t)")

// Last array element
var ar=[1,2,3,4,5,6]
var last=ar[ar.endIndex-1]
print("End element: \(last)")

// Random Int
let randomInt = Int.random(in: 0..<6)
print("random int: \(randomInt)")
print("random int: \(CGFloat.random(in: 0...1))")

// Split String
let s="leetcode"
let ss="leet"
print(s[ss.startIndex..<ss.endIndex])
print(s[ss.endIndex..<s.endIndex])


// Random dictionary element
var d = ["one":1, "two":2, "three":3, "four":4]
print(d.values.randomElement()!)
print(d.randomElement()!.value)
print(d.keys.randomElement()!)


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

let d1 = 512
print( d1 >> 1) // = 256  - Divide by 2
print( d1 << 1) // = 1024 - Multyply by 2
