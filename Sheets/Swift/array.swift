// String from array
let array = ["Andrew", "Ben", "John", "Paul", "Peter", "Laura"]
let joined = array.joined(separator: ", ")
print("String from Array: \(joined)")

// Array From String
var str = "super String with awesome TExt"
var arr = str.components(separatedBy: " ")
print("Array from string: \(arr)")


// Last array element
var ar=[1,2,3,4,5,6]
var last=ar[ar.endIndex-1]
print("End element: \(last)")


// Reversed enumerated array
let arr = ["a", "b", "c", "d"]
for (index, value) in arr.enumerated().reversed() {
    print("Index: \(index), Value: \(value)")
}
/*
Index: 3, Value: d
Index: 2, Value: c
Index: 1, Value: b
Index: 0, Value: a
*/


// Loop in array from index 1 to 3
let arr = ["a", "b", "c", "d", "e", "f"]
for (i, val) in arr[1...3].enumerated() {
    let originalIndex = i + 1
    print("Index: \(originalIndex), Value: \(val)")
}
/*
Because enumerated() always starts at 0, even on a slice. 
So we shift the index back to match the original array's indices.

Index: 1, Value: b
Index: 2, Value: c
Index: 3, Value: d
*/
