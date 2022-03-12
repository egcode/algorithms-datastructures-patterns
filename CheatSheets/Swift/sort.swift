// Sort String
var some_str = "defbgca"
var str_sorted = String(Array(some_str).sorted())
print("Sorted string: \(str_sorted)")


// Sort Tuple
var t=[(4,5),(1,4),(0,1)]
t=t.sorted(by: { $0.0 < $1.0})
print("Sorted Tuple: \(t)")

