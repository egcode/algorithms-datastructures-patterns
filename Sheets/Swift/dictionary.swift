// Count with dictionary
let fruits = ["apple", "banana", "apple", "orange", "banana", "apple"]
var counts: [String: Int] = [:]

for fruit in fruits {
    counts[fruit] = (counts[fruit] ?? 0) + 1
}

print(counts)
// Output: ["banana": 2, "orange": 1, "apple": 3]
