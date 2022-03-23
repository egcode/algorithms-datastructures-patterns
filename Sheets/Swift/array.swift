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

