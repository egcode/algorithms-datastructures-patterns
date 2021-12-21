// Random Int
let randomInt = Int.random(in: 0..<6)
print("random int: \(randomInt)")
print("random int: \(CGFloat.random(in: 0...1))")



// Random dictionary element
var d = ["one":1, "two":2, "three":3, "four":4]
print(d.values.randomElement()!)
print(d.randomElement()!.value)
print(d.keys.randomElement()!)


