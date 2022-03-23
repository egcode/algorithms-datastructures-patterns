// Split String
let s="leetcode"
let ss="leet"
print(s[ss.startIndex..<ss.endIndex])
print(s[ss.endIndex..<s.endIndex])


// String from array
let array = ["Andrew", "Ben", "John", "Paul", "Peter", "Laura"]
let joined = array.joined(separator: ", ")
print("String from Array: \(joined)")

// Array From String
var str = "super String with awesome TExt"
var arr = str.components(separatedBy: " ")
print("Array from string: \(arr)")

