let list = [ 1,2,3,4,5,6,7 ]

print("\nReversed List")
for num in list.reversed() {
    print(num)
}

print("\nReversed Range")
for i in (0..<list.count).reversed() {
    print(list[i])
}

print("\nReversed Stride")
for index in stride(from: list.count-1, through: 0, by: -1) {
    print(list[index])
}
